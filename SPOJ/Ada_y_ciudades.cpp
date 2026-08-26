#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
struct Arista{
    int v, iID;
    ll Capacidad, Flujo;
    Arista(){}
    Arista(int V, int i, ll c, ll f){
        v = V;
        iID = i;
        Capacidad = c;
        Flujo = f;
    }
};
vector<Arista> Lista;
vector< vi > Grafo;
vector<ll> Niveles;
vi Actuales;
bool BFS(int i, int f){
    fill(all(Niveles), 2222222222222222);
    Niveles[i] = 0;
    queue<int> Cola;
    Cola.push(i);
    while(!Cola.empty()){
        int Nodo = Cola.front();
        Cola.pop();
        for(auto E: Grafo[Nodo]){
            if(Lista[E].Flujo >= Lista[E].Capacidad) continue;
            int Siguiente = Lista[E].v;
            if(Niveles[Siguiente] > Niveles[Nodo] + 1){
                Niveles[Siguiente] = Niveles[Nodo] + 1;
                Cola.push(Siguiente);
            }
        }
    }
    return Niveles[f] <= 2222;
}
int DFS(int Nodo, int Final, ll Flujo_mandado){
    if(Nodo == Final) return Flujo_mandado;
    for(; Actuales[Nodo] < int(Grafo[Nodo].size()); Actuales[Nodo]++){
        int Siguiente = Lista[Grafo[Nodo][Actuales[Nodo]]].v;
        if(Niveles[Siguiente] != Niveles[Nodo] + 1) continue;
        ll Mandable = Lista[Grafo[Nodo][Actuales[Nodo]]].Capacidad - Lista[Grafo[Nodo][Actuales[Nodo]]].Flujo;
        if(Mandable <= 0LL) continue;
        ll Flujo_posible = DFS(Siguiente, Final, min(Mandable, Flujo_mandado));
        if(Flujo_posible <= 0LL) continue;
        Flujo_mandado = min(min(Flujo_mandado, Mandable), Flujo_posible);
        Lista[Grafo[Nodo][Actuales[Nodo]]].Flujo += Flujo_mandado;
        int iID = Lista[Grafo[Nodo][Actuales[Nodo]]].iID;
        Lista[iID].Flujo -= Flujo_mandado;
        return Flujo_mandado;
    }
    return -2LL;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int Casos;
    cin>>Casos;
    while(Casos--){
        int n, m, f;
        ll t;
        cin>>n>>m>>f>>t;
        vector< vector<ll> > Grafo_(n, vector<ll>(n, 222222222222));
        vi Posiciones(f);
        forn(i, f){
            cin>>Posiciones[i];
            Posiciones[i]--;
        }
        while(m--){
            int a, b;
            ll c;
            cin>>a>>b>>c;
            a--;
            b--;
            Grafo_[a][b] = min(c, Grafo_[a][b]);
            Grafo_[b][a] = min(c, Grafo_[b][a]);
        }
        forn(i, n) Grafo_[i][i] = 0LL;
        forn(k, n){
            forn(i, n){
                forn(j, n){
                    Grafo_[i][j] = min(Grafo_[i][j], Grafo_[i][k] + Grafo_[k][j]);
                }
            }
        }
        int Tama_o = f + n + 22, Fuente = f + n + 2, Desag_e = f + n + 4, ID = 0;
        Grafo.assign(Tama_o, vi());
        Niveles.assign(Tama_o, 0);
        Actuales.assign(Tama_o, 0);
        forn(i, f){
            Grafo[Fuente].pb(ID);
            Grafo[i].pb(ID + 1);
            Lista.pb(Arista(i, ID + 1, 1LL, 0LL));
            Lista.pb(Arista(Fuente, ID, 0LL, 0LL));
            ID += 2;
            forn(j, n){
                if(Grafo_[Posiciones[i]][j] <= t){
                    Grafo[i].pb(ID);
                    Grafo[j + f].pb(ID + 1);
                    Lista.pb(Arista(j + f, ID + 1, 1LL, 0LL));
                    Lista.pb(Arista(i, ID, 0LL, 0LL));
                    ID += 2;
                }
            }
        }
        forn(i, n){
            Grafo[i + f].pb(ID);
            Grafo[Desag_e].pb(ID + 1);
            Lista.pb(Arista(Desag_e, ID + 1, 1LL, 0LL));
            Lista.pb(Arista(i + f, ID, 0LL, 0LL));
            ID += 2;
        }
        ll r = 0LL;
        while(BFS(Fuente, Desag_e)){
            fill(all(Actuales), 0);
            ll Flujito_extra;
            while(Flujito_extra = DFS(Fuente, Desag_e, LLONG_MAX)){
                if(Flujito_extra <= 0LL) break;
                r += Flujito_extra;
            }
        }
        cout<<r<<el;
        Lista.clear();
    }
    return 0;
}