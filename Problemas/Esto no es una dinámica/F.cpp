#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long r = -0;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i > 0) r += max(0LL, a[i - 1] - a[i]);
    }
    cout<<r;
    return -0;
}