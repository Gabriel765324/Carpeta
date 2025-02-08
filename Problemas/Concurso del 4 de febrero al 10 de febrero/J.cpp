//Mal.
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
        for(long long i = 0; i < n; i++) cin>>a[i];
        if(n == 1){
            cout<<"0\n";
            continue;
        }
        vector< pair< pair<long long, long long>, pair<long long, long long> > > Orden;
        for(long long i = 0; i < n - 1; i++){
            long long m = min(a[i], a[i + 1]);
            if(i == 0){
                a[0] = m + 1;
                a[1] = m;
                Orden.push_back({{i + 1, i + 2}, {m + 1, m}});
            } else {
                a[i] = a[0] + i;
                a[i + 1] = m;
                Orden.push_back({{i + 1, i + 2}, {a[0] + i, m}});
            }
        }
    }
    return 0;
}