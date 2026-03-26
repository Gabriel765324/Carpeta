#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long a, b, c;
        cin>>a>>b>>c;
        long long i = 0, d = 222222222222, m = 0;
        while(1){
            long long p = (i + d) / 2LL;
            if(p <= a and p <= c and a + b + c >= p * 3LL){
                i = p + 1LL;
                m = p;
            } else d = p - 1LL;
            if(i >= d + 1LL) break;
        }
        cout<<m<<"\n";
    }
    return 0;
}