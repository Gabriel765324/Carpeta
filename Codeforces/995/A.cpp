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
        vector<long long> a(n), b(n);
        for(long long i = 0; i < n; i++){
            cin>>a[i];
        }
        for(long long i = 0; i < n; i++){
            cin>>b[i];
        }
        long long r = a.back();
        for(long long i = 0; i < n - 1; i++){
            if(a[i] - b[i + 1] > 0) r += a[i] - b[i + 1];
        }
        cout<<r<<"\n";
    }
    return 0;
}