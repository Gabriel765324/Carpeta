#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>s;
    n = int(s.size());
    string OK = ".-.-.-", KO = ".-.-.-", OOK = ".-.-.-.-.-", a = "";
    for(int i = 0; i < n; i++){
        a += s[i];
        if(a == "KO"){
            cout<<KO;
            a = "";
        }
        if(a == "OK"){
            cout<<OK;
            a = "";
        }
        if(a == "OOK"){
            cout<<OOK;
            a = "";
        }
    }
    cout<<"\n";
    return 0;
}