#include "bits/stdc++.h"
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define all(v) (v).begin(), (v).end()
using namespace std;
struct Arista{
    int u, v;
    ll p;
    Arista(){
        u = -2;
        v = -2;
        p = -2;
    }
    Arista(int U, int V, ll P){
        u = U;
        v = V;
        p = P;
    }
    bool operator<(const Arista& a){
        return p < a.p;
    }
};
ll m = 998244353;
struct M_dulo{
    ll v;
    M_dulo(){
        v = 1LL;
    }
    M_dulo(ll V){
        v = V % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo((v % m + a.v % m) % m);
    }
    M_dulo operator-(const M_dulo& a){
        return M_dulo(((v % m - a.v % m) % m + m) % m);
    }
    M_dulo operator*(const M_dulo& a){
        return M_dulo((v % m * a.v % m) % m);
    }
    M_dulo operator^(long long e){
        if(e == 0LL) return M_dulo(1LL);
        if(e == 1LL) return M_dulo(v);
        M_dulo a = M_dulo(v) ^ (e / 2LL);
        a = a * a * (M_dulo(v) ^ (e & 1LL));
        return a;
    }
};
vector<int> Representantes;
vector<ll> Tama_o;
M_dulo Respuesta = M_dulo(1LL), s;
int Buscar(int a){
    if(Representantes[a] == a) return a;
    return Representantes[a] = Buscar(Representantes[a]);
}
void Unir(int a, int b, M_dulo Peso){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        Respuesta = Respuesta * ((s - Peso + M_dulo(1)) ^ (Tama_o[a] * Tama_o[b] - 1LL));
        Representantes[b] = a;
        Tama_o[a] += Tama_o[b];
    }
}
void Resolver(){
    int n;
    cin>>n>>s.v;
    Respuesta = M_dulo(1);
    vector<Arista> a(n - 1);
    forn(i, n - 1){
        Representantes.pb(i);
        Tama_o.pb(1);
        cin>>a[i].u>>a[i].v>>a[i].p;
        a[i].u--;
        a[i].v--;
    }
    Representantes.pb(n - 1);
    Tama_o.pb(1);
    sort(all(a));
    forn(i, n - 1){
        Unir(a[i].u, a[i].v, M_dulo(a[i].p));
    }
    cout<<Respuesta.v % m<<"\n";
}
/*
2
2 5
1 2 4
4 5
1 2 2
2 3 4
3 4 3
*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        Resolver();
        Representantes.clear();
        Tama_o.clear();
    }
    return 0;
}