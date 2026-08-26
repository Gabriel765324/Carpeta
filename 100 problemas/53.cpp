#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>n>>s;
    cout<<(s.size() >= 3 and (s.substr(n - 3, 3) == "tea") ? "Yes" : "No");
    return 0;
}