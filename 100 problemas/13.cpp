#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo;
vector<bool> Usar;
bool Bien = 1;
int Fuimos = 0;
void DFS(int Nodo){
    Usar[Nodo] = 0;
    Fuimos++;
    if(Grafo[Nodo].size() != 2) Bien = 0;
    for(auto E: Grafo[Nodo]){
        if(Usar[E]) DFS(E);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    if(n != m){
        cout<<"No";
        return 0;
    }
    Grafo.assign(n, {});
    Usar.assign(n, 1);
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    DFS(0);
    cout<<((Bien and Fuimos == n) ? "Yes" : "No");
    return 0;
}