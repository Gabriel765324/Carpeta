#include "bits/stdc++.h"
#define mp make_pair
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define F first
#define S second
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
vector<ll> _rbol;
ll Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return -0;
    int P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(int i, int d, int p, int a, long long v){
    if(i == d and i == a){
        _rbol[p] = v;
        return;
    }
    if(i > a or d < a) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, a, v);
    Actualizar(P + 1, d, p * 2 + 1, a, v);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
void Resolver(){
    int n;
    cin>>n;
    vector<ii> a(n);
    set<int> s;
    forn(i, n){
        cin>>a[i].F>>a[i].S;
        s.insert(a[i].F);
        s.insert(a[i].S);
    }
    vi Recta(2 * n);
    int c = 0;
    map<int, int> Mapeo;
    for(auto E: s){
        Mapeo[E] = c;
        //cerr<<E<<" "<<c<<el;
        c++;
    }
    forn(i, n){
        Recta[Mapeo[a[i].F]] = i;
        Recta[Mapeo[a[i].S]] = i;
    }
    /*for(auto E: Recta) cerr<<E<<" ";
    cerr<<el;*/
    vi Primero(n, -2);
    _rbol.assign(n * 8 + 22, 0);
    long long r = 0;
    forn(i, 2 * n){
        if(Primero[Recta[i]] == -2){
            Primero[Recta[i]] = i;
        } else {
            //cerr<<"Consulta."<<el;
            r += Consulta(0, 2 * n - 1, 1, Primero[Recta[i]], i);
            //cerr<<"Consulta hecha."<<el;
            Actualizar(0, 2 * n - 1, 1, Primero[Recta[i]], 1);
            //cerr<<"Consulta hecha 2."<<el;
        }
    }
    cout<<r<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}