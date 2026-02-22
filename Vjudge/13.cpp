#include "bits/stdc++.h"
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define mp make_pair
#define F first
//#define S second
#define vi vector<int>
#define ii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define ll long long
#define pb push_back
using namespace std;
ll m = 1e9 + 7;
vector<ll> Factoriales(1e6 + 22);
ll S(ll a, ll b){
    return (a % m + b % m) % m;
}
ll M(ll a, ll b){
    return (a % m * b % m) % m;
}
ll P(ll b, ll e){
    if(e == 0) return 1;
    if(e == 1) return b % m;
    ll a = P(b, e / 2);
    a = M(a, a);
    a = M(a, P(b, e % 2));
    return a % m;
}
ll D(ll a, ll b){
    return M(a, P(b, m - 2LL)) % m;
}
ll a, b;
bool Verificar(ll n){
    string v;
    stringstream c;
    c<<n;
    c>>v;
    for(auto E: v) if((E - '0') != a and (E - '0') != b) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>a>>b>>n;
    Factoriales[0] = 1;
    Factoriales[1] = 1;
    forsn(i, 2, Factoriales.size()){
        Factoriales[i] = M(i, Factoriales[i - 1]);
    }
    ll r = 0;
    //cerr<<Verificar(111113333);
    for(ll i = 0; i <= n; i++){
        if(Verificar(a * i + b * (n - i))){
            r = S(r, D(Factoriales[n], M(Factoriales[i], Factoriales[n - i])));
            /*cerr<<i<<" "<<D(Factoriales[n], M(Factoriales[i], Factoriales[n - i]))<<el;
            cerr<<Factoriales[n]<<" "<<Factoriales[i]<<" "*/
        }
    }
    cout<<r % m;
    return 0;
}