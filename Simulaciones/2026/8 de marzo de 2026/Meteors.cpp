#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin>>n>>m;
    vector<int> a(m), r(n, -2);
    vector<long long> o(n);
    for(int i = 0; i < m; i++){
        cin>>a[i];
        a[i]--;
    }
    for(int i = 0; i < n; i++) cin>>o[i];
    cin>>k;
    for(int c = 0; c < k; c++){
        int i, d;
        long long v;
        cin>>i>>d>>v;
        d--;
        for(i--; 1; i %= m){
            o[a[i]] -= v;
            if(i == d) break;
            i++;
        }
        for(i = 0; i < n; i++){
            if(o[i] <= 0 and r[i] == -2) r[i] = c + 1;
        }
    }
    for(auto E: r){
        if(E != -2) cout<<E;
        else cout<<"NIE";
        cout<<"\n";
    }
    return 0;
}