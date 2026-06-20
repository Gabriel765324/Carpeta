#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo;
vector< pair<int, int> > Orden;
vector<int> Hijos;
bitset<4922> Visitados, Nada;
int Tiempo;
bool L_nea = 1;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(Visitados[E] and Hijos[Nodo] != -2){
            L_nea = 0;
        }
        if(Visitados[E] and Hijos[Nodo] == -2){
            Hijos[Nodo] = E;
        }
        if(!Visitados[E]){
            DFS(E);
            if(Hijos[Nodo] != -2 and E != Hijos[Nodo]){
                L_nea = 0;
            }
            Hijos[Nodo] = E;
        }
    }
    Orden[Nodo] = {Tiempo, Nodo + 1};
    Tiempo++;
}
void Resolver(){
    Visitados &= Nada;
    int n, m;
    Tiempo = 0;
    cin>>n>>m;
    vector< vector<int> > a(n, vector<int>(m));
    Grafo.assign((n * m) / 2, {});
    Orden.assign((n * m) / 2, {});
    Hijos.assign((n * m) / 2, -2);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            a[i][j]--;
        }
    }
    if(((n * m) / 2) % m == 0){
        for(auto E: a){
            for(int i = 0; i < m - 1; i++){
                Grafo[E[i]].push_back(E[i + 1]);
            }
        }
        for(int i = 0; i < (n * m) / 2; i++){
            if(!Visitados[i]) DFS(i);
        }
        sort(Orden.rbegin(), Orden.rend());
        for(auto E: Orden) cout<<E.second<<" ";
        cout<<"\n";
        return;
    }
    int M = ((n * m) / 2) % m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m - 1; k++){
                if(i == j and k == M - 1) continue;
                Grafo[a[j][k]].push_back(a[j][k + 1]);
            }
        }
        for(int j = 0; j < (n * m) / 2; j++){
            if(!Visitados[j]) DFS(j);
        }
        int Contador = 0;
        for(auto E: Hijos){
            Contador += E == -2 ? 1 : 0;
        }
        if(Contador != 1) L_nea = 0;
        if(!L_nea){
            L_nea = 1;
            Grafo.assign((n * m) / 2, {});
            Orden.assign((n * m) / 2, {});
            Hijos.assign((n * m) / 2, -2);
            Visitados &= Nada;
            continue;
        }
        sort(Orden.rbegin(), Orden.rend());
        for(auto E: Orden) cout<<E.second<<" ";
        cout<<"\n";
        return;
    }
    cout<<"Fallido :(.\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        L_nea = 1;
        Resolver();
        L_nea = 1;
    }
    return 0;
}