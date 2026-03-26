#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin>>s>>t;
    int i = 0, j = 1;
    for(auto E: t){
        if(E == s[i]){
            cout<<j<<" ";
            i++;
            if(i == s.size()) return -0;
        }
        j++;
    }
    return 0;
}