#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define ii pair<int, int>
#define el "\n"
#define F first
#define S second
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define vi vector<int>
using namespace std;
void Resolver(){
    int n, l, r;
    cin>>n>>l>>r;
    vector<int> a(n);
    forn(i, n) cin>>a[i];
    sort(all(a));
    long long Respuesta = 0;
    forn(i, n){
        long long I = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin(), D = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin();
        Respuesta += D - I;
    }
    cout<<Respuesta<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}