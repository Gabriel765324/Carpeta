#include "bits/stdc++.h"
#define vi vector<int>
#define ii pair<int, int>
#define ll long long
#define el "\n"
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define di deque<int>
#define pf push_front
#define mp make_pair
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n, i = 0, d = 4444, Capa = 4444, Respuesta = 0LL;
        cin>>n;
        while(i < d + 1LL){
            ll p = (i + d) / 2LL;
            if(p * (p + 1LL) / 2LL >= n){
                Capa = p;
                d = p - 1LL;
            } else {
                i = p + 1LL;
            }
        }
        ll Inicio = (Capa - 1LL) * Capa / 2LL + 1LL, Final = (Capa + 1LL) * Capa / 2LL;
        ll Izquierda = n, Derecha = n;
        while(Capa > 0LL){
            Izquierda--;
            Respuesta += Derecha * (Derecha + 1LL) * (2LL * Derecha + 1LL) / 6LL;
            Respuesta -= Izquierda * (Izquierda + 1LL) * (2LL * Izquierda + 1LL) / 6LL;
            Izquierda++;
            Capa--;
            Izquierda -= Capa + 1LL;
            Derecha -= Capa;
            Final = (Capa + 1LL) * Capa / 2LL;
            Inicio = (Capa - 1LL) * Capa / 2LL + 1LL;
            Izquierda = max(Izquierda, Inicio);
            Derecha = min(Derecha, Final);
        }
        cout<<Respuesta<<el;
    }
    return 0;
}