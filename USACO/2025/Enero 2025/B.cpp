#include "bits/stdc++.h"
using namespace std;
long long Resta(long long a, long long b, long long m){
    return ((a % m - b % m) % m + m) % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        vector<long long> a(n);
        for(long long i = 0; i < n; i++){
            cin>>a[i];
            a[i] = a[i] % m;
            long long _1 = m - a[i], _2 = a[i];
            if(_1 < _2) cout<<-_1<<" ";
            else cout<<_2<<" ";
        }
        
        if(t >= 1) cout<<"\n";
    }
    return 0;
}