#include "bits/stdc++.h"
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define el "\n"
#define vi vector<int>
using namespace std;
struct M_dulo{
    long long v, m;
    M_dulo(long long V){
        m = 1000000007;
        v = (V + m) % m;
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
    M_dulo operator^(const long long& e){
        if(e == 0) return M_dulo(1);
        if(e == 1) return M_dulo(v);
        M_dulo a = M_dulo(v) ^ (e / 2LL);
        a = a * a * (M_dulo(v) ^ (e % 2LL));
        return a;
    }
    M_dulo operator/(const M_dulo& a){
        M_dulo b = a;
        return M_dulo((v % m * (b ^ (m - 2LL)).v % m) % m);
    }
};
vector<M_dulo> Factorial;
M_dulo nCk(int a, int b){
    return Factorial[a] / (Factorial[b] * Factorial[a - b]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Factorial.pb(M_dulo(1));
    Factorial.pb(M_dulo(1));
    forsn(i, 2, 222222) Factorial.pb(M_dulo(i) * Factorial.back());
    int n;
    cin>>n;
    M_dulo r = M_dulo(0);
    forn(i, n) r = r + nCk(n - 1 + i, i);
    r = M_dulo(2) * r - M_dulo(n);
    cout<<r.v;
    return 0;
}