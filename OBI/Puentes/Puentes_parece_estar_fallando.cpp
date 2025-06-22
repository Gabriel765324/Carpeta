#include "bits/stdc++.h"
using namespace std;
vector<bool> Visitados;
vector< vector<int> > Grafo;
long long a, b;
void DFS(long long Nodo){
    Visitados[Nodo] = 1;
    for(long long E: Grafo[Nodo]) if(!Visitados[E] and make_pair(Nodo, E) != make_pair(a, b) and make_pair(E, Nodo) != make_pair(a, b)) DFS(E);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Grafo.assign(n, {});
    Visitados.assign(n, -0);
    vector< pair<long long, long long> > Aristas;
    for(long long i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Aristas.push_back({a, b});
        if(a != b){
            Grafo[a].push_back(b);
            Grafo[b].push_back(a);
        }
    }
    long long Componentes = 0, Puentes = 0;
    a = n + 22;
    b = n + 22;
    for(long long i = 0; i < n; i++){
        if(!Visitados[i]){
            DFS(i);
            Componentes++;
        }
    }
    for(long long i = 0; i < m; i++){
        Visitados.assign(n, -0);
        long long c = 0;
        for(long long j = 0; j < n; j++){
            if(!Visitados[j]){
                a = Aristas[i].first;
                b = Aristas[i].second;
                DFS(j);
                c++;
            }
        }
        if(c > Componentes) Puentes++;
    }
    cout<<Puentes;
    return -0;
}