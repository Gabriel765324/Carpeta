#include "bits/stdc++.h"
#define ii pair<int, int>
#define vi vector<int>
#define ll long long
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < n; i++)
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define all(v) (v).beign(), (v).end()
#define di deque<int>
#define pf push_front
using namespace std;
vector< vi > Grafo;
vi Emparejado;
bitset<222> Visitados, Nada;
bool DFS(int Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(Emparejado[E] == -2){
            Emparejado[E] = Nodo;
            return 1;
        }
        if(Visitados[Emparejado[E]]) continue;
        bool Posible = DFS(Emparejado[E]);
        if(Posible){
            Emparejado[E] = Nodo;
            return 1;
        }
    }
    return 0;
}
void Resolver(){
    int n;
    cin>>n;
    Grafo.assign(n + 60, {});
    Emparejado.assign(n + 60, -2);
    forn(i, n){
        ll a;
        cin>>a;
        for(long long j = 0; j < 60LL; j++){
            if(a & (1LL<<j)){
                Grafo[i].push_back(j + n);
            }
        }
    }
    int Respuesta = n;
    forn(i, n){
        Respuesta -= (DFS(i) ? 1 : 0);
        Visitados &= Nada;
    }
    cout<<Respuesta<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        Resolver();
    }
    return 0;
}