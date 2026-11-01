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
bool Orden1(const ii& a, const ii& b){
    if(a.F + a.S < b.F + b.S) return 1;
    if(a.F + a.S > b.F + b.S) return 0;
    return a.F < b.F;
}
bool Orden2(const ii& a, const ii& b){
    if(a.F - a.S < b.F - b.S) return 1;
    if(a.F - a.S > b.F - b.S) return 0;
    return a.F < b.F;
}
ll Distancia(ii a, ii b){
    return abs(a.F - b.F) + abs(a.S - b.S);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector< ii > Mal(n), Bien(m), Emparejado(n);
    forn(i, n){
        cin>>Mal[i].F>>Mal[i].S;
        Emparejado[i].F = Emparejado[i].S = -2222222222222222LL;
    }
    forn(i, m){
        cin>>Bien[i].F>>Bien[i].S;
    }
    const int Revisar = 4;
    sort(all(Bien), Orden1);
    forn(i, n){
        int E = lower_bound(all(Bien), Mal[i], Orden1) - Bien.begin(), r = E + Revisar;
        for(E -= Revisar; E < r; E++){
            if(E > -1 and E < m and Distancia(Mal[i], Bien[E]) < Distancia(Mal[i], Emparejado[i])) Emparejado[i] = Bien[E];
        }
    }
    sort(all(Bien), Orden2);
    forn(i, n){
        int E = lower_bound(all(Bien), Mal[i], Orden2) - Bien.begin(), r = E + Revisar;
        for(E -= Revisar; E < r; E++){
            if(E > -1 and E < m and Distancia(Mal[i], Bien[E]) < Distancia(Mal[i], Emparejado[i])) Emparejado[i] = Bien[E];
        }
    }
    ll s = 0LL;
    forn(i, n) s += Distancia(Mal[i], Emparejado[i]);
    cout<<s<<el;
    return 0;
}