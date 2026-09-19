#include "bits/stdc++.h"
#define ll long long
#define mp make_pair
#define ii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
ll m = 998244353LL;
struct Modular{
    ll v;
    Modular(){
        v = 0LL;
    }
    Modular(ll a){
        v = (a + m) % m;
    }
    Modular operator+(const Modular& o){
        return Modular(v % m + o.v % m);
    }
    Modular operator-(const Modular& o){
        return Modular(v % m - o.v % m);
    }
    Modular operator*(const Modular& o){
        return Modular(v % m * o.v % m);
    }
    Modular operator^(const ll& e){
        if(e == 0LL) return Modular(1LL);
        if(e == 1LL) return Modular(v);
        Modular a = *this ^ (e >> 1LL);
        a = a * a * (*this ^ (e & 1LL));
        return a;
    }
    Modular operator/(const Modular& o){
        Modular Apoyo = o;
        return *this * (Apoyo ^ (m - 2LL));
    }
    bool operator<(const Modular& o){
        return v < o.v;
    }
    bool operator<=(const Modular& o){
        return v <= o.v;
    }
    bool operator>(const Modular& o){
        return v > o.v;
    }
    bool operator>=(const Modular& o){
        return v >= o.v;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, nn;
    cin>>n>>nn;
    vector<Modular> a(n), Suma(n);
    forn(i, n){
        cin>>a[i].v;
        a[i].v %= m;
    }
    sort(all(a));
    for(int i = n - 1; i > -1; i--){
        Suma[i] = a[i];
        if(i < n - 1) Suma[i] = Suma[i] + Suma[i + 1];
    }
    while(nn--){
        Modular A, B;
        cin>>A.v>>B.v;
        B.v %= m;
        int _ndice = lower_bound(all(a), B.v) - a.begin();
        Modular R = Modular((ll)(n - _ndice));
        Modular _0, _1;
        if(A >= R) _0 = Modular(0LL);
        else _0 = ((R - A) / R) * Suma[_ndice];
        if(A >= R + Modular(1LL)) _1 = Modular(0LL);
        else _1 = ((R + Modular(1LL) - A) / (R + Modular(1LL))) * (Suma[0] - Suma[_ndice]);
        cout<<(_0 + _1).v<<el;
    }
    return 0;
}