#include "bits/stdc++.h"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i< int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define el "\n"
#define pb push_back
#define mp make_pair
using namespace std;
vi _rbol, Grafo_plano;
vector< ii > Inicios_y_finales;
vector< vi > Grafo, Colores;
bitset<222222> Visitados;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    Inicios_y_finales[Nodo].F = Grafo_plano.size();
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E]){
            DFS(E);
        }
    }
    Inicios_y_finales[Nodo].S = Grafo_plano.size();
    Grafo_plano.push_back(Nodo);
}
int Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return -0;
    int P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(int i, int d, int p, int c){
    if(i == d and d == c){
        _rbol[p] = 1 - _rbol[p];
        return;
    }
    if(i > c or d < c) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, c);
    Actualizar(P + 1, d, p * 2 + 1, c);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
int main(){
    FastIO;
    int n, q;
    cin>>n>>q;
    Grafo.assign(n + 2, {});
    Colores.assign(2 * (q + n + 2222), {});
    _rbol.assign(n * 22 + 22, 0);
    Inicios_y_finales.assign(n + 2, {});
    set<int> Comprimir;
    map<int, int> Colores_comprimidos;
    vi a(n);
    forn(i, n){
        cin>>a[i];
        Comprimir.insert(a[i]);
    }
    int c = 0;
    /*for(auto E: Comprimir){
        Colores_comprimidos[E] = c;
        c++;
    }
    forn(i, n){
        a[i] = Colores_comprimidos[a[i]];
        Colores[a[i]].push_back(i);
    }*/
    forn(i, n - 1){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        Grafo[u].pb(v);
        Grafo[v].pb(u);
    }
    DFS(0);
    vi Respuestas(q);
    vector< vector< ii > > Nuevas_consultas(2 * (n + q + 2222));
    vector< ii > Consultas(q);
    forn(i, q){
        cin>>Consultas[i].F>>Consultas[i].S;
        Consultas[i].F--;
        /*if(Colores_comprimidos.count(Consultas[i].S) == 0){
            Colores_comprimidos[Consultas[i].S] = c;
            c++;
        } else Consultas[i].S = Colores_comprimidos[Consultas[i].S];*/
        Comprimir.insert(Consultas[i].S);
        //Nuevas_consultas[Consultas[i].S].pb(mp(Consultas[i].F, i));
    }
    for(auto E: Comprimir){
        Colores_comprimidos[E] = c;
        c++;
    }
    forn(i, n){
        a[i] = Colores_comprimidos[a[i]];
        Colores[a[i]].push_back(i);
    }
    forn(i, q){
        Consultas[i].S = Colores_comprimidos[Consultas[i].S];
        Nuevas_consultas[Consultas[i].S].pb(mp(Consultas[i].F, i));
    }
    forn(i, Colores.size()){
        forn(j, Colores[i].size()){
            Actualizar(0, n - 1, 1, Inicios_y_finales[Colores[i][j]].S);
        }
        forn(j, Nuevas_consultas[i].size()){
            Respuestas[Nuevas_consultas[i][j].S] = Consulta(0, n - 1, 1, Inicios_y_finales[Nuevas_consultas[i][j].F].F, Inicios_y_finales[Nuevas_consultas[i][j].F].S);
        }
        forn(j, Colores[i].size()){
            Actualizar(0, n - 1, 1, Inicios_y_finales[Colores[i][j]].S);
        }
    }
    for(auto E: Respuestas) cout<<E<<el;
    return 0;
}