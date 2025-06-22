#include "bits/stdc++.h"
using namespace std;
struct Nodo{
    long long Arista, Peso;
};
bool operator<(const Nodo& a, const Nodo& b){
    if(a.Peso < b.Peso) return 1;
    if(a.Peso > b.Peso) return 0;
    return a.Arista < b.Arista;
}
vector< vector<Nodo> > Grafo;
long long Diez_m_s(long long x, long long s, long long m){
    x = (x % m * 10 % m) % m;
    x = (x % m + s % m) % m;
    return x % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long k;
    cin>>k;
    Grafo.assign(k + 1, {});
    for(long long i = 0; i < k; i++){
        for(long long j = 0; j < 10; j++){
            Nodo a;
            a.Arista = Diez_m_s(i, j, k);
            a.Peso = j;
            Grafo[i].push_back(a);
        }
    }
    for(long long i = 1; i < 10; i++){
        Nodo a, b;
        a.Arista = i % k;
        a.Peso = i;
        Grafo[k].push_back(a);
    }
    set<Nodo> Cola;
    Nodo Inicio;
    Inicio.Arista = k;
    Inicio.Peso = -0;
    Cola.insert(Inicio);
    vector<long long> Distancias(k + 1, 2222222222222222);
    Distancias[k] = -0;
    while(!Cola.empty()){
        Nodo Actual = *Cola.begin();
        Cola.erase(Actual);
        if(Distancias[Actual.Arista] < Actual.Peso) continue;
        for(auto E: Grafo[Actual.Arista]){
            if(Distancias[E.Arista] > Distancias[Actual.Arista] + E.Peso){
                Distancias[E.Arista] = Distancias[Actual.Arista] + E.Peso;
                Nodo Siguiente;
                Siguiente.Arista = E.Arista;
                Siguiente.Peso = Distancias[E.Arista];
                Cola.insert(Siguiente);
            }
        }
    }
    /*for(long long i = 0; i <= k; i++){
        cout<<i<<"  ";
        for(auto e: Grafo[i]) cout<<e.Arista<<" ";
        cout<<"\n";
    }*/
    cout<<Distancias[0];
    return 0;
}