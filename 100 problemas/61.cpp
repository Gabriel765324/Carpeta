#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    long long s = 0;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++){
        cin>>b[i];
        s += min(a[i], b[i]);
    }
    while(q--){
        char t;
        int p;
        long long v;
        cin>>t>>p>>v;
        p--;
        s -= min(a[p], b[p]);
        if(t == 'A') a[p] = v;
        else b[p] = v;
        s += min(a[p], b[p]);
        cout<<s<<"\n";
    }
    return 0;
}