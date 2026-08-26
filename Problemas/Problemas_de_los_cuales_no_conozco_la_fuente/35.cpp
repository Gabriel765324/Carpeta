#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define el "\n"
using namespace std;
vi r, t;
int c;
int Buscar(int a){
    return (a == r[a] ? a : r[a] = Buscar(r[a]));
}
void Unir(int a, int b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        c--;
        if(t[a] < t[b]) swap(a, b);
        t[a] += t[b];
        r[b] = a;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    c = n;
    bitset<222222> Color;
    forn(i, n){
        int a;
        cin>>a;
        Color[i] = a;
        r.pb(i);
        t.pb(1);
    }
    vector< ii > Aristas(n - 1);
    forn(i, n - 1){
        cin>>Aristas[i].F>>Aristas[i].S;
        Aristas[i].F--;
        Aristas[i].S--;
        if(Color[Aristas[i].F] == Color[Aristas[i].S]) Unir(Aristas[i].F, Aristas[i].S);
    }
    vector< vi > Grafo(n);
    map<int, int> Comprimir;
    int Inicio = 0;
    for(auto E: Aristas){
        int a = Buscar(E.F), b = Buscar(E.S);
        Inicio = a;
        if(Color[a] == Color[b]) continue;
        Grafo[a].pb(b);
        swap(a, b);
        Grafo[a].pb(b);
    }
    vi Distancias(n, INT_MAX);
    queue<int> Cola;
    Cola.push(Inicio);
    int Mayor = 0, Elegido = Inicio, d = 0;
    Distancias[Inicio] = 0;
    while(!Cola.empty()){
        int Nodo = Cola.front();
        Cola.pop();
        if(Distancias[Nodo] > Mayor){
            Mayor = Distancias[Nodo];
            Elegido = Nodo;
        }
        for(auto E: Grafo[Nodo]){
            if(Distancias[E] <= Distancias[Nodo] + 1) continue;
            Distancias[E] = Distancias[Nodo] + 1;
            Cola.push(E);
        }
    }
    forn(i, n) Distancias[i] = INT_MAX;
    Distancias[Elegido] = 0;
    Cola.push(Elegido);
    while(!Cola.empty()){
        int Nodo = Cola.front();
        Cola.pop();
        d = max(d, Distancias[Nodo]);
        for(auto E: Grafo[Nodo]){
            if(Distancias[E] <= Distancias[Nodo] + 1) continue;
            Distancias[E] = Distancias[Nodo] + 1;
            Cola.push(E);
        }
    }
    //cerr<<d<<el;
    cout<<((d + 1) >> 1)<<el;
    return 0;
}