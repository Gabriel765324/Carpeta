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
void Resolver(){
    int n;
    cin>>n;
    unsigned ll Llevo = 0, Temporal;
    vector<unsigned ll> a(n);
    bitset<122> Usados;
    forn(i, n){
        cin>>a[i];
    }
    forn(i, n){
        Temporal = Llevo | a[i];
        int Ganancia = - (int)__popcount(~(~a[i] | Llevo));
        bitset<122> Posible;
        forn(j, n){
            if(Usados[j]) continue;
            if((int)__popcount(~(~a[j] | Temporal)) == 0){
                Posible[j] = 1;
                Ganancia++;
            }
        }
        if(Ganancia >= 0){
            Llevo = Temporal;
            Usados |= Posible;
        }
    }
    cout<<(int)Usados.count() - (int)__popcount(Llevo)<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        Resolver();
    }
    return 0;
}