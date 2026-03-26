#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, p = 0;
    cin>>n>>q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = i + 1;
    while(q--){
        int t, i, x;
        cin>>t;
        if(t == 1){
            cin>>i>>x;
            a[(p + i - 1 + n * 22) % n] = x;
        } else if(t == 2){
            cin>>i;
            cout<<a[(p + i - 1 + n * 22) % n]<<"\n";
        } else {
            cin>>i;
            p += i;
            p %= n;
        }
    }
    return 0;
}