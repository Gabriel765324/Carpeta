#include "bits/stdc++.h"
#define ll long long
#define el "\n"
#define mp make_pair
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define ii pair<int, int>
#define vi vector<int>
#define pb push_back
using namespace std;
vector< vi > Grafo, GrafoT;
vector<ll> Costos;
vi Componente;
vi Orden;
vector<bool> Visitados;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E]){
            DFS(E);
        }
    }
    Orden.push_back(Nodo);
}
void DFS2(int Nodo){
    Visitados[Nodo] = 1;
    for(auto E: GrafoT[Nodo]){
        if(!Visitados[E]){
            DFS2(E);
        }
    }
    Componente.push_back(Costos[Nodo]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n;
    Grafo.assign(n, {});
    GrafoT.assign(n, {});
    Costos.assign(n, {});
    Visitados.assign(n, 0);
    forn(i, n) cin>>Costos[i];
    cin>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        GrafoT[b].push_back(a);
    }
    forn(i, n){
        if(!Visitados[i]){
            DFS(i);
        }
    }
    ll Respuesta = 0, Copias = 1;
    Visitados.assign(n, 0);
    for(int i = n - 1; i > -1; i--){
        if(!Visitados[Orden[i]]){
            Componente.clear();
            DFS2(Orden[i]);
            sort(all(Componente));
            Componente.pb(-2);
            Respuesta += Componente[0];
            forsn(j, 1, Componente.size()){
                if(Componente[j] != Componente[j - 1]){
                    Copias = (Copias % 1000000007LL * (long long)j % 1000000007LL) % 1000000007LL;
                    break;
                }
            }
        }
    }
    cout<<Respuesta<<" "<<Copias;
    return 0;
}