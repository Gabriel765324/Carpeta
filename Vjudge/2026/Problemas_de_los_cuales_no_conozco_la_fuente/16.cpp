#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define el "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll r1 = 0, r2 = 0;
    vector<ll> a(n), p(n), s(n);
    forn(i, n) cin>>a[i];
    if(n == 1){
        cout<<a[0] * 2LL;
        return 0;
    }
    sort(all(a));
    forn(i, n){
        p[i] = a[i];
        s[i] = a[i];
        if(i > 0) p[i] += p[i - 1];
    }
    for(int i = n - 2; i > -1; i--){
        s[i] += s[i + 1];
    }
    s.push_back(0);
    int i, j = n;
    for(i = 0; i < n; i++){
        if(p[i] > s[i + 1]){
            i--;
            j = i + 1;
            r1 = max(r1, 2LL * max((i > -1 ? p[i] : 0LL), s[j]));
            break;
        }
    }
    for(j = n - 1; j > -1; j--){
        if(s[j] > p[j - 1]){
            j++;
            i = j - 1;
            r2 = max(r2, 2LL * max(p[i], s[j]));
            break;
        }
    }
    cout<<min(r1, r2);
    return 0;
}