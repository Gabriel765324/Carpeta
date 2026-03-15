#include "bits/stdc++.h"
using namespace std;
int n;
vector<long long> a;
vector< vector< vector<long long> > > PD;
long long Resolver(long long i, long long j, bool k){
    if(j < i) return 0;
    if(PD[i][j][k] != -2222222222222222) return PD[i][j][k];
    if(k == 0){
        return PD[i][j][k] = max(Resolver(i + 1, j, !k) + a[i], Resolver(i, j - 1, !k) + a[j]);
    } else {
        return PD[i][j][k] = min(Resolver(i + 1, j, !k) - a[i], Resolver(i, j - 1, !k) - a[j]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    a.assign(n, 0);
    PD.assign(n + 2, vector< vector<long long> >(n + 2, vector<long long>(2, -2222222222222222)));
    for(int i = 0; i < n; i++) cin>>a[i];
    cout<<Resolver(0, n - 1, 0);
    return 0;
}