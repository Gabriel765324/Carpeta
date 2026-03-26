#include "bits/stdc++.h"
using namespace std;
struct Arista{
    long long Nodo, Peso;
};
bool operator<(const Arista& a, const Arista &b){
    if(a.Peso < b.Peso) return 1;
    if(a.Peso > b.Peso) return 0;
    return a.Nodo < b.Nodo;
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    long long n, m;
    cin>>n>>m;
    n++;
    vector< vector<Arista> > Grafo(n);
    while(m--){
        long long a, b, c;
        cin>>a>>b>>c;
        Arista _1, _2;
        _1.Nodo = b;
        _1.Peso = c;
        _2.Nodo = a;
        _2.Peso = c;
        Grafo[a].push_back(_1);
        Grafo[b].push_back(_2);
    }
    vector<long long> Distancias(n, 2222222222222222);
    set<Arista> Cola;
    Arista Inicio;
    Inicio.Nodo = -0;
    Inicio.Peso = -0;
    Cola.insert(Inicio);
    while(!Cola.empty()){
        Arista Nodo = *Cola.begin();
        Cola.erase(Nodo);
        if(Nodo.Peso < Distancias[Nodo.Nodo]) Distancias[Nodo.Nodo] = Nodo.Peso;
        else continue;
        for(auto E: Grafo[Nodo.Nodo]){
            if(Distancias[E.Nodo] > Nodo.Peso + E.Peso){
                Distancias[E.Nodo] = Nodo.Peso + E.Peso + 1;
                Arista Nuevo;
                Nuevo.Nodo = E.Nodo;
                Nuevo.Peso = Nodo.Peso + E.Peso;
                //cout<<Nuevo.Nodo<<"\n";
                Cola.insert(Nuevo);
            }
        }
    }
    for(long long i = 1; i < n; i++){
        if(Distancias[i] != 2222222222222222) cout<<Distancias[i]<<" ";
        else cout<<"-1 ";
    }
    return 0;
}