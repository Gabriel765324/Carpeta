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
        long long m = n % 11;
        long long d = n / 11;
        if(m * 10 <= d) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}