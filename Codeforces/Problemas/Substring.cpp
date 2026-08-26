#include "bits/stdc++.h"
using namespace std;
long long n, m, o = 0;
string s;
vector< vector<long long> > Grafo;
vector<long long> Orden, Puntos;
vector<bool> Visitados;
void DFS(long long Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]) if(!Visitados[E]) DFS(E);
    Orden[Nodo] = o;
    o++;
}
long long Calcular(long long Nodo, char Messirve){
    if(Visitados[Nodo]) return Puntos[Nodo];
    Visitados[Nodo] = 1;
    long long Mayor = 0;
    for(auto E: Grafo[Nodo]) Mayor = max(Mayor, Calcular(E, Messirve));
    return Puntos[Nodo] = Mayor + (long long)(s[Nodo] == Messirve);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>s;
    Grafo.assign(n, {});
    Orden.assign(n, 0);
    Visitados.assign(n, 0);
    for(long long i = 0; i < m; i++){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
    }
    for(long long i = 0; i < n; i++){
        if(!Visitados[i]) DFS(i);
    }
    for(long long i = 0; i < n; i++){
        for(auto E: Grafo[i]){
            if(Orden[i] <= Orden[E]){
                cout<<-1;
                return 0;
            }
        }
    }
    long long r = 0;
    for(long long i = 'a'; i <= 'z'; i++){
        Visitados.assign(n, 0);
        Puntos.assign(n, -2);
        for(long long j = 0; j < n; j++){
            if(!Visitados[j]) r = max(r, Calcular(j, i));
        }
    }
    cout<<r;
    return 0;
}