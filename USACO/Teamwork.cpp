#include "bits/stdc++.h"
using namespace std;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    long long n, k;
    cin>>n>>k;
    deque<long long> a(n), PD(n);
    for(long long i = 0; i < n; i++){
        cin>>a[i];
    }
    for(long long i = 0; i < n; i++){
        long long c = k, m = a[i];
        PD[i] = a[i];
        for(long long j = i; j > -1 and c > 0; j--){
            c--;
            m = max(m, a[j]);
            if(j > 0) PD[i] = max(PD[i], m * (i - j + 1) + PD[j - 1]);
            else PD[i] = max(PD[i], m * (i - j + 1));
        }
        //cout<<PD[i]<<" ";
    }
    cout<<PD.back();
    fclose(stdout);
    return 0;
}