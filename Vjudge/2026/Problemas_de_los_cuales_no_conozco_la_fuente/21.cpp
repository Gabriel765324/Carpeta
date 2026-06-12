#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define el "\n"
using namespace std;
string Cadena = "Z";
vi Primero(26, 0);
vector< vi > Grafo;
vi Respuesta, Mayor, _ndice;
bitset<100022> L_nea;
void Resolver(int Nodo, int Anterior){
    if(Nodo != 0){
        if(int(Grafo[Nodo].size()) == 1){
            L_nea[Nodo] = 1;
            return;
        }
        if(int(Grafo[Nodo].size()) == 2){
            L_nea[Nodo] = 1;
            for(auto E: Grafo[Nodo]){
                if(E == Anterior) continue;
                Resolver(E, Nodo);
                if(L_nea[E]){
                    _ndice[Nodo] = _ndice[E] + 1;
                    Respuesta[Nodo] = Cadena[_ndice[Nodo]];
                    Mayor[Nodo] = min(Mayor[E], Respuesta[Nodo]);
                    return;
                } else {
                    Respuesta[Nodo] = Mayor[E] - 1;
                    Mayor[Nodo] = Respuesta[Nodo];
                    _ndice[Nodo] = Primero[Respuesta[Nodo] - 'a'];
                    return;
                }
            }
        } else {
            for(auto E: Grafo[Nodo]){
                if(E == Anterior) continue;
                Resolver(E, Nodo);
                Respuesta[Nodo] = min(Respuesta[Nodo], Mayor[E] - 1);
                Mayor[Nodo] = Respuesta[Nodo];
            }
        }
    } else {
        if(int(Grafo[Nodo].size()) == 1){
            L_nea[Nodo] = 1;
            for(auto E: Grafo[Nodo]){
                if(E == Anterior) continue;
                Resolver(E, Nodo);
                if(L_nea[E]){
                    _ndice[Nodo] = _ndice[E] + 1;
                    Respuesta[Nodo] = Cadena[_ndice[Nodo]];
                    Mayor[Nodo] = min(Mayor[E], Respuesta[Nodo]);
                    return;
                } else {
                    Respuesta[Nodo] = Mayor[E] - 1;
                    Mayor[Nodo] = Respuesta[Nodo];
                    _ndice[Nodo] = Primero[Respuesta[Nodo] - 'a'];
                    return;
                }
            }
        } else {
            for(auto E: Grafo[Nodo]){
                if(E == Anterior) continue;
                Resolver(E, Nodo);
                Respuesta[Nodo] = min(Respuesta[Nodo], Mayor[E] - 1);
                Mayor[Nodo] = Respuesta[Nodo];
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 'Y'; i >= 'A'; i--){
        Primero[i - 'A'] = int(Cadena.size());
        Cadena += char(i) + Cadena;
    }
    int n;
    cin>>n;
    Grafo.assign(n, {});
    Respuesta.assign(n, 'Z');
    Mayor.assign(n, 'Z');
    _ndice.assign(n, 0);
    forn(i, n - 1){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].pb(b);
        Grafo[b].pb(a);
    }
    Resolver(0, -2);
    for(auto E: Respuesta) cout<<char(E)<<" ";
    return 0;
}