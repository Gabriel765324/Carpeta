#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    string r = "";
    for(int i = 0; i < int(s.size()); i++){
        if(i + 5 < int(s.size()) and s.substr(i, 6) == "mesero"){
            i += 5;
            r += "taquero";
        } else r += s[i];
    }
    cout<<r;
    return 0;
}