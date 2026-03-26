#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector< vector<long long> > Matriz(n, vector<long long>(n));
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++) cin>>Matriz[i][j];
    }
    set< pair<long long, long long> > Tenemos;
    long long Menor = 2, Mayor = 2 * n, Cantidad = 1;
    while(Menor <= Mayor){
        Tenemos.insert({Cantidad, Menor});
        Tenemos.insert({Cantidad, Mayor});
        Menor++;
        Mayor--;
        Cantidad++;
    }
    set<long long> Pendientes;
    map<long long, long long> Cambiar_valores, Cantidad_de_valores;
    for(long long i = 2; i <= 2 * n; i++){
        Pendientes.insert(i);
    }
    vector<long long> Orden;
    set<long long> No_repetir;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            //swap(i, j);
            Cantidad_de_valores[Matriz[i][j]]++;
            if(No_repetir.find(Matriz[i][j]) == No_repetir.end()){
                Orden.push_back(Matriz[i][j]);
                No_repetir.insert(Matriz[i][j]);
            }
            //swap(i, j);
        }
    }
    for(auto E: Orden){
        cerr<<E<<" "<<Cantidad_de_valores[E]<<"\n";
        auto e = Tenemos.lower_bound({Cantidad_de_valores[E], -2});
        Cambiar_valores[E] = (*e).second;
        Tenemos.erase(e);
    }
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            cout<<Cambiar_valores[Matriz[i][j]];
            if(j < n - 1) cout<<" ";
        }
        if(i < n - 1) cout<<"\n";
    }
    return 0;
}