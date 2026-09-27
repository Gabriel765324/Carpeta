#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define el "\n"
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
using namespace std;
inline int Tama_o(int i, int d){
    return 2 * (d - i + 1);
}
struct _rbol_de_segmentos_de_sumas{
    vector<ll> _rbol, a;
    vector< ii > Propagar;
    int n;
    _rbol_de_segmentos_de_sumas(int N, vector<ll>& A){
        n = N;
        a = A;
        _rbol.assign(n * 2 + 22, 0);
        Propagar.assign(n * 2 + 22, {});
    }
    void Propagando(int i, int d, int P, int p){
        if(Propagar[p].F == -2) return;
        if(Propagar[p].F == 0){
            _rbol[p] = 0;
            if(i != d){
                Propagar[p + 1] = mp(0, 0);
                Propagar[p + Tama_o(i, P)] = mp(0, 0);
            }
            Propagar[p].F = -2;
        }
        if(Propagar[p].F == -1){
            _rbol[p] = a[d];
            if(i > 0) _rbol[p] -= a[i - 1];
            if(i != d){
                Propagar[p + 1] = mp(-1, 0);
                Propagar[p + Tama_o(i, P)] = mp(-1, 0);
            }
            Propagar[p].F = -2;
        }
        _rbol[p] += (ll)Propagar[p].S * (ll)(d - i + 1);
        if(i != d){
            Propagar[p + 1].S += Propagar[p].S;
            if(Propagar[p + 1].F == -2) Propagar[p + 1].F = 1;
            Propagar[p + Tama_o(i, P)].S += Propagar[p].S;
            if(Propagar[p + Tama_o(i, P)].F == -2) Propagar[p + Tama_o(i, P)].F = 1;
        }
        Propagar[p] = mp(-2, 0);
    }
    void Sumar(int i, int d, int p, int I, int D, ll v){
        if(D < I) return;
        int P = (i + d) / 2;
        Propagando(i, d, P, p);
        if(I <= i and d <= D){
            Propagar[p] = mp(1, v);
            Propagando(i, d, P, p);
            return;
        }
        if(d < I or D < i) return;
        Sumar(i, P, p + 1, I, D, v);
        Sumar(P + 1, d, p + Tama_o(i, P), I, D, v);
        _rbol[p] = _rbol[p + 1] + _rbol[p + Tama_o(i, P)];
    }
    void Llenar(int i, int d, int p, int I, int D){
        if(D < I) return;
        int P = (i + d) / 2;
        Propagando(i, d, P, p);
        if(I <= i and d <= D){
            Propagar[p] = mp(-1, 0);
            Propagando(i, d, P, p);
            return;
        }
        if(d < I or D < i) return;
        Llenar(i, P, p + 1, I, D);
        Llenar(P + 1, d, p + Tama_o(i, P), I, D);
        _rbol[p] = _rbol[p + 1] + _rbol[p + Tama_o(i, P)];
    }
    void Cerear(int i, int d, int p, int I, int D){
        if(D < I) return;
        int P = (i + d) / 2;
        Propagando(i, d, P, p);
        if(I <= i and d <= D){
            Propagar[p] = mp(0, 0);
            Propagando(i, d, P, p);
            return;
        }
        if(d < I or D < i) return;
        Cerear(i, P, p + 1, I, D);
        Cerear(P + 1, d, p + Tama_o(i, P), I, D);
        _rbol[p] = _rbol[p + 1] + _rbol[p + Tama_o(i, P)];
    }
    ll Consulta(int i, int d, int p, int I, int D){
        if(D < I) return 0LL;
        int P = (i + d) / 2;
        Propagando(i, d, P, p);
        if(I <= i and d <= D) return _rbol[p];
        if(d < I or D < i) return -0LL;
        return Consulta(i, P, p + 1, I, D) + Consulta(P + 1, d, p + Tama_o(i, P), I, D);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<ll> s(n, 0);
    forn(i, n){
        cin>>s[i];
        if(i > 0) s[i] += s[i - 1];
    }
    _rbol_de_segmentos_de_sumas _rbol = _rbol_de_segmentos_de_sumas(n, s);
    while(m--){
        /*cerr<<"----------------\n";
        forn(i, n) cerr<<_rbol.Consulta(0, n - 1, 0, i, i)<<" ";
        cerr<<"\n----------------\n\n\n";*/
        int t, a, b;
        cin>>t>>a>>b;
        a--;
        if(t == 1){
            int i = 0, d = a, Mejor = 0;
            bool Bien = 0;
            ll Suma = s[a];
            while(i < d + 1){
                int p = (i + d) / 2;
                if(_rbol.Consulta(0, n - 1, 0, p, a) + (ll)b <= Suma - (p == 0 ? 0LL : s[p - 1])){
                    Mejor = p;
                    i = p + 1;
                    Bien = 1;
                } else d = p - 1;
            }
            ll Consultita = _rbol.Consulta(0, n - 1, 0, Mejor, a) + (ll)b, Debe_haber = Suma - (Mejor == 0 ? 0LL : s[Mejor - 1]);
            if(Consultita == Debe_haber or !Bien){
                _rbol.Llenar(0, n - 1, 0, Mejor, a);
            } else {
                Mejor++;
                Debe_haber = Suma - (Mejor == 0 ? 0LL : s[Mejor - 1]) - _rbol.Consulta(0, n - 1, 0, Mejor, a);
                _rbol.Llenar(0, n - 1, 0, Mejor, a);
                Mejor--;
                _rbol.Sumar(0, n - 1, 0, Mejor, Mejor, b - Debe_haber);
            }
            continue;
        }
        b--;
        cout<<_rbol.Consulta(0, n - 1, 0, a, b)<<el;
        _rbol.Cerear(0, n - 1, 0, a, b);
    }
    return 0;
}