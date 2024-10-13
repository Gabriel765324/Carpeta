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
        vector<long long> a(n);
        for(long long i = 0; i < n; i++){
            a[i] = i + 2;
            if(i == (n - 1)) a[i] = 1;
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}