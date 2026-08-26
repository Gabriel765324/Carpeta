#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<long long> a(n + 2, 0), PD(n + 2, 0);
    for(int i = 2; i < n + 2; i++){
        cin>>a[i];
        if(i == 2){
            a[0] = a[2];
            a[1] = a[2];
        }
        PD[i] = min(abs(a[i] - a[i - 1]) + PD[i - 1], abs(a[i] - a[i - 2]) + PD[i - 2]);
    }
    cout<<PD.back();
    return 0;
}