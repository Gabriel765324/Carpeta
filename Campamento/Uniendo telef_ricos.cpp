#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Grafo;
vector<bool> Visitados;
void DFS(long long Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]) if(!Visitados[E]) DFS(E);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n>>m;
    Grafo.assign(n, {});
    Visitados.assign(n, 0);
    while(m--){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    long long r = -1;
    for(long long i = 0; i < n; i++){
        if(!Visitados[i]){
            DFS(i);
            r++;
        }
    }
    cout<<r;
    return 0;
}