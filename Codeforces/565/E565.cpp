#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Grafo;
vector<bool> Visitados, Color;
void DFS(long long Nodo, bool c){
    Visitados[Nodo] = 1;
    Color[Nodo] = c;
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E]) DFS(E, !c);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        Grafo.assign(n, vector<long long>());
        Visitados.assign(n, 0);
        Color.assign(n, 0);
        for(long long i = 0; i < m; i++){
            long long a, b;
            cin>>a>>b;
            a--;
            b--;
            Grafo[a].push_back(b);
            Grafo[b].push_back(a);
        }
        DFS(0, 0);
        long long _0 = 0, _1 = 0;
        for(long long i = 0; i < n; i++){
            if(Color[i]) _1++;
            else _0++;
        }
        if(_0 <= (n / 2)){
            cout<<_0<<"\n";
            for(long long i = 0; i < n; i++){
                if(!Color[i]) cout<<i + 1<<" ";
            }
        } else {
            cout<<_1<<"\n";
            for(long long i = 0; i < n; i++){
                if(Color[i]) cout<<i + 1<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}