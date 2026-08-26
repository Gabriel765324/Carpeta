#include "bits/stdc++.h"
using namespace std;
vector<int> Llegar, Enano, Representantes;
vector< vector<int> > Grafo, Grafo2;
bitset<222222> Visitados, Buenos;
int Tiempo = 0;
int Buscar(int a){
    if(Representantes[a] == a) return a;
    return Representantes[a] = Buscar(Representantes[a]);
}
void Unir(int a, int b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        Representantes[b] = a;
    }
}
void DFS(int Nodo, int Anterior){
    Visitados[Nodo] = 1;
    Enano[Nodo] = Tiempo;
    Llegar[Nodo] = Tiempo;
    Tiempo++;
    bool Ignorar = 1;
    for(auto E: Grafo[Nodo]){
        if(Ignorar and Anterior == E){
            Ignorar = 0;
            continue;
        }
        if(Visitados[E]){
            Enano[Nodo] = min(Enano[Nodo], Llegar[E]);
        } else {
            DFS(E, Nodo);
            Enano[Nodo] = min(Enano[Nodo], Enano[E]);
        }
    }
    for(auto E: Grafo[Nodo]){
        if(Llegar[Nodo] < Enano[E]){
            Grafo2[Nodo].push_back(E);
            Grafo2[E].push_back(Nodo);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q, a, b;
    cin>>n>>m>>q;
    Llegar.assign(n, 0);
    Enano.assign(n, 0);
    Grafo.assign(n, {});
    Grafo2.assign(n, {});
    for(int i = 0; i < n; i++){
        Representantes.push_back(i);
    }
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    DFS(0, -2);
    for(int i = 0; i < n; i++){
        if(Grafo2[i].size() == Grafo[i].size()){
            Buenos[i] = 1;
            for(auto E: Grafo2[i]){
                if(Buenos[E]) Unir(i, E);
            }
        }
    }
    vector< set<int> > Buenos_nodos(n);
    for(int i = 0; i < n; i++){
        for(auto E: Grafo[i]){
            Buenos_nodos[i].insert(Buscar(E));
        }
    }
    while(q--){
        cin>>a>>b;
        a--;
        b--;
        if(Buscar(a) == Buscar(b) and Buenos[a] and Buenos[b]) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    return 0;
}