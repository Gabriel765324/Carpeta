#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define mp make_pair
#define el "\n"
using namespace std;
vector< vi > Grafo;
map< ii , ii > Mapa;
set< ii > Eliminados;
vi Llegada, Chiquito;
int Tiempo = 0;
bitset<444444> Visitados, Nada;
void DFS(int Nodo, int Anterior){
    //cerr<<Nodo<<" ";
    Llegada[Nodo] = Tiempo;
    Chiquito[Nodo] = Tiempo;
    Visitados[Nodo] = 1;
    Tiempo++;
    for(auto E: Grafo[Nodo]){
        if(E == Anterior) continue;
        if(Visitados[E]) Chiquito[Nodo] = min(Chiquito[Nodo], Llegada[E]);
        else {
            DFS(E, Nodo);
            Chiquito[Nodo] = min(Chiquito[Nodo], Chiquito[E]);
        }
    }
    for(auto E: Grafo[Nodo]){
        if(Chiquito[Nodo] > Llegada[E]){
            //cerr<<Nodo + 1<<" "<<E + 1<<" Puente.\n";
            Eliminados.insert({Nodo, E});
            Eliminados.insert({E, Nodo});
        }
    }
}
int Contar(int Nodo){
    //cerr<<Nodo<<" ";
    Visitados[Nodo] = 1;
    int c = 1;
    for(auto E: Grafo[Nodo]){
        if(Eliminados.count({E, Nodo}) == 1) continue;
        if(Mapa.count({E, Nodo}) == 0){
            Mapa[{E, Nodo}] = {Nodo, E};
            Mapa[{Nodo, E}] = {Nodo, E};
        }
        if(Visitados[E]) continue;
        c += Contar(E);
    }
    return c;
}
void Orientar(int Nodo){
    //cerr<<Nodo<<" ";
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(Visitados[E]) continue;
        Orientar(E);
        if(Eliminados.count({E, Nodo}) == 1){
            Mapa[{E, Nodo}] = {E, Nodo};
            Mapa[{Nodo, E}] = {E, Nodo};
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Llegada.assign(n, 0);
    Chiquito.assign(n, 0);
    Grafo.assign(n, {});
    vector< ii > a(m);
    forn(i, m){
        cin>>a[i].F>>a[i].S;
        a[i].F--;
        a[i].S--;
        Grafo[a[i].F].push_back(a[i].S);
        Grafo[a[i].S].push_back(a[i].F);
    }
    DFS(0, -2);
    //cerr<<el;
    int Mayor = 0, Componente = -2;
    Visitados &= Nada;
    forn(i, n){
        if(!Visitados[i]){
            int Posible = Contar(i);
            if(Posible > Mayor){
                Mayor = Posible;
                Componente = i;
            }
        }
    }
    //cerr<<el;
    Visitados &= Nada;
    Orientar(Componente);
    //cerr<<el;
    cout<<Mayor<<el;
    for(auto E: a){
        cout<<Mapa[E].F + 1<<" "<<Mapa[E].S + 1<<el;
    }
    return 0;
}