#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define pb push_back
#define pf push_front 
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
struct Comida{
    int x;
    ll v;
    Comida(){}
};
int Obtener(int i, vector<ll>& c){
    return lower_bound(all(c), i) - c.begin();
}
vector<ll> _rbol;
int t(int i, int d){
    return 2 * (d - i + 1);
}
void Crear(int i, int d, int p, vector<ll>& a){
    if(i == d){
        _rbol[p] = a[i];
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p + 1, a);
    Crear(P + 1, d, p + t(i, P), a);
    _rbol[p] = max(_rbol[p + 1], _rbol[p + t(i, P)]);
}
ll Consulta(int i, int d, int p, int I, int D){
    if(I <= i and d <= D) return _rbol[p];
    if(d < I or D < i) return -2LL;
    int P = (i + d) / 2;
    return max(Consulta(i, P, p + 1, I, D), Consulta(P + 1, d, p + t(i, P), I, D));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll d;
    cin>>n>>d;
    vector<ll> Coordenadas0, Coordenadas;
    vector<Comida> a(n);
    forn(i, n){
        cin>>a[i].x>>a[i].v;
        Coordenadas0.push_back(a[i].x);
        Coordenadas0.push_back(a[i].x - d);
        Coordenadas0.push_back(a[i].x + d);
        Coordenadas0.push_back(a[i].x + 1);
    }
    sort(all(Coordenadas0));
    Coordenadas.pb(Coordenadas0[0]);
    int m = int(Coordenadas0.size());
    forsn(i, 1, m){
        if(Coordenadas0[i] == Coordenadas0[i - 1]) continue;
        Coordenadas.pb(Coordenadas0[i]);
    }
    m = int(Coordenadas.size());
    vector<ll> Valores0(m, 0LL), Valores1 = Valores0, Suma = Valores0;
    forn(i, n){
        Suma[Obtener(a[i].x, Coordenadas)] += a[i].v;
    }
    forsn(i, 1, m){
        Suma[i] += Suma[i - 1];
    }
    forn(i, n){
        int p = Obtener(a[i].x, Coordenadas), s = Obtener(a[i].x + d, Coordenadas);
        Valores0[p] = Suma[s];
        if(p > 0) Valores0[p] -= Suma[p - 1];
        s = Obtener(a[i].x - d, Coordenadas);
        Valores1[p] = Suma[p];
        if(s > 0) Valores1[p] -= Suma[s - 1];
    }
    _rbol.assign(2 * m + 22, 0LL);
    Crear(0, m - 1, 0, Valores0);
    ll Respuesta = 0LL;
    forn(i, n){
        int p = Obtener(a[i].x, Coordenadas);
        Respuesta = max(Respuesta, Valores1[p] + Consulta(0, m - 1, 0, Obtener(a[i].x + 1, Coordenadas), m - 1));
    }
    cout<<Respuesta<<"\n";
    return 0;
}