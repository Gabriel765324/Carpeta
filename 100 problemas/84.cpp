#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, r = 1, o = 0;
    cin>>n>>k;
    while(n--){
        int a;
        cin>>a;
        o += a;
        if(o > k){
            o = a;
            r++;
        }
    }
    cout<<r;
    return 0;
}