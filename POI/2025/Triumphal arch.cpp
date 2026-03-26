#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Grafo;
vector<long long> Distancia, Mejores, Precios, Fila;
bool Probar(long long Salario){
    deque<long long> Cola;
    long long n = Grafo.size();
    long long Precio = -0;
    for(long long i = 0; i < n; i++) Precio = max(Precio, Distancia[i]);
    long long i = 0;
    Mejores.assign(n, 2222222222222222);
    for(; Precio > -1; Precio--){
        for(; i < n and Distancia[Fila[i]] == Precio; i++){
            Cola.push_back(Fila[i]);
        }
        for(long long j = 0; j < Cola.size(); j++){
            long long Nodo = Cola[j];
            if(Grafo[Nodo].size() == 1 and Nodo != 0) Mejores[Nodo] = 0;
            else {
                vector<long long> Tomo;
                for(auto E: Grafo[Nodo]){
                    if(Mejores[E] != 2222222222222222){
                        Tomo.push_back(Mejores[E]);
                    }
                }
                sort(Tomo.begin(), Tomo.end());
                long long Tengo = Precios[Nodo];
                for(long long k = 0; k < Tomo.size(); k++){
                    if(Tomo[k] < 0) Tengo += Tomo[k];
                }
                Mejores[Nodo] = min(0LL, Tengo);
            }
        }
        Cola.clear();
    }
    /*cout<<Salario<<"\n";
    for(auto E: Mejores) cout<<E<<" ";
    cout<<"\n";
    for(auto E: Precios) cout<<E<<" ";
    cout<<"\n";*/
    return Mejores[0] >= 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    if(n == 1){
        cout<<0;
        return 0;
    }
    if(n == 2){
        cout<<1;
        return 0;
    }
    Grafo.assign(n, {});
    for(long long i = 0; i < n - 1; i++){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    deque<long long> Cola = {0};
    Distancia.assign(n, 2222222222222222);
    Distancia[0] = 0;
    while(!Cola.empty()){
        long long Nodo = Cola[0];
        Cola.pop_front();
        for(auto E: Grafo[Nodo]) if(Distancia[Nodo] + 1 < Distancia[E]){
            Distancia[E] = Distancia[Nodo] + 1;
            Cola.push_back(E);
        }
    }
    /*for(auto E: Distancia) cout<<E<<" ";
    cout<<"\n";*/
    long long Izquierda = -0, Derecha = n + 22;
    Precios.assign(n, 0);
    Fila.assign(n, 0);
    set< pair<long long, long long> > Orden;
    for(long long i = 0; i < n; i++){
        Orden.insert(make_pair(Distancia[i], i));
        Precios[i] = -Grafo[i].size() + 1;
        if(i == 0) Precios[i]--;
    }
    long long p = n - 1;
    for(auto E: Orden){
        Fila[p] = E.second;
        p--;
    }
    /*for(auto E: Fila) cout<<E<<" ";
    cout<<"\n";*/
    long long Mejor = Derecha;
    /*for(long long i = 0; i < n; i++) cout<<Precios[i]<<" ";
    cout<<"\n";*/
    while(Izquierda <= Derecha){
        long long Promedio = (Izquierda + Derecha) / 2;
        for(long long i = 0; i < n; i++) Precios[i] += Promedio;
        if(Probar(Promedio)){
            Derecha = Promedio - 1;
            Mejor = Promedio;
        } else Izquierda = Promedio + 1;
        for(long long i = 0; i < n; i++) Precios[i] -= Promedio;
    }
    cout<<Mejor;
    return 0;
}
/*
16
1 3
2 1
4 1
3 5
6 3
2 7
7 8
7 9
7 10
7 11
12 7
13 4
16 13
14 13
13 15

18
1 2              
2 3
3 4
4 12
12 13
12 14
12 15
12 16
12 17
12 18
4 5
5 6
5 7
5 8
5 9
5 10
5 11
Este caso está mal.
*/