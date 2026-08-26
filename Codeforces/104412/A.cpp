#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r = 0;
    string k;
    cin>>n>>k;
    for(int i = 0; i < n; i++) if(k[i] != '0' and k[i] != '6' and k[i] != '8') r++;
    cout<<r;
    return 0;
}