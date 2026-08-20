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
struct Arista{
    int v;
    ll d;
    Arista(){}
    Arista(int b, ll c){
        v = b;
        d = c;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    vector< vector<Arista> > Grafo(n);
    while(m--){
        int a, b;
        ll c;
        cin>>a>>b>>c;
        a--;
        b--;
        Grafo[a].pb(Arista(b, c));
        Grafo[b].pb(Arista(a, c));
    }
    vector<ll> Tiempo(n, LLONG_MAX);
    priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > Cola;
    while(k--){
        int a;
        cin>>a;
        a--;
        Cola.push(mp(0LL, a));
        Tiempo[a] = 0LL;
    }
    //cerr<<Cola.size()<<"\n";
    while(!Cola.empty()){
        ll d = Cola.top().first;
        int Nodo = Cola.top().second;
        Cola.pop();
        if(d > Tiempo[Nodo]) continue;
        for(auto E: Grafo[Nodo]){
            //cerr<<Nodo<<" "<<E.v<<"\n";
            if(d + E.d * 2LL >= Tiempo[E.v]) continue;
            Tiempo[E.v] = d + E.d * 2LL;
            Cola.push(mp(d + E.d * 2LL, E.v));
        }
    }
    for(auto E: Tiempo) cerr<<E<<" ";
    cerr<<"\n";
    ll i = -22222222222, d = 0, Mejor = i;
    vector<ll> Tiempo_(n, LLONG_MAX);
    while(i < d + 1LL){
        ll p = (i + d) / 2LL;
        fill(all(Tiempo_), LLONG_MAX);
        Tiempo_[0] = p;
        Cola.push(mp(p, 0));
        while(!Cola.empty()){
            ll d = Cola.top().first;
            int Nodo = Cola.top().second;
            Cola.pop();
            if(d > Tiempo_[Nodo]) continue;
            for(auto E: Grafo[Nodo]){
                if(d + E.d >= Tiempo_[E.v] or d + E.d >= Tiempo[E.v]) continue;
                Tiempo_[E.v] = d + E.d;
                Cola.push(mp(d + E.d, E.v));
            }
        }
        if(Tiempo_.back() < LLONG_MAX){
            Mejor = p;
            i = p + 1;
        } else d = p - 1;
    }
    cout<<max(-Mejor - 1LL, 0LL)<<"\n";
    return 0;
}