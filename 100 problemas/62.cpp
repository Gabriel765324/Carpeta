#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    int p;
    string s;
    cin>>p>>s;
    cout<<(a[p - 1] == s ? "Yes" : "No");
    return 0;
}