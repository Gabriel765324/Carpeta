#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r = 0;
    cin>>n;
    vector< pair<long long, long long> > q(n);
    vector<long long> m;
    for(int i = 0; i < n; i++){
        cin>>q[i].first>>q[i].second;
        q[i].first *= 2LL;
        q[i].second *= 2LL;
        m.push_back((q[i].first + q[i].second) / 2LL);
        for(int j = 0; j < i; j++){
            if(q[i].first <= m[j] and m[j] <= q[i].second and q[j].first <= m.back() and m.back() <= q[j].second) r++;
        }
    }
    cout<<r;
    return 0;
}