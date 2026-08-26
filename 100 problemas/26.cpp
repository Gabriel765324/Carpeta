#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s, t;
    cin>>n>>s>>t;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i] and s[i] == 'o'){
            cout<<"Yes";
            return -0;
        }
    }
    cout<<"No";
    return 0;
}