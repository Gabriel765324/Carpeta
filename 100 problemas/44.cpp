#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    int x;
    cin>>x;
    for(auto E: a){
        if(E == x){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}