#include "bits/stdc++.h"
using namespace std;
int n;
vector< vector<int> > Grafo;
bitset<2222> Cola, Visitados;
bool Fallo = 0;
void DFS(int Nodo, bool v){
    Visitados[Nodo] = 1;
    Cola[Nodo] = v;
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E]){
            DFS(E, !v);
        }
        if(Cola[Nodo] == Cola[E]) Fallo = 1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector< pair<int, int> > a(n);
    for(int i = 0; i < n * 2; i++){
        int v;
        cin>>v;
        if(v > 0) a[v - 1].first = i;
        else a[abs(v) - 1].second = i;
    }
    Grafo.assign(n, {});
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i].first < a[j].first and a[i].second < a[j].second and a[i].second > a[j].first){
                Grafo[i].push_back(j);
                Grafo[j].push_back(i);
            } else {
                swap(i, j);
                if(a[i].first < a[j].first and a[i].second < a[j].second and a[i].second > a[j].first){
                    Grafo[i].push_back(j);
                    Grafo[j].push_back(i);
                }
                swap(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(!Visitados[i]){
            DFS(i, 0);
        }
    }
    if(Fallo){
        cout<<"*";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(Cola[i]) cout<<"S";
        else cout<<"G";
    }
    return 0;
}