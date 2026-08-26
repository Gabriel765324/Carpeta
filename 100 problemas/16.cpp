#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long r = 0, s = 0;
    cin>>n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        s += a[i];
    }
    for(int i = 0; i < n; i++){
        s -= a[i];
        r += s * a[i];
    }
    cout<<r;
    return 0;
}