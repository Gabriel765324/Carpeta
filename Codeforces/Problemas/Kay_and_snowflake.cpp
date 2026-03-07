#include "bits/stdc++.h"
using namespace std;
struct Inicios{
    int _ndice, Inicio, Final;
    bool Ahora;
};
struct Finales{
    int _ndice, Final;
};
struct En_la_fila{
    int Nodo;
};
bool operator<(const Inicios& a, const Inicios& b){
    if(a.Inicio < b.Inicio) return 1;
    if(a.Inicio > b.Inicio) return 0;
    if(a.Ahora and !b.Ahora) return 1;
    if(!a.Ahora and b.Ahora) return 0;
    return a._ndice < b._ndice;
}
bool operator<(const Finales& a, const Finales& b){
    if(a.Final < b.Final) return 1;
    if(a.Final > b.Final) return 0;
    return a._ndice < b._ndice;
}
vector< vector<int> > Grafo, Mesa;
vector<int> Tama_os, Respuestas, Capa, Mayor_componente;
set<Inicios> Por_a_dir;
set<Finales> Por_borrar;
bool operator<(const En_la_fila& a, const En_la_fila& b){
    if(Capa[a.Nodo] > Capa[b.Nodo]) return 1;
    if(Capa[a.Nodo] < Capa[b.Nodo]) return 0;
    return a.Nodo < b.Nodo;
}
set<En_la_fila> Cola;
int DFS(int Nodo, int Anterior){
    if(Nodo != 0){
        Capa[Nodo] = Capa[Anterior] + 1;
        Mesa[Nodo].push_back(Anterior);
        int Actual = Anterior;
        for(int i = 1; i < Mesa[Actual].size(); i++){
            Mesa[Nodo].push_back(Mesa[Actual][i]);
            Actual = Mesa[Actual][i];
        }
    }
    int Tama_o = 1;
    for(auto E: Grafo[Nodo]){
        if(E == Anterior) continue;
        int Extrita = DFS(E, Nodo);
        Tama_o += Extrita;
        Mayor_componente[Nodo] = max(Mayor_componente[Nodo], Extrita);
    }
    return Tama_os[Nodo] = Tama_o;
}
bool V_lido(int a, int b){
    return max(Tama_os[a] - Tama_os[b], Mayor_componente[b]) <= Tama_os[a] / 2;
}
void Calcular(int Nodo, int Anterior){
    if(Nodo != 0 and Grafo[Nodo].size() == 1){
        En_la_fila A_adir;
        A_adir.Nodo = Nodo;
        Cola.insert(A_adir);
    }
    for(auto E: Grafo[Nodo]){
        if(E == Anterior) continue;
        Calcular(E, Nodo);
    }
    Grafo[Nodo].clear();
    Inicios Nuevo;
    if(Nodo == 0 and V_lido(0, 0)){
        Nuevo.Inicio = 0;
        Nuevo.Final = 0;
        Nuevo._ndice = 0;
        Nuevo.Ahora = 1;
        Por_a_dir.insert(Nuevo);
    }
    if(Nodo == 0) return;
    int Inicio = Nodo, Final = -2, Nodo_actual = Nodo;
    while(Nodo_actual != 0){
        int i = 0, d = Mesa[Nodo_actual].size() - 1, m = 0;
        bool Seguir = 1;
        while(1){
            int p = (i + d) / 2;
            if(Tama_os[Mesa[Nodo_actual][p]] < Mayor_componente[Nodo] * 2){
                i = p + 1;
                m = p;
            } else {
                d = p - 1;
                Seguir = 0;
            }
            if(i >= d + 1) break;
        }
        Inicio = Mesa[Nodo_actual][m];
        if(Seguir) Nodo_actual = Mesa[Nodo_actual].back();
        else {
            Nodo_actual = Mesa[Nodo_actual][m];
            break;
        }
    }
    Final = Inicio;
    Nodo_actual = Inicio;
    while(Nodo_actual != 0){
        int i = 0, d = Mesa[Nodo_actual].size() - 1, m = 0;
        bool Seguir = 1;
        while(1){
            int p = (i + d) / 2;
            if(V_lido(Mesa[Nodo_actual][p], Nodo)){
                i = p + 1;
                m = p;
            } else {
                d = p - 1;
                Seguir = 0;
            }
            if(i >= d + 1) break;
        }
        Final = Mesa[Nodo_actual][m];
        if(Seguir) Nodo_actual = Mesa[Nodo_actual].back();
        else {
            Nodo_actual = Mesa[Nodo_actual][m];
            break;
        }
    }
    Nuevo.Ahora = V_lido(Nodo, Nodo);
    Nuevo._ndice = Nodo;
    Nuevo.Inicio = Inicio;
    Nuevo.Final = Final;
    //cerr<<Nuevo._ndice<<" "<<Nuevo.Inicio<<" "<<Nuevo.Final<<" "<<Nuevo.Ahora<<"\n";
    Por_a_dir.insert(Nuevo);
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Grafo.assign(n, {});
    Mesa.assign(n, {});
    Tama_os.assign(n, -2);
    Capa.assign(n, 0);
    Mayor_componente.assign(n, 0);
    for(int i = 0; i < n - 1; i++){
        int a;
        cin>>a;
        Grafo[a - 1].push_back(i + 1);
        Grafo[i + 1].push_back(a - 1);
    }
    for(int i = 0; i < n; i++) Mesa[i].push_back(i);
    int Nada = DFS(0, -2);
    /*for(int i = 0; i < n; i++){
        cerr<<i<<"\n";
        for(auto E: Mesa[i]) cerr<<E<<" ";
        cerr<<"\n";
    }*/
    Calcular(0, -2);
    for(int i = 0; i < n; i++) while(Mesa[i].size() > 2) Mesa[i].pop_back();
    Grafo.clear();
    Tama_os.clear();
    Mayor_componente.clear();
    Respuestas.assign(n, -2);
    while(!Cola.empty()){
        int Nodo = Cola.begin()->Nodo;
        Cola.erase(Cola.begin());
        Inicios Buscar;
        Buscar.Ahora = 1;
        Buscar.Inicio = Nodo;
        Buscar.Final = -2;
        Buscar._ndice = -2;
        for(auto E = Por_a_dir.lower_bound(Buscar); E != Por_a_dir.end(); E = Por_a_dir.lower_bound(Buscar)){
            if(E->Ahora and E->_ndice == Nodo){
                Finales Respuesta_nueva;
                Respuesta_nueva.Final = E->Final;
                Respuesta_nueva._ndice = E->_ndice;
                //cerr<<Nodo<<" "<<Respuesta_nueva._ndice<<" "<<Respuesta_nueva.Final<<" Añadir.\n";
                Por_borrar.insert(Respuesta_nueva);
                Por_a_dir.erase(E);
            } else break;
        }
        Buscar.Ahora = 0;
        Respuestas[Nodo] = Por_borrar.begin()->_ndice + 1;
        for(auto E = Por_a_dir.lower_bound(Buscar); E != Por_a_dir.end(); E = Por_a_dir.lower_bound(Buscar)){
            if(E->Inicio == Nodo){
                Finales Respuesta_nueva;
                Respuesta_nueva.Final = E->Final;
                Respuesta_nueva._ndice = E->_ndice;
                //cerr<<Nodo<<" "<<Respuesta_nueva._ndice<<" "<<Respuesta_nueva.Final<<" Añadir 2.\n";
                Por_borrar.insert(Respuesta_nueva);
                Por_a_dir.erase(E);
            } else break;
        }
        Finales Eliminable;
        Eliminable.Final = Nodo;
        Eliminable._ndice = -2;
        for(auto E = Por_borrar.lower_bound(Eliminable); E != Por_borrar.end(); E = Por_borrar.lower_bound(Eliminable)){
            if(E->Final == Nodo){
                //cerr<<Nodo<<" "<<E->_ndice<<" Borrar.\n";
                Por_borrar.erase(E);
            } else break;
        }
        if(Nodo != 0){
            En_la_fila Nodo_nuevo_para_la_fila;
            Nodo_nuevo_para_la_fila.Nodo = Mesa[Nodo][1];
            Cola.insert(Nodo_nuevo_para_la_fila);
        }
    }
    while(m--){
        int a;
        cin>>a;
        cout<<Respuestas[a - 1]<<"\n";
    }
    return 0;
}