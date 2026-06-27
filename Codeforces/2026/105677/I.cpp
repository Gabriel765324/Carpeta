#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo;
vector<int> Orden;
int t = 0;
void DFS(int Nodo){
    for(auto E: Grafo[Nodo]){
        if(Orden[E] == -2){
            DFS(E);
        }
    }
    Orden[Nodo] = t;
    t++;
}
int Revisar(int Nodo){
    int r = 1;
    for(auto E: Grafo[Nodo]){
        if(Orden[E] == Orden[Nodo] - 1){
            r += Revisar(E);
            break;
        }
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    Grafo.assign(n, {});
    Orden.assign(n, -2);
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        while(m--){
            int a;
            cin>>a;
            a--;
            Grafo[i].push_back(a);
        }
    }
    for(int i = 0; i < n; i++){
        if(Orden[i] == -2){
            DFS(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(Orden[i] == n - 1){
            int r = Revisar(i);
            if(r == n){
                cout<<"1\n";
            } else {
                cout<<"0\n";
            }
            return 0;
        }
    }
    return 0;
}