#include "bits/stdc++.h"
#define ii pair<int, int>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define el "\n"
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
vector<ll> _rbol_menor, _rbol_mayor, Propagar;
inline int Tama_o(int i, int d){
    return ((d - i + 1)<<1);
}
pair<long long, long long> operator+(const pair<long long, long long>& a, const pair<long long, long long>& b){
    return mp(max(a.F, b.F), min(a.S, b.S));
}
void Propagando(int i, int d, int p){
    if(Propagar[p] == 0LL) return;
    _rbol_mayor[p] += Propagar[p];
    _rbol_menor[p] += Propagar[p];
    if(i != d){
        Propagar[p + 1] += Propagar[p];
        Propagar[p + Tama_o(i, (i + d)>>1)] += Propagar[p];
    }
    Propagar[p] = 0;
}
pair<long long, long long> Consulta(int i, int d, int p, int I, int D){
    Propagando(i, d, p);
    if(I <= i and d <= D) return mp(_rbol_mayor[p], _rbol_menor[p]);
    if(D < i or d < I) return mp(-2LL, LLONG_MAX);
    int P = (i + d)>>1;
    return Consulta(i, P, p + 1, I, D) + Consulta(P + 1, d, p + Tama_o(i, P), I, D);
}
void Actualizar(int i, int d, int p, int I, int D, long long v){
    Propagando(i, d, p);
    if(I <= i and d <= D){
        Propagar[p] += v;
        Propagando(i, d, p);
        return;
    }
    if(D < i or d < I) return;
    int P = (i + d)>>1;
    Actualizar(i, P, p + 1, I, D, v);
    Actualizar(P + 1, d, p + Tama_o(i, P), I, D, v);
    _rbol_mayor[p] = max(_rbol_mayor[p + 1], _rbol_mayor[p + Tama_o(i, P)]);
    _rbol_menor[p] = min(_rbol_menor[p + 1], _rbol_menor[p + Tama_o(i, P)]);
}
struct Bloque{
    bool s;
    ll l, p;
    Bloque(){}
    Bloque(char SS, ll L, ll P){
        s = SS == '-';
        l = L;
        p = P;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> Posibles;
    vector<Bloque> a(n);
    forn(i, n){
        char s;
        ll l, p;
        cin>>s>>l>>p;
        a[i] = Bloque(s, l, p);
        Posibles.pb(p - 1LL);
        Posibles.pb(p);
        Posibles.pb(p + 1LL);
        if(a[i].s){
            Posibles.pb(p + l);
            Posibles.pb(p + l - 2LL);
            Posibles.pb(p + l - 1LL);
        }
    }
    sort(all(Posibles));
    vector<ll> Comprimir;
    Comprimir.pb(Posibles[0]);
    forsn(i, 1, Posibles.size()){
        if(Posibles[i] != Posibles[i - 1]) Comprimir.pb(Posibles[i]);
    }
    n = int(Comprimir.size()) + 22;
    _rbol_mayor.assign(n * 2 + 22, 0);
    _rbol_menor.assign(n * 2 + 22, 0);
    Propagar.assign(n * 2 + 22, 0);
    for(auto E: a){
        //cerr<<E.s<<" "<<E.l<<" "<<E.p<<el;
        ll i = E.p, d = i;
        if(E.s) d += E.l - 1LL;
        ll v = E.s ? 1 : E.l;
        i = lower_bound(all(Comprimir), i) - Comprimir.begin();
        d = lower_bound(all(Comprimir), d) - Comprimir.begin();
        auto Ver = Consulta(0, n - 1, 0, int(i), (int)d);
        if(Ver.F == Ver.S){
            Actualizar(0, n - 1, 0, (int)i, (int)d, v);
            cout<<"S";
        } else cout<<"U";
    }
    cout<<el;
    return 0;
}