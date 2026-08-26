#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
struct M_dulo{
    long long v, m;
    M_dulo(){
        v = 0LL;
        m = (ll)1e9 + 7LL;
    }
    M_dulo(ll a, ll b){
        m = b;
        v = (a + m) % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo((v % m + a.v % m) % m, m);
    }
    M_dulo operator*(const M_dulo& a){
        return M_dulo((v % m * a.v % m) % m, m);
    }
    bool operator==(const M_dulo& a){
        return ((v % m) == (a.v % a.m)) and (m == a.m);
    }
};
struct Hash{
    M_dulo v0, v1;
    Hash(){
        v0 = M_dulo(0LL, (ll)1e9 + 7LL);
        v1 = M_dulo(0LL, (ll)1e9 + 9LL);
    }
    Hash(ll a, ll b){
        v0 = M_dulo(a, (ll)1e9 + 7LL);
        v1 = M_dulo(b, (ll)1e9 + 9LL);
    }
    Hash(M_dulo a, M_dulo b){
        v0 = a;
        v1 = b;
    }
    Hash operator+(const Hash& b){
        return Hash(v0 + b.v0, v1 + b.v1);
    }
    Hash operator*(const Hash& b){
        return Hash(v0 * b.v0, v1 * b.v1);
    }
    bool operator==(const Hash& b){
        return v0 == b.v0 and v1 == b.v1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<M_dulo> Potencia0, Potencia1;
    Potencia0.pb(M_dulo(1LL, (ll)1e9 + 7LL));
    Potencia1.pb(M_dulo(1LL, (ll)1e9 + 9LL));
    forn(i, 222222){
        Potencia0.pb(Potencia0.back() * M_dulo(31LL, (ll)1e9 + 7LL));
        Potencia1.pb(Potencia1.back() * M_dulo(37LL, (ll)1e9 + 9LL));
    }
    while(cin>>s){
        int n = int(s.size()), m = 1, c = 1;
        Hash Normal, Inverso;
        for(int i = n - 1; i > -1; i--){
            Normal = Normal + (Hash((ll)(s[i] - 'a') + 1LL, (ll)(s[i] - 'a') + 1LL) * Hash(Potencia0[c - 1], Potencia1[c - 1]));
            Inverso = (Inverso * Hash(31LL, 37LL)) + Hash((ll)(s[i] - 'a') + 1LL, (ll)(s[i] - 'a') + 1LL);
            if(Normal == Inverso) m = c;
            c++;
        }
        for(int i = n - m - 1; i > -1; i--) s += s[i];
        cout<<s<<el;
    }
    return 0;
}