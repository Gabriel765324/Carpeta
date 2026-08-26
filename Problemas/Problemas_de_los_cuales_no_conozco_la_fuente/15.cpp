#include "bits/stdc++.h"
using namespace std;
vector<int> Llegar, Enano;
bool Puente = 0;
bitset<222222> Visitados;
int Tiempo = 0, Contador = 0;
vector< pair<int, int> > Arista;
vector< vector<int> > Grafo;
void DFS(int Nodo, int Anterior){
    //cerr<<Nodo<<"\n";
    Llegar[Nodo] = Tiempo;
    Enano[Nodo] = Tiempo;
    Contador++;
    Tiempo++;
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(E == Anterior) continue;
        if(Visitados[E]){
            if(Llegar[E] <= Enano[Nodo]) Arista.push_back({Nodo + 1, E + 1});
            Enano[Nodo] = min(Enano[Nodo], Llegar[E]);
        } else {
            DFS(E, Nodo);
            if(Enano[E] <= Enano[Nodo]) Arista.push_back({Nodo + 1, E + 1});
            Enano[Nodo] = min(Enano[Nodo], Enano[E]);
        }
    }
    for(auto E: Grafo[Nodo]){
        if(Enano[Nodo] > Llegar[E]){
            /*cerr<<Nodo<<" "<<E<<"\n";
            cerr<<Enano[Nodo]<<" "<<Llegar[E]<<"\n";
            cerr<<"\n";*/
            Puente = 1;
            break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Grafo.assign(n, vector<int>());
    Llegar.assign(n, 0);
    Enano.assign(n, 0);
    int cm = m;
    set< pair<int, int> > Aristas;
    while(cm--){
        int a, b;
        cin>>a>>b;
        Aristas.insert({min(a, b), max(a, b)});
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    DFS(0, -2);
    /*for(auto E: Llegar) cerr<<E<<" ";
    cerr<<"\n";
    for(auto E: Enano) cerr<<E<<" ";
    cerr<<"\n";*/
    if(Puente or Contador < n) cout<<"IMPOSSIBLE";
    else {
        for(auto E: Arista){
            cout<<E.first<<" "<<E.second<<"\n";
            Aristas.erase({min(E.first, E.second), max(E.first, E.second)});
        }
        for(auto E: Aristas){
            cout<<E.first<<" "<<E.second<<"\n";
        }
    }
    return 0;
}