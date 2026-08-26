#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > PD, Grafo;
int DFS(int Nodo, int Usado, int Anterior){
    if(PD[Nodo][Usado] != -2) return PD[Nodo][Usado];
    int r = 0;
    vector<int> Posibles, Anteriores;
    for(auto E: Grafo[Nodo]){
        if(E == Anterior) continue;
        r += DFS(E, 1, Nodo);
        if(Usado){
            Posibles.push_back(DFS(E, 0, Nodo) + 1);
            Anteriores.push_back(DFS(E, 1, Nodo));
        }
    }
    //cerr<<Nodo + 1<<" "<<Usado<<" "<<r<<"\n";
    if(Usado){
        int cr = r;
        for(int i = 0; i < int(Posibles.size()); i++){
            //cerr<<r<<" "<<Anteriores[i]<<" "<<Posibles[i]<<" "<<r - Anteriores[i] + Posibles[i]<<"\n";
            r = max(r, cr - Anteriores[i] + Posibles[i]);
        }
    }
    //cerr<<r<<"\n";
    return PD[Nodo][Usado] = r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n == 1){
        cout<<0;
        return 0;
    }
    PD.assign(n, {-2, -2});
    Grafo.assign(n, {});
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    cout<<DFS(0, 1, -2);
    return 0;
}