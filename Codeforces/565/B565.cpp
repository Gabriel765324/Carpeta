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
        map<long long, long long> a;
        for(long long i = 0; i < n; i++){
            long long aa;
            cin>>aa;
            a[aa % 3]++;
        }
        long long _1 = a[1], _2 = a[2];
        long long m = min(_1, _2);
        a[0] += m;
        _1 -= m;
        _2 -= m;
        a[0] += _1 / 3 + _2 / 3;
        cout<<a[0]<<"\n";
    }
    return 0;
}