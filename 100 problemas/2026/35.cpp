#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r = 0;
    cin>>n;
    while(n--){
        int a, b;
        cin>>a>>b;
        r += b > a;
    }
    cout<<r;
    return 0;
}