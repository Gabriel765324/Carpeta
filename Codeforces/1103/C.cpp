#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a, b, x;
        cin>>a>>b>>x;
        int c = 0, r = abs(a - b);
        while(1){
            r = min(r, abs(a - b) + c);
            if(a == 0 and b == 0) break;
            if(a > b) a /= x;
            else b /= x;
            c++;
        }
        cout<<r<<"\n";
    }
    return 0;
}