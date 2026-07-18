#include "bits/stdc++.h"
#define forn(i, n) for(long long i = 0; i < long long(n); i++)
#define forsn(i, s, n) for(long long i = long long(s); i < long long(n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long 
#define vi vector<long long>
#define ii pair<long long, long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
ll Potenciar(ll b, int e){
    if(e == 0) return 1LL;
    if(e == 1) return b;
    ll a = Potenciar(b, e>>1);
    a = a * a * Potenciar(b, e & 1);
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mt19937 Aleatorio(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<long long> Aleatorizador(1, 222222), Peque_o(1, 6);
    string s;
    long long a;
    while(a = Aleatorizador(Aleatorio)){
        long long ca = a;
        bool Fin = 1;
        while(ca > 0){
            Fin = Fin and ((ca % 10LL) != 1LL) and ((ca % 10LL) != 0LL);
            ca /= 10LL;
        }
        if(Fin) break;
    }
    stringstream c;
    c<<a;
    c>>s;
    long long b = 0LL, Diez = Potenciar(10LL, int(s.size()) - 1), cDiez = Diez;
    while(1){
        b = 0LL;
        Diez = cDiez;
        for(auto E: s){
            b += Potenciar((long long)(E - '0'), Peque_o(Aleatorio)) * Diez;
            Diez /= 10LL;
        }
        if(b <= (long long)INT_MAX) break;
    }
    cout<<s<<" "<<b<<"\n";
    return 0;
}