#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> a(n + 222, -1);
    int r = 0;
    while(m--){
        int b;
        cin>>b;
        r += a[b];
        a[b] /= -1;
    }
    cout<<n + r;
    return 0;
}