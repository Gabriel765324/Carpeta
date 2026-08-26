#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
vector< vi > Grafo;
vi Estado, Representantes, Tama_os;
bitset<100022> Ciclos;
int Buscar(int a){
    if(Representantes[a] == a) return a;
    return Representantes[a] = Buscar(Representantes[a]);
}
void Unir(int a, int b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        if(Tama_os[a] < Tama_os[b]) swap(a, b);
        Tama_os[a] += Tama_os[b];
        Representantes[b] = a;
    }
}
void DFS(int Nodo){
    Estado[Nodo] = 1;
    int r = 1;
    for(auto E: Grafo[Nodo]){
        if(Estado[E] == 1) Ciclos[Buscar(Nodo)] = 1;
        if(Estado[E] == 0) DFS(E);
    }
    Estado[Nodo] = 2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c = 0, r = 0;
    cin>>n>>m;
    bitset<100022> Usados, Nada;
    Estado.assign(n, 0);
    Grafo.assign(n, {});
    forn(i, n){
        Representantes.pb(i);
        Tama_os.pb(1);
    }
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        c += !Usados[a];
        c += !Usados[b];
        Usados[a] = 1;
        Usados[b] = 1;
        Unir(a, b);
    }
    forn(i, n) if(Estado[i] == 0) DFS(i);
    Usados &= Nada;
    forn(i, n){
        int ri = Buscar(i);
        if(!Usados[ri]){
            Usados[ri] = 1;
            if(Ciclos[ri]){
                r += Tama_os[ri];
            } else {
                r += Tama_os[ri] - 1;
            }
        }
    }
    cout<<r<<el;
    return 0;
}