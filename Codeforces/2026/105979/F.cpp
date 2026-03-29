#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m = 0, s0 = 0, s1 = 0;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i];
        s0 += a[i];
        s1 += b[i];
    }
    if(s0 == s1){
        cout<<0;
        return 0;
    }
    for(int i = 0; i < n; i++){
        m = max(s0 - a[i] - b[i], m);
    }
    cout<<(abs(s0 - s1) <= m ? 1 : 2); 
    return 0;
}