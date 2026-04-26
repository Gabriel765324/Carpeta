#include "bits/stdc++.h"
using namespace std;
vector<int> Tipo, Respuesta, Tenemos;
vector< vector<int> > Grafo;
bitset<1222222> Visitados;
void DFS(int Nodo, int& Tengo){
    Visitados[Nodo] = 1;
    Tenemos[Tipo[Nodo]]++;
    if(Tenemos[Tipo[Nodo]] == 1) Tengo++;
    Respuesta[Nodo] = Tengo;
    for(auto E: Grafo[Nodo]){
        if(Visitados[E]) continue;
        DFS(E, Tengo);
    }
    Tenemos[Tipo[Nodo]]--;
    if(Tenemos[Tipo[Nodo]] == 0) Tengo--;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Inicio = 0, Tengo = 0;
    cin>>n;
    if(n == 1){
        cout<<"1\n";
        return 0;
    }
    Respuesta.assign(n, 0);
    Tipo.assign(n, 0);
    Grafo.assign(n, {});
    Tenemos.assign(n + 22, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        a--;
        if(a == -1) Inicio = i;
        else {
            Grafo[i].push_back(a);
            Grafo[a].push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        cin>>Tipo[i];
    }
    DFS(Inicio, Tengo);
    for(auto E: Respuesta) cout<<E<<" ";
    cout<<"\n";
    return 0;
}