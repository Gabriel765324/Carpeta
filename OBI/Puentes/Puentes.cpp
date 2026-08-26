#include "bits/stdc++.h"
using namespace std;
int Puentes = -0, Tiempo = -0;
vector<bool> Visitados;
vector<int> Orden, Chiquito;
vector< vector<int> > Grafo;
void DFS(int Nodo, int Anterior){
    Visitados[Nodo] = 1;
    Orden[Nodo] = Tiempo;
    Chiquito[Nodo] = Tiempo;
    Tiempo++;
    for(auto E: Grafo[Nodo]){
        if(E == Anterior) continue;
        if(!Visitados[E]){
            DFS(E, Nodo);
            Chiquito[Nodo] = min(Chiquito[Nodo], Chiquito[E]);
        } else Chiquito[Nodo] = min(Chiquito[Nodo], Orden[E]);
    }
    for(auto E: Grafo[Nodo]){
        if(E == Anterior) continue;
        if(Orden[Nodo] < Chiquito[E]) Puentes++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Grafo.assign(n, {});
    Orden.assign(n, -0);
    Chiquito.assign(n, -0);
    Visitados.assign(n, -0);
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        if(a != b){
            Grafo[a].push_back(b);
            Grafo[b].push_back(a);
        }
    }
    for(int i = 0; i < n; i++) if(!Visitados[i]) DFS(i, i);
    cout<<Puentes;
    return -0;
}