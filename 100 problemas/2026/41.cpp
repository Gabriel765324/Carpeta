#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r, c = 0;
    cin>>n>>l>>r;
    while(n--){
        int a, b;
        cin>>a>>b;
        c += a <= l and r <= b;
    }
    cout<<c;
    return 0;
}