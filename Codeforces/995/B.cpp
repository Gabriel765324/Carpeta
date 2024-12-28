#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, a, b, c, i = 0, d = 1e9, m = 0;
        cin>>n>>a>>b>>c;
        long long s = a + b + c;
        while(1){
            long long p = (i + d) / 2;
            if(s * p < n){
                i = p + 1;
                m = p;
            } else d = p - 1;
            if(i >= d + 1) break;
        }
        n -= s * m;
        m *= 3;
        if(a >= n) cout<<m + 1;
        else if(a + b >= n) cout<<m + 2;
        else cout<<m + 3;
        cout<<"\n";
    }
    return 0;
}