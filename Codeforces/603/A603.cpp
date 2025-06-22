#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        vector<long long> a(3);
        cin>>a[0]>>a[1]>>a[2];
        long long r = 0;
        sort(a.begin(), a.end());
        if((a[2] - a[1]) > a[0]){
            a[2] -= a[0];
            r += a[0] + min(a[2], a[1]);
        } else {
            r += a[2] - a[1];
            a[0] -= a[2] - a[1];
            long long _2 = a[0] / 2;
            a[2] -= _2;
            r += _2;
            a[1] -= a[0] - _2;
            r += a[0] - _2 + min(a[2], a[1]);
        }
        cout<<r<<"\n";
    }
    return 0;
}