#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m = 998244353;
    cin>>n;
    vector<int> Previos(1e5 + 2, 0), PD(n + 1, 1);
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        PD[i + 1] = (PD[i] % m + Previos[a] % m) % m;
        Previos[a] = PD[i + 1];
    }
    cout<<PD.back();
    return 0;
}