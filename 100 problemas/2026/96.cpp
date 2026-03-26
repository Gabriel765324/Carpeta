#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n = s.size(), c = 0;
    for(auto E: s){
        if(E >= 'A' and E <= 'Z') c++;
        else c--;
    }
    if(c > 0){
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' and s[i] <= 'z') s[i] -= 'a' - 'A';
        }
    } else {
        for(int i = 0; i < n; i++){
            if(s[i] >= 'A' and s[i] <= 'Z') s[i] += 'a' - 'A';
        }
    }
    cout<<s;
    return 0;
}