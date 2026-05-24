#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n;
    vector<long long> Suma(n);
    for(int i = 0; i < n; i++){
        cin>>Suma[i];
        if(i > 0) Suma[i] += Suma[i - 1];
    }
    cin>>q;
    while(q--){
        long long v;
        cin>>v;
        cout<<lower_bound(Suma.begin(), Suma.end(), v) - Suma.begin() + 1<<"\n";
    }
    return 0;
}