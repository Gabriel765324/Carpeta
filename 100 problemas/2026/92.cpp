#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r;
    cin>>n>>l>>r;
    l--;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = i + 1;
    reverse(a.begin() + l, a.begin() + r);
    for(auto E: a) cout<<E<<" ";
    return 0;
}