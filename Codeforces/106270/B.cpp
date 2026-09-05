#include "bits/stdc++.h"
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
typedef double ld;
const ll Mayor = 100000000000022;
const ld Mucho = (ld)2e16;
struct _rbol_de_Li_Chao{
    struct Nodo{
        ld p, d;
        int Izquierdo, Derecho;
        Nodo(){
            p = 0;
            d = Mucho;
            Izquierdo = -2;
            Derecho = -2;
        }
        Nodo(ld P, ld D){
            p = P;
            d = D;
            Izquierdo = -2;
            Derecho = -2;
        }
        ld Evaluar(ll x){
            //cerr<<"Recta: "<<p<<" * "<<x<<" + "<<d<<".\n";
            return p * (ld)x + d;
        }
    };
    vector<Nodo> _rbol;
    _rbol_de_Li_Chao(){}
    ld Consulta(ll i, ll d, int p, ll x){
        //cerr<<"CL "<<p<<" "<<int(_rbol.size())<<(p >= int(_rbol.size()) ? "------------" : "")<<"\n";
        if(p >= int(_rbol.size()) or p < 0) return Mucho;
        ld Mejor = _rbol[p].Evaluar(x);
        if(i == d) return Mejor;
        ll P = i + (d - i) / 2LL;
        if(x <= P){
            if(_rbol[x].Izquierdo == -2) return Mejor;
            return min(Mejor, Consulta(i, P, _rbol[p].Izquierdo, x));
        }
        if(_rbol[x].Derecho == -2) return Mejor;
        return min(Mejor, Consulta(P + 1LL, d, _rbol[p].Derecho, x));
    }
    void Actualizar(ll i, ll d, int p, Nodo Nuevo){
        //cerr<<"AL "<<p<<" "<<int(_rbol.size())<<(p >= int(_rbol.size()) ? "------------" : "")<<"\n";
        if(p >= int(_rbol.size()) or p < 0) return;
        ll P = i + (d - i) / 2LL;
        if(Nuevo.Evaluar(P) < _rbol[p].Evaluar(P)){
            Nuevo.Izquierdo = _rbol[p].Izquierdo;
            Nuevo.Derecho = _rbol[p].Derecho;
            swap(_rbol[p], Nuevo);
            Nuevo.Izquierdo = -2;
            Nuevo.Derecho = -2;
        }
        if(i == d) return;
        if(Nuevo.Evaluar(i) < _rbol[p].Evaluar(i)){
            if(_rbol[p].Izquierdo == -2){
                _rbol[p].Izquierdo = int(_rbol.size());
                _rbol.pb(Nodo());
            }
            Actualizar(i, P, _rbol[p].Izquierdo, Nuevo);
            return;
        }
        if(_rbol[p].Derecho == -2){
            _rbol[p].Derecho = int(_rbol.size());
            _rbol.pb(Nodo());
        }
        Actualizar(P + 1LL, d, _rbol[p].Derecho, Nuevo);
    }
    ld Consultar(ll x){
        if(_rbol.empty()) return Mucho;
        return Consulta(-Mayor, Mayor, 0, x);
    }
    void Actualizaci_n(ld p, ld d){
        if(_rbol.empty()) _rbol.pb(Nodo());
        Actualizar(-Mayor, Mayor, 0, Nodo(p, d));
    }
};
struct _rbol_de_segmentos{
    struct Hijos{
        int Izquierdo, Derecho;
        Hijos(){
            Izquierdo = -2;
            Derecho = -2;
        }
    };
    vector<_rbol_de_Li_Chao> _rbol;
    vector<Hijos> Continuaci_n;
    vector<ll> Compresor;
    _rbol_de_segmentos(){}
    void Comprimir(vector<ll> c){
        Compresor = c;
    }
    ld Consulta(ll i, ll d, int p, ll x){
        if(p >= int(_rbol.size()) or p < 0) return Mucho;
        //cerr<<"CA "<<p<<" "<<int(_rbol.size())<<(p >= int(_rbol.size()) ? "------------" : "")<<"\n";
        ld Mejor = _rbol[p].Consultar(x);
        //cerr<<i<<" "<<d<<" "<<p<<" "<<x<<" "<<Mejor<<el;
        if(i == d) return Mejor;
        ll P = i + (d - i) / 2LL;
        if(x <= P){
            if(Continuaci_n[p].Izquierdo == -2) return Mejor;
            return min(Consulta(i, P, Continuaci_n[p].Izquierdo, x), Mejor);
        }
        if(Continuaci_n[p].Derecho == -2) return Mejor;
        return min(Consulta(P + 1LL, d, Continuaci_n[p].Derecho, x), Mejor);
    }
    void Actualizar(ll i, ll d, int p, ll I, ll D, ld Pendiente, ld Desplazamiento){
        //cerr<<"AA "<<p<<" "<<int(_rbol.size())<<(p >= int(_rbol.size()) ? "------------" : "")<<"\n";
        if(p >= int(_rbol.size()) or p < 0) return;
        if(I <= i and d <= D){
            _rbol[p].Actualizaci_n(Pendiente, Desplazamiento);
            return;
        }
        if(d < I or D < i) return;
        ll P = i + (d - i) / 2LL;
        if(Continuaci_n[p].Izquierdo == -2){
            Continuaci_n[p].Izquierdo = int(_rbol.size());
            _rbol.pb(_rbol_de_Li_Chao());
            Continuaci_n.pb(Hijos());
        }
        Actualizar(i, P, Continuaci_n[p].Izquierdo, I, D, Pendiente, Desplazamiento);
        if(Continuaci_n[p].Derecho == -2){
            Continuaci_n[p].Derecho = int(_rbol.size());
            _rbol.pb(_rbol_de_Li_Chao());
            Continuaci_n.pb(Hijos());
        }
        Actualizar(P + 1LL, d, Continuaci_n[p].Derecho, I, D, Pendiente, Desplazamiento);
    }
    ld Consultar(ll x){
        x = lower_bound(all(Compresor), x) - Compresor.begin();
        ll Inicio = lower_bound(all(Compresor), -Mayor) - Compresor.begin();
        ll Final = lower_bound(all(Compresor), Mayor) - Compresor.begin();
        return Consulta(Inicio, Final, 0, x);
    }
    void Actualizaci_n(ll i, ll d, ld p, ld D){
        i = lower_bound(all(Compresor), i) - Compresor.begin();
        d = lower_bound(all(Compresor), d) - Compresor.begin();
        ll Inicio = lower_bound(all(Compresor), -Mayor) - Compresor.begin();
        ll Final = lower_bound(all(Compresor), Mayor) - Compresor.begin();
        if(_rbol.empty()){
            _rbol.pb(_rbol_de_Li_Chao());
            Continuaci_n.pb(Hijos());
        }
        Actualizar(Inicio, Final, 0, i, d, p, D);
    }
};
struct Consulta{
    char t;
    ll x;
    ld X, v;
    Consulta(char a, ll b){
        t = a;
        x = b;
    }
    Consulta(char a, ld b, ld c){
        t = a;
        X = b;
        v = c;
    }
};
void Resolver(){
    int n, q;
    cin>>n;
    _rbol_de_segmentos A = _rbol_de_segmentos();
    vector<ll> Compresor = {-Mayor};
    vector< pair<ll, ll> > Iniciales;
    while(n--){
        ll x, v;
        cin>>x>>v;
        Iniciales.pb(mp(x, v));
        Compresor.pb(x);
        //A.Actualizaci_n(-Mayor, x, (ld)-1 / v, x / v);
        //A.Actualizaci_n(x, Mayor, (ld)1 / v, -x / v);
    }
    cin>>q;
    vector<Consulta> Q;
    while(q--){
        char t;
        cin>>t;
        if(t == '?'){
            ll x;
            cin>>x;
            //cerr<<"-----------------\n"<<x<<el;
            //cout<<setprecision(222)<<A.Consultar(x)<<el;
            //cerr<<"-----------------\n";
            Q.pb(Consulta(t, x));
            Compresor.pb(x);
        } else {
            ll x, v;
            cin>>x>>v;
            //A.Actualizaci_n(-Mayor, x, (ld)-1 / v, x / v);
            //A.Actualizaci_n(x, Mayor, (ld)1 / v, -x / v);
            Q.pb(Consulta(t, x, v));
            Compresor.pb(x);
        }
    }
    Compresor.pb(Mayor);
    sort(all(Compresor));
    A.Comprimir(Compresor);
    for(auto E: Iniciales){
        A.Actualizaci_n(-Mayor, E.F, (ld)-1 / (ld)E.S, (ld)E.F / (ld)E.S);
        A.Actualizaci_n(E.F, Mayor, (ld)1 / (ld)E.S, -(ld)E.F / (ld)E.S);
    }
    for(auto E: Q){
        if(E.t == '?'){
            cout<<setprecision(222)<<A.Consultar(E.x)<<el;
        } else {
            A.Actualizaci_n(-Mayor, E.x, (ld)-1 / E.v, E.x / E.v);
            A.Actualizaci_n(E.x, Mayor, (ld)1 / E.v, -E.x / E.v);
        }
    }
    A = _rbol_de_segmentos();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}
/*
1
2
0 2
2 2
8
? 1
? -1
+ 3 5
? 1
? -1
+ 1 9
? 1
? -1
*/