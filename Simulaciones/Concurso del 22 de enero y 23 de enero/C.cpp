#include "bits/stdc++.h"
using namespace std;
vector< vector< pair<long long, long long> > > Grafo;
vector< vector<long long> > Levantamiento_binario;
vector< pair<long long, long long> > Contenerdores;
vector<long long> Anteriores;
vector<bool> Visitados;
long long Tiempo = 0;
void DFS(long long Nodo, long long Padre){
    Contenerdores[Nodo].first = Tiempo;
    Tiempo++;
    Visitados[Nodo] = 1;
    if(Nodo != Padre){
        Levantamiento_binario[Nodo].push_back(Padre);
        Anteriores[Nodo] = Padre;
        long long Anterior = Padre;
        for(long long i = 0; 1; i++){
            if(i < Levantamiento_binario[Anterior].size()){
                Levantamiento_binario[Nodo].push_back(Levantamiento_binario[Anterior][i]);
                Anterior = Levantamiento_binario[Anterior][i];
            } else break;
        }
    }
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E.first]) DFS(E.first, Nodo);
    }
    Contenerdores[Nodo].second = Tiempo;
    Tiempo++;
}
bool Contiene(long long u, long long v){
    return Contenerdores[u].first < Contenerdores[v].first and Contenerdores[u].second > Contenerdores[v].second;
}
long long Consulta(long long u, long long v){
    if(Contiene(u, v)) return u;
    if(Contiene(v, u)) return v;
    long long r = 0, Actual;
    for(Actual = u; !Contiene(Anteriores[Actual], v); ){
        long long i = 0, d = Levantamiento_binario[Actual].size() - 1, Mejor = i;
        while(1){
            long long p = (i + d) / 2;
            if(!Contiene(Levantamiento_binario[Actual][p], v)){
                Mejor = p;
                i = p + 1;
            } else d = p - 1;
            if(i >= d + 1) break;
        }
        Actual = Levantamiento_binario[Actual][Mejor];
    }
    return Anteriores[Actual];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, t, Respuesta = 0;
    cin>>n>>m>>t;
    Grafo.assign(n, {});
    Levantamiento_binario.assign(n, {});
    Contenerdores.assign(n, {-2, -2});
    Anteriores.assign(n, 0);
    Visitados.assign(n, 0);
    while(m--){
        long long u, v, w;
        cin>>u>>v>>w;
        Grafo[u].push_back({v, w});
        Grafo[v].push_back({u, w});
    }
    vector<long long> Distancias(n, 2222222222222222);
    Distancias[0] = 0;
    deque<long long> Cola = {0};
    while(!Cola.empty()){
        long long Nodo = Cola[0];
        Cola.pop_front();
        for(auto E: Grafo[Nodo]){
            if(Distancias[E.first] > Distancias[Nodo] + E.second){
                Distancias[E.first] = Distancias[Nodo] + E.second;
                Cola.push_back(E.first);
            }
        }
    }
    DFS(0, 0);
    for(long long i = 0; i < n - 1; i++){
        for(long long j = i + 1; j < n; j++){
            if(Distancias[i] + Distancias[j] - Distancias[Consulta(i, j)] * 2 <= t){
                Respuesta++;
                //cout<<i<<" "<<j<<" "<<Distancias[i] + Distancias[j] - Distancias[Consulta(i, j)] * 2<<"\n";
            }
        }
    }
    cout<<Respuesta;
    return 0;
}
/*
7 6 4
0 1 4
0 2 1
2 6 2
2 5 3
1 3 2
1 4 1

9
*/