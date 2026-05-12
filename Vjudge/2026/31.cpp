#include "bits/stdc++.h"
#define ii pair<int, int>
#define vi vector<int>
#define ll long long
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < n; i++)
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define all(v) (v).beign(), (v).end()
#define di deque<int>
#define pf push_front
using namespace std;
const ll m0 = /*999999797*/999999677, m1 = 31/*999999677, m2 = 999999527, m3 = 999999433*/;
ll Potencia(ll b, ll e){
    if(e == 0LL) return 1LL;
    if(e == 1LL) return b % m0;
    ll a = Potencia(b, e>>1LL) % m0;
    a = (a % m0 * a % m0) % m0;
    a = (a % m0 * Potencia(b, e & 1LL) % m0) % m0;
    return a % m0;
}
ll Sumar(ll a, ll b){
    return (a % m0 + b % m0) % m0;
}
ll Restar(ll a, ll b){
    return ((a % m0 - b % m0) % m0 + m0) % m0;
}
ll Multiplicar(ll a, ll b){
    return (a % m0 * b % m0) % m0;
}
vector<ll> Potencias;
ll Dividir(ll a, ll b){
    return Multiplicar(a, Potencias[b]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, Malos;
    int k, n, r = 0;
    cin>>s>>Malos>>k;
    n = int(s.size());
    vector<int> Prefijos(n, 0), Hash(n, 0);
    ll Numerito = 1;
    forn(i, n){
        Prefijos[i] = (Malos[s[i] - 'a'] == '0' ? 1 : 0);
        Hash[i] = Multiplicar(s[i] - 'a', Numerito);
        if(i > 0){
            Prefijos[i] += Prefijos[i - 1];
            Hash[i] = Sumar(Hash[i - 1], Hash[i]);
        }
        Potencias.push_back(Potencia(Numerito, m0 - 2LL));
        Numerito = Multiplicar(Numerito, m1);
    }
    vector< set<ll> > Usados(n + 1);
    forn(i, n){
        forsn(j, i, n){
            ll Hash_actual = Hash[j], Malos_actual = Prefijos[j];
            if(i > 0){
                Hash_actual = Restar(Hash_actual, Hash[i - 1]);
                Hash_actual = Dividir(Hash_actual, i);
                Malos_actual -= Prefijos[i - 1];
            }
            if(Malos_actual <= k and Usados[j - i + 1].find(Hash_actual) == Usados[j - i + 1].end()){
                Usados[j - i + 1].insert(Hash_actual);
                r++;
            }
        }
    }
    cout<<r;
    return 0;
}