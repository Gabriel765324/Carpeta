#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, r = "";
    cin>>s;
    for(auto E: s) if(E >= 'A' and E <= 'Z') r += E;
    cout<<r;
    return 0;
}