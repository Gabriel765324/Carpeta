#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin>>n>>m){
        long long p = 1LL;
        long long w;
        int a, b;
        while(m--){
            cin>>w>>a>>b;
            if(w & 1LL) p *= w;
        }
        cout<<p<<"\n";
    }
    return 0;
}