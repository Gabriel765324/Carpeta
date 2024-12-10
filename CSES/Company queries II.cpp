#include "bits/stdc++.h"
using namespace std;
struct Valor{
    long long u, v, ID;
};
vector<long long> Distancias;
bool o(Valor &a, Valor &b){
    long long v1 = min(Distancias[a.u], Distancias[a.v]), v2 = min(Distancias[b.u], Distancias[b.v]);
    return v1 > v2;
}
vector<long long> r;
long long Buscar(long long a){
    if(r[a] == a) return a;
    return r[a] = Buscar(r[a]);
}
void Unir(long long a, long long b){
    a = Buscar(a);
    b = Buscar(b);
    r[a] = b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, q;
    cin>>n>>q;
    vector< vector<long long> > Grafo(n);
    vector<long long> Anterior(n);
    Distancias.assign(n, 2222222222222222);
    r.assign(n, 0);
    for(long long i = 1; i < n; i++){
        r[i] = i;
        long long a;
        cin>>a;
        a--;
        Grafo[a].push_back(i);
        Anterior[i] = a;
    }
    Distancias[0] = 0;
    long long m = 1;
    deque<long long> Cola = {0};
    while(!Cola.empty()){
        long long Nodo = Cola[0];
        Cola.pop_front();
        for(auto E: Grafo[Nodo]){
            if(Distancias[E] > Distancias[Nodo] + 1){
                Cola.push_back(E);
                Distancias[E] = Distancias[Nodo] + 1; 
                m = max(m, Distancias[E] + 1);
            }
        }
    }
    vector< vector<long long> > Capas(m);
    for(long long i = 0; i < n; i++){
        Capas[Distancias[i]].push_back(i);
    }
    vector<long long> Respuestas(q, -2);
    vector<Valor> Consultas(q);
    for(long long i = 0; i < q; i++){
        cin>>Consultas[i].u>>Consultas[i].v;
        Consultas[i].u--;
        Consultas[i].v--;
        Consultas[i].ID = i;
    }
    sort(Consultas.begin(), Consultas.end(), o);
    long long c = 0;
    for(long long i = m - 2; i > -1; i--){
        for(auto E: Capas[i + 1]){
            Unir(E, Anterior[E]);
        }
        /*Solo falta corregir esto para que funcione, antes del break podrían haber más consultas que se pueden responder.*/
        for(; c < q; c++){
            if(Buscar(Consultas[c].u) == Buscar(Consultas[c].v)) Respuestas[Consultas[c].ID] = Buscar(Consultas[c].v) + 1;
            else break;
        }
        /**/
    }
    for(long long i = 0; i < q; i++){
        if(Consultas[i].u == Consultas[i].v) Respuestas[Consultas[i].ID] = Consultas[i].u;
        if(Consultas[i].u == 1 or Consultas[i].v == 1) Respuestas[Consultas[i].ID] = 1;
    }
    for(auto E: Respuestas) cout<<E<<"\n";
    return 0;
}