#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp make_pair
#define ii pair<long long, long long>
#define F first
#define S second
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define ld long double
#define di deque<int>
#define vi vector<int>
#define pf push_front
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define el "\n"
using namespace std;
int n, q;
vector<ll> a, x;
vector< vi > Grafo;
bool Imposible = 0;
ll Resolver(int Nodo, int Padre){
    //cerr<<Nodo + 1<<".\n";
    if(Imposible) return -1LL;
    ll Mayor = -2LL, Respuesta = 0LL;
    for(auto E: Grafo[Nodo]){
        if(E == Padre) continue;
        Respuesta += Resolver(E, Nodo);
        Mayor = max(Mayor, a[E]);
    }
    if(Imposible) return -1LL;
    if(Mayor <= a[Nodo]){
        //cerr<<Nodo + 1<<" Bien.\n";
        return a[Nodo] + Respuesta;
    }
    int i = 0, d = int(x.size()) - 1, m = int(x.size());
    while(i < d + 1){
        int p = (i + d) / 2;
        if(a[Nodo] + x[p] >= Mayor){
            m = p;
            d = p - 1;
        } else i = p + 1;
    }
    if(m == int(x.size())){
        //cerr<<Nodo + 1<<" Imposible.\n";
        //cerr<<a[Nodo]<<" "<<Mayor<<".\n";
        Imposible = 1;
        return -1LL;
    }
    a[Nodo] += x[m];
    //cerr<<Nodo + 1<<" "<<a[Nodo]<<".\n";
    return Respuesta + a[Nodo];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    a.assign(n, 0);
    x.assign(q, 0);
    Grafo.assign(n, {});
    forn(i, n) cin>>a[i];
    forn(i, n - 1){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].pb(b);
        Grafo[b].pb(a);
    }
    forn(i, q) cin>>x[i];
    bitset<1000001> Posibles;
    Posibles[0] = 1;
    forn(i, q){
        Posibles |= Posibles<<x[i];
    }
    x.clear();
    forn(i, 1000001){
        if(Posibles[i]) x.pb(i);
    }
    /*for(auto E: x) cerr<<E<<" ";
    cerr<<el;*/
    ll Nada = Resolver(0, 0);
    if(Imposible) cout<<"-1\n";
    else cout<<Nada<<el;
    return 0;
}