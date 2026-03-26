#include "bits/stdc++.h"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i< int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define el "\n"
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
    FastIO;
    int k, n;
    cin>>k;
    vector<ll> a(k), Suma(k, 0);
    forn(i, k) cin>>a[i];
    cin>>n;
    vector< vector<ll> > Clientes(n, vector<ll>(k));
    forn(i, n){
        forn(j, k){
            cin>>Clientes[i][j];
            Suma[j] += Clientes[i][j];
        }
    }
    ll Menor = LLONG_MAX;
    forn(i, k){
        if(Suma[i] != 0LL) Menor = min(Menor, a[i] / Suma[i]);
    }
    cout<<Menor + 1<<" ";
    forn(i, k){
        a[i] -= Menor * Suma[i];
    }
    forn(i, n){
        forn(j, k){
            a[j] -= Clientes[i][j];
            if(a[j] < 0LL){
                cout<<i + 1<<el;
                return 0;
            }
        }
    }
    return 0;
}