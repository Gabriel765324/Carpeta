#include "bits/stdc++.h"
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define mp make_pair
#define F first
#define S second
#define ii pair<int, int>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define el "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r, x, Respuesta = 0;
    cin>>n>>l>>r>>x;
    vector<int> a(n);
    forn(i, n) cin>>a[i];
    forsn(i, 1, (1<<n)){
        int Mayor = -0, Menor = 1e6 + 2, Suma = 0, c = 0;
        forn(j, n){
            if((1<<j) & i){
                Suma += a[j];
                Mayor = max(Mayor, a[j]);
                Menor = min(Menor, a[j]);
                c++;
            }
        }
        if(Suma >= l and Suma <= r and c >= 2 and Mayor - Menor >= x) Respuesta++;
    }
    cout<<Respuesta;
    return 0;
}