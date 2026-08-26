#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    vector<int> r;
    cin>>n>>m>>k;
    vector<int> p(n, 0);
    while(k--){
        int a, b;
        cin>>a>>b;
        p[a - 1]++;
        if(p[a - 1] == m) r.push_back(a);
    }
    for(auto E: r) cout<<E<<" ";
    return 0;
}