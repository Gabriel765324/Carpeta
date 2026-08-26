#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
vi Respuestas, Destinos, Grafo_plano, _rbol_r, _rbol_d, Propagar_r, Propagar_d;
vector< vi > Grafo, GrafoT;
vector< ii > Sub_rboles;
bitset<222222> Visitados;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    Sub_rboles[Nodo].F = Grafo_plano.size();
    for(auto E: GrafoT[Nodo]){
        if(!Visitados[E]){
            DFS(E);
        }
    }
    Sub_rboles[Nodo].S = Grafo_plano.size();
    Grafo_plano.pb(Nodo);
}
int Resolver(int Nodo){
    if(Visitados[Nodo]) return Respuestas[Nodo];
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(E < int(Grafo.size())){
            Respuestas[Nodo] = 1 + Resolver(E);
            Destinos[Nodo] = Destinos[E];
        }
    }
    Destinos[Nodo] = Nodo;
    return Respuestas[Nodo] = 1;
}
void Crear(int i, int d, int p){
    if(i == d){
        _rbol_d[p] = Destinos[i];
        _rbol_r[p] = Respuestas[i];
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol_r[p] = _rbol_r[p * 2] + _rbol_r[p * 2 + 1];
    _rbol_d[p] = _rbol_d[p * 2] + _rbol_d[p * 2 + 1];
}
void Propagar(bool Seguir, int p){
    _rbol_r[p] += Propagar_r[p];
    if(Propagar_d[p] != -2){
        _rbol_d[p] = Propagar_d[p];
    }
    if(Seguir){
        Propagar_r[p * 2] += Propagar_r[p];
        Propagar_r[p * 2 + 1] += Propagar_r[p];
        Propagar_d[p * 2] = Propagar_d[p];
        Propagar_d[p * 2 + 1] = Propagar_d[p];
    }
    Propagar_r[p] = 0;
    Propagar_d[p] = -2;
}
pair<int, int> Consulta(int i, int d, int p, int c){
    Propagar(i != d, p);
    if(i == d and d == c){
        return {_rbol_d[p] + 1, _rbol_r[p]};
    }
    if(i > c or d < c){
        return {-2, -2};
    }
    int P = (i + d) / 2;
    return max(Consulta(i, P, p * 2, c), Consulta(P + 1, d, p * 2 + 1, c));
}
void Actualizar_r(int i, int d, int p, int I, int D, int v){
    Propagar(i != d, p);
    if(i >= I and d <= D){
        Propagar_r[p] += v;
        Propagar(i != d, p);
        return;
    }
    if(i > D or d < I){
        return;
    }
    int P = (i + d) / 2;
    Actualizar_r(i, P, p * 2, I, D, v);
    Actualizar_r(P + 1, d, p * 2 + 1, I, D, v);
    _rbol_r[p] = _rbol_r[p * 2] + _rbol_r[p * 2 + 1];
}
void Actualizar_d(int i, int d, int p, int I, int D, int v){
    Propagar(i != d, p);
    if(i >= I and d <= D){
        Propagar_d[p] = v;
        Propagar(i != d, p);
        return;
    }
    if(i > D or d < I){
        return;
    }
    int P = (i + d) / 2;
    Actualizar_d(i, P, p * 2, I, D, v);
    Actualizar_d(P + 1, d, p * 2 + 1, I, D, v);
    _rbol_d[p] = _rbol_d[p * 2] + _rbol_d[p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    Grafo.assign(n, {});
    GrafoT.assign(n, {});
    Sub_rboles.assign(n, {0, 0});
    Respuestas.assign(n, 0);
    Destinos.assign(n, 0);
    _rbol_r.assign(n * 4 + 22, 0);
    _rbol_d.assign(n * 4 + 22, 0);
    Propagar_r.assign(n * 4 + 22, 0);
    Propagar_d.assign(n * 4 + 22, -2);
    vi a(n);
    forn(i, n){
        cin>>a[i];
        if(i + a[i] < n){
            GrafoT[i + a[i]].pb(i);
            Grafo[i].pb(i + a[i]);
        }
    }
    forn(i, n){
        if(!Visitados[i]){
            DFS(i);
        }
    }
    bitset<222222> Nada;
    Visitados = Visitados & Nada;
    forn(i, n){
        if(!Visitados[i]){
            Resolver(i);
        }
    }
    Crear(0, n - 1, 1);
    while(k--){
        int t;
        cin>>t;
        if(t == 0){
            int b, c;
            cin>>b>>c;
            b--;
            if(b + c >= n){
                Actualizar_d(0, n - 1, 1, Sub_rboles[b].F, Sub_rboles[b].S, b);
                int v = 1;
                if(b + a[b] < n){
                    v -= Consulta(0, n - 1, 1, Sub_rboles[b + a[b]].S).S;
                }
                Actualizar_r(0, n - 1, 1, Sub_rboles[b].F, Sub_rboles[b].S, v);
            }
        }
    }
    return 0;
}