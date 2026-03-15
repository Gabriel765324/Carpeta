#include "bits/stdc++.h"
using namespace std;
struct Arista{
    int u, v, ID_opuesto;
    long long Capacidad, Flujo;
};
struct Organizar{
    int ID;
};
vector<Arista> Lista;
vector< vector<int> > Grafo;
vector<int> Punteros, Niveles, Ruta;
int Nodo_inicial;
bool operator<(const Organizar& a, const Organizar& b){
    if(Lista[a.ID].Flujo < Lista[b.ID].Flujo) return 1;
    if(Lista[a.ID].Flujo > Lista[b.ID].Flujo) return 0;
    if(Lista[a.ID].Capacidad < Lista[b.ID].Capacidad) return 1;
    if(Lista[a.ID].Capacidad > Lista[b.ID].Capacidad) return 0;
    return Lista[a.ID].v < Lista[b.ID].v;
}
set<Organizar> Lista_del_inicio;
bool BFS(int Inicio){
    //cerr<<Inicio<<"\n";
    Nodo_inicial = Inicio;
    int n = Inicio + 20, Final = Inicio + 2;
    if(Niveles.empty()){
        Niveles.assign(n, -2);
        Punteros.assign(n, 0);
    } else {
        for(int i = 0; i < n; i++){
            Niveles[i] = -2;
            Punteros[i] = 0;
        }
    }
    queue<int> Cola;
    Cola.push(Inicio);
    Niveles[Inicio] = 0;
    while(!Cola.empty()){
        int Nodo = Cola.front();
        Cola.pop();
        for(auto E: Grafo[Nodo]){
            auto Siguiente = Lista[E];
            if(Siguiente.Flujo >= Siguiente.Capacidad) continue;
            if(Niveles[Siguiente.v] < Niveles[Nodo] + 1 and Niveles[Siguiente.v] != -2) continue;
            Niveles[Siguiente.v] = Niveles[Nodo] + 1;
            Cola.push(Siguiente.v);
        }
    }
    return Niveles[Final] != -2;
}
set<int> Borrados;
long long DFS(int Nodo, int Final, long long Flujo){
    //cerr<<Nodo<<"\n";
    if(Nodo == Final) return Flujo;
    if(Nodo == Nodo_inicial){
        while(!Lista_del_inicio.empty()){
            auto Siguiente = Lista[Lista_del_inicio.begin()->ID];
            //cerr<<Nodo<<" "<<Siguiente.v<<" Posible.\n";
            if(Niveles[Nodo] + 1 != Niveles[Siguiente.v]){
                //cerr<<"Fallan los niveles.\n";
                Borrados.insert(Lista_del_inicio.begin()->ID);
                Lista_del_inicio.erase(Lista_del_inicio.begin());
                continue;
            }
            //cerr<<"Niveles correctos.\n";
            if(Siguiente.Flujo >= Siguiente.Capacidad){
                //cerr<<"Falla la capacidad.\n";
                Borrados.insert(Lista_del_inicio.begin()->ID);
                Lista_del_inicio.erase(Lista_del_inicio.begin());
                continue;
            }
            //cerr<<"Capacidad correcta.\n";
            long long Nuevo = DFS(Siguiente.v, Final, min(Flujo, Siguiente.Capacidad - Siguiente.Flujo));
            if(Nuevo == 0){
                //cerr<<"No llega.\n";
                Borrados.insert(Lista_del_inicio.begin()->ID);
                Lista_del_inicio.erase(Lista_del_inicio.begin());
                continue;
            }
            //cerr<<Nodo<<" "<<Siguiente.v<<" Tomado.\n";
            Flujo = min(Flujo, Nuevo);
            auto Actual = *Lista_del_inicio.begin();
            Ruta.push_back(Actual.ID);
            Lista_del_inicio.erase(Actual);
            return Flujo;
        }
        return 0;
    }
    for(; Punteros[Nodo] < Grafo[Nodo].size(); Punteros[Nodo]++){
        auto Siguiente = Lista[Grafo[Nodo][Punteros[Nodo]]];
        //cerr<<Nodo<<" "<<Siguiente.v<<" Posible.\n";
        if(Niveles[Nodo] + 1 != Niveles[Siguiente.v]) continue;
        //cerr<<"Niveles correctos.\n";
        if(Siguiente.Flujo >= Siguiente.Capacidad) continue;
        //cerr<<"Capacidad correcta.\n";
        long long Nuevo = DFS(Siguiente.v, Final, min(Flujo, Siguiente.Capacidad - Siguiente.Flujo));
        if(Nuevo == 0) continue;
        //cerr<<Nodo<<" "<<Siguiente.v<<" Tomado.\n";
        Flujo = min(Flujo, Nuevo);
        Ruta.push_back(Grafo[Nodo][Punteros[Nodo]]);
        Punteros[Nodo]++;
        return Flujo;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    long long r, t;
    cin>>n>>m>>r>>t>>k;
    //cerr<<t / r<<"\n\n";
    Grafo.assign(n + m + 22, {});
    int ID = 0;
    for(int i = 0; i < k; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b = b - 1 + n;
        Grafo[a].push_back(ID);
        Grafo[b].push_back(ID + 1);
        Lista.push_back({a, b, ID + 1, 1, 0});
        Lista.push_back({b, a, ID, 0, 0});
        ID += 2;
    }
    vector<int> Recuperar;
    for(int i = 0; i < n; i++){
        Lista_del_inicio.insert({ID});
        Recuperar.push_back(ID);
        Grafo[n + m + 2].push_back(ID);
        Grafo[i].push_back(ID + 1);
        Lista.push_back({n + m + 2, i, ID + 1, t / r, 0});
        Lista.push_back({i, n + m + 2, ID, 0, 0});
        ID += 2;
    }
    for(int i = n; i < n + m; i++){
        Grafo[i].push_back(ID);
        Grafo[n + m + 4].push_back(ID + 1);
        Lista.push_back({i, n + m + 4, ID + 1, 1, 0});
        Lista.push_back({n + m + 4, i, ID, 0, 0});
        ID += 2;
    }
    long long Flujo_m_ximo = 0;
    while(BFS(n + m + 2)){
        /*cerr<<"Niveles.\n";
        for(int i = 0; i < n + m + 22; i++) cerr<<Niveles[i]<<" ";
        cerr<<"\nFin.\n";*/
        long long Flujo_extra;
        while(Flujo_extra = DFS(n + m + 2, n + m + 4, LLONG_MAX)){
            //cerr<<"Fin.\n"<<Flujo_extra<<"\n";
            if(Flujo_extra == 0) break;
            Flujo_m_ximo += Flujo_extra;
            for(auto E: Ruta){
                Lista[E].Flujo += Flujo_extra;
                Lista[Lista[E].ID_opuesto].Flujo -= Flujo_extra;
            }
            Lista_del_inicio.clear();
            for(auto E: Recuperar){
                if(Borrados.count(E) == 0){
                    Lista_del_inicio.insert({E});
                }
            }
            /*for(auto E: Lista_del_inicio) cerr<<Lista[E.ID].u<<" "<<Lista[E.ID].v<<" "<<Lista[E.ID].Flujo<<" "<<Lista[E.ID].Capacidad<<"\n";
            cerr<<"\n";*/
            Ruta.clear();
        }
        Borrados.clear();
        //sort(Grafo[n + m + 2].begin(), Grafo[n + m + 2].end(), o);
    }
    cout<<Flujo_m_ximo<<" ";
    long long Penalizaci_n = 0;
    for(auto E: Grafo[n + m + 2]){
        Penalizaci_n += (Lista[E].Flujo * Lista[E].Flujo + Lista[E].Flujo) / 2;
    }
    cout<<Penalizaci_n * r<<"\n";
    for(int i = 0; i < n; i++){
        long long Contador = 0;
        for(auto E: Grafo[i]){
            auto Siguiente = Lista[E];
            if(Siguiente.Flujo != 1) continue;
            cout<<i + 1<<" "<<Siguiente.v - n + 1<<" "<<Contador * r<<"\n";
            Contador++;
        }
    }
    return 0;
}