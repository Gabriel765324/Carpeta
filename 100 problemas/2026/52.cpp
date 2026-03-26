#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m = 0, r = 0;
    cin>>n;
    vector<long long> a(n), v1(n, 0), v2(n, 0);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        m = max(m, a[i]);
        if(i + a[i] < n){
            r += v1[i + a[i]];
            v2[i + a[i]]++;
        }
        if(i - a[i] > -1){
            r += v2[i - a[i]];
            v1[i - a[i]]++;
        }
    }
    cout<<r;
    return 0;
}