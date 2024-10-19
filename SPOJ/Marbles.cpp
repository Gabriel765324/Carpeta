#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        long long i = n - 1, r = 1;
        for(long long j = 1; j <= min(k - 1, n - k); j++){
            r = r * i / j;
            i--;
        }
        cout<<r<<"\n";
    }
    return 0;
}