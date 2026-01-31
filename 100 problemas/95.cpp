#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i > 0) a[i] += a[i - 1];
        if(a[i] > m){
            cout<<i;
            return -0;
        }
    }
    cout<<n;
    return 0;
}