#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    while(n--){
        int a;
        cin>>a;
        m -= a;
    }
    cout<<((m < 0) ? "No" : "Yes");
    return 0;
}