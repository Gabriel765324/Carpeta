#include "bits/stdc++.h"
#define ll long long
#define mp make_pair
#define F first
#define S second
#define vi vector<int>
#define ii pair<int, int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
#define all(v) (v).begin(), (v).end()
using namespace std;
struct Nodo{
    long long p, v, i;
};
struct Probar{
    int i, d, v1, v2, r;
    bool Set_o__rbol;
};
Nodo operator+(const Nodo& a, const Nodo& b){
    if(b.v > a.v) return b;
    if(a.v > b.v) return a;
    if(b.i > a.i) return b;
    return a;
} //Bueno.
vi operator+(const vi& a, const vi& b){
    vi r;
    for(int i = 0, j = 0; i < a.size() or j < b.size(); ){
        if(i >= a.size()){
            r.pb(b[j]);
            j++;
        } else if(j >= b.size()){
            r.pb(a[i]);
            i++;
        } else {
            if(a[i] < b[i]){
                r.pb(a[i]);
                i++;
            } else {
                r.pb(b[j]);
                j++;
            }
        }
    }
    return r;
}
vector<Nodo> _rbol;
vector<vi> _rbol_ordenador;
vector<ii> Aristas;
set< ii, greater<ii> > Mejores;
vector<vi> Remover;
vi Originales;
void Crear(int i, int d, int p){
    if(i == d){
        _rbol_ordenador[p] = {Aristas[i].S};
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol_ordenador[p] = _rbol_ordenador[p * 2] + _rbol_ordenador[p * 2 + 1];
}
void Crear2(int i, int d, int p){
    if(i == d){
        _rbol[p].i = i;
        _rbol[p].p = 0;
        _rbol[p].v = -0;
        return;
    }
    int P = (i + d) / 2;
    Crear2(i, P, p * 2);
    Crear2(P + 1, d, p * 2 + 1);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
void Propagar(bool Seguir, int p){
    _rbol[p].v += _rbol[p].p;
    if(Seguir){
        _rbol[p * 2].p += _rbol[p].p;
        _rbol[p * 2 + 1].p += _rbol[p].p;
    }
    _rbol[p].p = -0;
}
Nodo Consulta(int i, int d, int p, int I, int D){
    Propagar(i != d, p);
    if(i >= I and d <= D){
        return _rbol[p];
    }
    if(i > D or d < I){
        Nodo Neutro;
        Neutro.v = -2222222222222222;
        Neutro.p = -0;
        Neutro.i = -2;
        return Neutro;
    }
    int P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(int i, int d, int p, int I, int D, long long Extra){
    Propagar(i != d, p);
    if(i >= I and d <= D){
        _rbol[p].p += Extra;
        Propagar(i != d, p);
        return;
    }
    if(i > D or d < I){
        return;
    }
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D, Extra);
    Actualizar(P + 1, d, p * 2 + 1, I, D, Extra);
}
bool Existe(int i, int d, int p, int I, int D, int v1, int v2){
    if(v2 > v1) return 0;
    if(i >= I and d <= D){
        int Posible = lower_bound(all(_rbol_ordenador[p]), v1) - _rbol_ordenador[p].begin();
        if(Posible < _rbol_ordenador[p].size() and _rbol_ordenador[p][Posible] >= v1 and _rbol_ordenador[p][Posible] <= v2){
            return 1;
        } else {
            return 0;
        }
    }
    if(i > D or d < I) return 0;
    int P = (i + d) / 2;
    return Existe(i, P, p * 2, I, D, v1, v2) or Existe(P + 1, d, p * 2 + 1, I, D, v1, v2);
}
void Resolver(){
    int n, m;
    cin>>n>>m;
    _rbol_ordenador.assign(m * 4 + 22, {});
    Nodo Nada;
    Nada.p = 0;
    Nada.v = 0;
    Nada.i = -2;
    _rbol.assign(n * 4 + 22, Nada);
    Crear2(0, n - 1, 1);
    Aristas.assign(m, {});
    Remover.assign(n + 2, {});
    Originales.assign(n + 2, 0);
    forn(i, m){
        int a, b;
        cin>>a>>b;
        Aristas[i] = mp(max(a, b), min(a, b));
    }
    sort(all(Aristas));
    Crear(0, m - 1, 1);
    int i = n - 2;
    Originales.back() = n;
    Remover[n].push_back(n);
    //cerr<<"Empieza."<<el;
    Mejores.insert(mp(-2222222222222222, -2));
    for(int Removedor = 1; i > -1; i--){
        //cerr<<i<<el;
        while(!Remover[Removedor].empty()){
            Actualizar(0, n - 1, 1, Remover[Removedor].back(), Remover[Removedor].back(), -2222222222222222);
            Mejores.insert(mp(Originales[Remover[Removedor].back()], Remover[Removedor].back()));
            Remover[Removedor].pop_back();
        }
        Actualizar(0, n - 1, 1, i + 1, n - 1, 1);
        //cerr<<"¿?\n";
        while(1){
            Nodo Mejor__rbol = Consulta(0, n - 1, 1, i + 1, n - 1);
            ii Mejor_set = *Mejores.begin();
            Probar Le_gana;
            if(Mejor__rbol.v > Mejor_set.F){
                Le_gana.Set_o__rbol = 0;
                Le_gana.v1 = i + 1;
                Le_gana.v2 = Mejor__rbol.i;
                Le_gana.r = Mejor__rbol.v;
            } else if(Mejor_set.F > Mejor__rbol.v){
                Le_gana.Set_o__rbol = 1;
                Le_gana.v1 = i + 1;
                Le_gana.v2 = Mejor_set.S;
                Le_gana.r = Mejor_set.F;
            } else {
                if(Mejor__rbol.p > Mejor_set.S){
                    Le_gana.Set_o__rbol = 0;
                    Le_gana.v1 = i + 1;
                    Le_gana.v2 = Mejor__rbol.i;
                    Le_gana.r = Mejor__rbol.v;
                } else {
                    Le_gana.Set_o__rbol = 1;
                    Le_gana.v1 = i + 1;
                    Le_gana.v2 = Mejor_set.S;
                    Le_gana.r = Mejor_set.F;
                }
            }
            //cerr<<Le_gana.Set_o__rbol<<el;
            Le_gana.i = m;
            Le_gana.d = m;
            int I1 = 0, D1 = m - 1;
            while(1){
                int P1 = (I1 + D1) / 2;
                if(Aristas[P1].F >= i + 1 and Aristas[P1].S >= i + 1){
                    I1 = P1 + 1;
                    Le_gana.i = P1;
                } else {
                    D1 = P1 - 1;
                }
                if(I1 >= D1 + 1) break;
            }
            I1 = 0, D1 = m - 1;
            while(1){
                int P1 = (I1 + D1) / 2;
                if(Aristas[P1].F <= Le_gana.v2 and Aristas[P1].S <= Le_gana.v2){
                    D1 = P1 - 1;
                    Le_gana.d = P1;
                } else {
                    I1 = P1 + 1;
                }
                if(I1 >= D1 + 1) break;
            }
            //cerr<<Le_gana.r<<" ";
            //Buscan el rango de la consulta en la cual se necesita saber si hay alguna arista 
            //que conecta 2 nodos que no estamos cubriendo.
            if(Existe(0, n - 1, 1, Le_gana.i, Le_gana.d, Le_gana.v1, Le_gana.v2)){
                if(Le_gana.Set_o__rbol) Mejores.erase(Mejores.begin());
                else Actualizar(0, n - 1, 1, Mejor__rbol.i, Mejor__rbol.i, -2222222222222222);
            } else {
                Originales[i] = Le_gana.r;
                cerr<<Originales[i]<<" ";
                if(Le_gana.r + Removedor < Remover.size()) Remover[Le_gana.r + Removedor].push_back(i);
                break;
            }
        }
        Removedor++;
    }
    cout<<Originales[0]<<el;
    //Veamos si funciona.
    //:)
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