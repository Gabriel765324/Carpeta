#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int i, d;
    for(i = n / 2; i > 1; i--){
        if(__gcd(n, i) == 1) break;
    }
    for(d = n / 2 + 1; d < n; d++){
        if(__gcd(n, d) == 1) break;
    }
    n -= d;
    if(i >= n) cout<<i<<"\n";
    else cout<<d<<"\n";
    return 0;
}