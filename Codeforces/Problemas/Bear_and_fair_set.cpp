#include "bits/stdc++.h"
#define el "\n"
#define ll long long
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
struct Arista{
    int v, iID, Capacidad, Flujo;
    Arista(int V, int i, int c){
        v = V;
        iID = i;
        Capacidad = c;
        Flujo = 0;
    }
};
struct Pista{
    int Final, Miembros, ID;
    Pista(){}
    bool operator<(const Pista& a){
        return mp(Final, mp(Miembros, ID)) < mp(a.Final, mp(a.Miembros, a.ID));
    }
};
vi Niveles, Revisar;
vector< vi > Grafo;
vector<Arista> Lista;
bool BFS(int i, int f){
    fill(all(Niveles), 22222222);
    Niveles[i] = 0;
    queue<int> Cola;
    Cola.push(i);
    while(!Cola.empty()){
        int Nodo = Cola.front();
        Cola.pop();
        for(auto E: Grafo[Nodo]){
            if(Lista[E].Flujo >= Lista[E].Capacidad) continue;
            int Siguiente = Lista[E].v;
            if(Niveles[Nodo] + 1 < Niveles[Siguiente]){
                Niveles[Siguiente] = Niveles[Nodo] + 1;
                Cola.push(Siguiente);
            }
        }
    }
    return Niveles[f] < 22222222;
}
int DFS(int Nodo, int& Final, int Flujito){
    if(Nodo == Final) return Flujito;
    for(; Revisar[Nodo] < int(Grafo[Nodo].size()); Revisar[Nodo]++){
        int ID = Grafo[Nodo][Revisar[Nodo]], Siguiente = Lista[ID].v;
        if(Lista[ID].Flujo >= Lista[ID].Capacidad) continue;
        if(Niveles[Nodo] + 1 != Niveles[Siguiente]) continue;
        int Nuevo_flujo = min(Flujito, Lista[ID].Capacidad - Lista[ID].Flujo), Posible = DFS(Siguiente, Final, Nuevo_flujo);
        if(Posible > 0){
            Nuevo_flujo = min(Nuevo_flujo, Posible);
            Lista[ID].Flujo += Nuevo_flujo;
            Lista[Lista[ID].iID].Flujo -= Nuevo_flujo;
            return Nuevo_flujo;
        }
    }
    return -22222222;
}
void A_adir_arista(int u, int v, int& ID, int p){
    cerr<<u<<" "<<v<<" "<<p<<el;
    Lista.pb(Arista(v, ID + 1, p));
    Lista.pb(Arista(u, ID, 0));
    Grafo[u].pb(ID);
    Grafo[v].pb(ID + 1);
    ID += 2;
}
int Crear_nodo(){
    Grafo.pb({});
    Niveles.pb(0);
    Revisar.pb(0);
    return int(Niveles.size()) - 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, b, q, ID = 0;
    cin>>n>>b>>q;
    int Inicio = Crear_nodo();
    int Desag_e = Crear_nodo();
    vi _5_nodos = {Crear_nodo(), Crear_nodo(), Crear_nodo(), Crear_nodo(), Crear_nodo()};
    vector<Pista> Pistas(q);
    forn(i, q){
        cin>>Pistas[i].Final>>Pistas[i].Miembros;
        Pistas[i].ID = Crear_nodo();
    }
    sort(all(Pistas));
    int Falta = n;
    forn(i, q){
        if(i == 0){
            if(Pistas[i].Miembros > Pistas[i].Final){
                cout<<"unfair\n";
                return 0;
            }
            int Actual = Pistas[i].ID;
            A_adir_arista(Inicio, Actual, ID, Pistas[i].Miembros);
            int _0 = Pistas[i].Final / 5, _1 = (Pistas[i].Final + 4) / 5, _2 = (Pistas[i].Final + 3) / 5, _3 = (Pistas[i].Final + 2) / 5, _4 = (Pistas[i].Final + 1) / 5;
            A_adir_arista(Actual, _5_nodos[0], ID, _0);
            A_adir_arista(Actual, _5_nodos[1], ID, _1);
            A_adir_arista(Actual, _5_nodos[2], ID, _2);
            A_adir_arista(Actual, _5_nodos[3], ID, _3);
            A_adir_arista(Actual, _5_nodos[4], ID, _4);
            continue;
        }
        int Actual = Pistas[i].ID;
        if(Pistas[i].Final == Pistas[i - 1].Final){
            if(Pistas[i].Miembros != Pistas[i].Miembros){
                cout<<"unfair\n";
                return 0;
            }
        }
        if(Pistas[i].Miembros > Pistas[i].Final){
            cout<<"unfair\n";
            return 0;
        }
        Pistas[i].Miembros -= Pistas[i - 1].Miembros;
        Pistas[i].Final -= Pistas[i - 1].Final;
        if(Pistas[i].Miembros > Pistas[i].Final){
            cout<<"unfair\n";
            return 0;
        }
        if(Pistas[i].Miembros < 0){
            cout<<"unfair\n";
            return 0;
        }
        if(Pistas[i].Miembros == 0){
            Pistas[i].Miembros += Pistas[i - 1].Miembros;
            Pistas[i].Final += Pistas[i - 1].Final;
            continue;
        }
        A_adir_arista(Inicio, Actual, ID, Pistas[i].Miembros);
        int Favorecido = (Pistas[i - 1].Final + 1) % 5;
        deque<int> Valores = {(Pistas[i].Final + 4) / 5, (Pistas[i].Final + 3) / 5, (Pistas[i].Final + 2) / 5, (Pistas[i].Final + 1) / 5, Pistas[i].Final / 5};
        while(Favorecido--){
            Valores.push_front(Valores.back());
            Valores.pop_back();
        }
        int _0 = Valores[0], _1 = Valores[1], _2 = Valores[2], _3 = Valores[3], _4 = Valores[4];
        A_adir_arista(Pistas[i].ID, _5_nodos[0], ID, _0);
        A_adir_arista(Pistas[i].ID, _5_nodos[1], ID, _1);
        A_adir_arista(Pistas[i].ID, _5_nodos[2], ID, _2);
        A_adir_arista(Pistas[i].ID, _5_nodos[3], ID, _3);
        A_adir_arista(Pistas[i].ID, _5_nodos[4], ID, _4);
        Pistas[i].Miembros += Pistas[i - 1].Miembros;
        Pistas[i].Final += Pistas[i - 1].Final;
    }
    Falta = n - Pistas.back().Miembros;
    if(Falta < 0){
        cout<<"unfair\n";
        return 0;
    }
    if(Falta > b - Pistas.back().Final){
        cout<<"unfair\n";
        return 0;
    }
    if(Falta > 0){
        int i = q, Actual = Crear_nodo();
        A_adir_arista(Inicio, Actual, ID, Falta);
        int Favorecido = (Pistas[i - 1].Final + 1) % 5;
        Falta = b - Pistas.back().Final;
        deque<int> Valores = {(Falta + 4) / 5, (Falta + 3) / 5, (Falta + 2) / 5, (Falta + 1) / 5, Falta / 5};
        while(Favorecido--){
            Valores.push_front(Valores.back());
            Valores.pop_back();
        }
        int _0 = Valores[0], _1 = Valores[1], _2 = Valores[2], _3 = Valores[3], _4 = Valores[4];
        A_adir_arista(Actual, _5_nodos[0], ID, _0);
        A_adir_arista(Actual, _5_nodos[1], ID, _1);
        A_adir_arista(Actual, _5_nodos[2], ID, _2);
        A_adir_arista(Actual, _5_nodos[3], ID, _3);
        A_adir_arista(Actual, _5_nodos[4], ID, _4);
    }
    A_adir_arista(_5_nodos[0], Desag_e, ID, n / 5);
    A_adir_arista(_5_nodos[1], Desag_e, ID, n / 5);
    A_adir_arista(_5_nodos[2], Desag_e, ID, n / 5);
    A_adir_arista(_5_nodos[3], Desag_e, ID, n / 5);
    A_adir_arista(_5_nodos[4], Desag_e, ID, n / 5);
    int Flujo_m_ximo = 0;
    while(BFS(Inicio, Desag_e)){
        int Flujito;
        while(Flujito = DFS(Inicio, Desag_e, 22222222)){
            if(Flujito <= 0) break;
            Flujo_m_ximo += Flujito;
        }
        fill(all(Revisar), 0);
    }
    if(Flujo_m_ximo == n) cout<<"fair\n";
    else cout<<"unfair\n";
    return 0;
}