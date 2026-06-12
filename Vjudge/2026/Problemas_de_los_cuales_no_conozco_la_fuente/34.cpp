#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define el "\n"
using namespace std;
int Resolver(){
    int n, k, r = 0, c = 0;
    cin>>n>>k;
    vi a(n);
    bitset<222222> Buenos;
    forn(i, n){
        cin>>a[i];
        if(i > 0 and a[i] * 2 > a[i - 1]) Buenos[i - 1] = 1;
    }
    forn(i, k) c += int(Buenos[i]);
    r += int(c == k);
    forsn(i, k, n - 1){
        c += int(Buenos[i]) - int(Buenos[i - k]);
        r += int(c == k);
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) cout<<Resolver()<<el;
    return 0;
}