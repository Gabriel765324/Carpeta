#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo;
vector<int> PD;
int Resolver(int Nodo){
    if(PD[Nodo] != -2) return PD[Nodo];
    for(auto E: Grafo[Nodo]) PD[Nodo] = max(PD[Nodo], Resolver(E) + 1);
    if(PD[Nodo] == -2) PD[Nodo] = 1;
    return PD[Nodo];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Grafo.assign(n, {});
    PD.assign(n, -2);
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
    }
    int Mejor = 1;
    for(int i = 0; i < n; i++){
        if(PD[i] == -2){
            Mejor = max(Mejor, Resolver(i));
        }
    }
    cout<<Mejor - 1;
    return 0;
}