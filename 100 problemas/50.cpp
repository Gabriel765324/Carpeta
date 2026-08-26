#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    string s;
    cin>>n>>a>>b>>s;
    cout<<s.substr(a, n - a - b);
    return 0;
}