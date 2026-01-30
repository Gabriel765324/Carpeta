#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long Mx = 0, mx = 1e9 + 2, My = 0, my = 1e9 + 2, r = 0;
    vector< pair<long long, long long> > a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
        Mx = max(Mx, a[i].first);
        mx = min(mx, a[i].first);
        My = max(My, a[i].second);
        my = min(my, a[i].second);
    }
    long long x = (mx + Mx) / 2, y = (my + My) / 2;
    for(auto E: a){
        r = max(r, max(abs(E.first - x), abs(E.second - y)));
    }
    cout<<r;
    return 0;
}