#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        n *= 2;
        vector<long long> a(n);
        for(long long i = 0; i < n; i++) cin>>a[i];
        sort(a.begin(), a.end());
        long long r = 2222222222222222;
        for(long long i = 0; i < n; i++){
            long long j = n / 2;
            if(i >= j) j--;
            r = min(r, abs(a[i] - a[j]));
        }
        cout<<r<<"\n";
    }
    return 0;
}