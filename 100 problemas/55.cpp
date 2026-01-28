#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, q;
    cin>>n>>q;
    vector<long long> a(n), s(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        s[i] = a[i];
        if(i > 0) s[i] += s[i - 1];
    }
    while(q--){
        long long d;
        cin>>d;
        if(d > a.back()){
            cout<<"-1\n";
            continue;
        }
        long long p = lower_bound(a.begin(), a.end(), d) - a.begin();
        cout<<(p > 0 ? s[p - 1] : -0LL) + (d - 1LL) * (n - p - 1LL) + d<<"\n";
    }
    return 0;
}