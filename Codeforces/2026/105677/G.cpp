#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long r, i = 0, d;
    int n;
    cin>>r>>n;
    d = r;
    while(n--){
        long long a;
        cin>>a;
        i += a;
        d += a;
        i = min(i, r);
        i = max(0LL, i);
        d = min(d, r);
        d = max(0LL, d);
    }
    if(i == d) cout<<i<<"\n";
    else cout<<"uncertain\n";
    return 0;
}