#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo;
vector< pair<int, int> > Tomados;
bitset<2222> Visitados, Nada;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(Visitados[E]) continue;
        DFS(E);
        Tomados.push_back({Nodo + 1, E + 1});
    }
}
void Resolver(){
    int n;
    cin>>n;
    Grafo.assign(n, {});
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1' or s[j] == '?'){
                Grafo[i].push_back(j);
            }
        }
    }
    DFS(0);
    if(Visitados.count() == n){
        cout<<"Yes\n";
        for(auto E: Tomados) cout<<E.first<<" "<<E.second<<"\n";
    } else cout<<"No\n";
    cout<<"\n";
    Visitados &= Nada;
    Tomados.clear();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}