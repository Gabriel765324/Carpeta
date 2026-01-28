#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int i = 0, n = s.size(), j = n - 1;
    for(; i < n; i++){
        if(s[i] == '.'){
            break;
        }
    }
    for(; j > -1; j--){
        if(s[i] == '.'){
            break;
        }
    }
    if(i == n){
        cout<<s;
        return 0;
    }
    j++;
    s[i] = 'o';
    for(int k = i + 1; k < j; k++){
        if(s[k - 1] == '#' and s[k] != '#') s[k] = 'o';
    }
    cout<<s;
    return 0;
}