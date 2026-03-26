#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector< pair<long long, long long> > a(n);
    long long s = 0, m = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
        s += a[i].first;
        m = max(a[i].second - a[i].first, m);
    }
    cout<<s + m;
    return 0;
}