#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    string s;
    cin>>n>>q>>s;
    vector<long long> Suma(n, 0);
    for(int i = 0; i < n; i++){
        Suma[i] = (s[i] == '8' ? 1LL : 0LL);
        if(i > 0) Suma[i] += Suma[i - 1];
    }
    while(q--){
        long long l, r, x, y;
        cin>>l>>r>>x>>y;
        l--;
        r--;
        x = abs(x);
        y = abs(y);
        long long d = Suma[r], t = r - l + 1LL;
        if(l > 0) d -= Suma[l - 1];
        //cerr<<d<<"\n";
        t -= d;
        long long Restable = min(x, y);
        if(Restable >= d){
            x -= d;
            y -= d;
        } else {
            x -= Restable;
            y -= Restable;
            d -= Restable;
            t += d;
        }
        if(x + y <= t) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}