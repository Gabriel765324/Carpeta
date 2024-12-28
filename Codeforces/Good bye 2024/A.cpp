#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, s = 0;
        cin>>n;
        vector<long long> a(n);
        for(long long i = 0; i < n; i++){
            cin>>a[i];
        }
        bool Bien = 1;
        for(long long i = 0; i < n - 1; i++){
            long long M = max(a[i], a[i + 1]), m = min(a[i], a[i + 1]);
            if(2 * m > M){
                cout<<"YES\n";
                Bien = 0;
                break;
            }
        }
        if(Bien) cout<<"NO\n";
    }
    return 0;
}