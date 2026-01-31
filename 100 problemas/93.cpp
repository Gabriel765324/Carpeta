#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin>>a[i];
    while(n--){
        for(int i = 0; i < m; i++){
            int b;
            cin>>b;
            a[i] -= b;
        }
    }
    for(auto E: a){
        if(E > 0){
            cout<<"No";
            return -0;
        }
    }
    cout<<"Yes";
    return 0;
}