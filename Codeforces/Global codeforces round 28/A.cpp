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
        cout<<(n % 33 == 0 ? "YES\n" : "NO\n");
    }
    return 0;
}