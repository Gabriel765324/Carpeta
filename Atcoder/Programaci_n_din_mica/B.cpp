#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<long long> a(n, 0), PD(n, LLONG_MAX);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i == 0){
            PD[0] = 0;
            continue;
        }
        for(int j = i - 1; j > -1 and j >= i - k; j--){
            long long Nuevo = abs(a[i] - a[j]) + PD[j];
            PD[i] = min(PD[i], Nuevo);
        }
    }
    cout<<PD.back();
    return 0;
}