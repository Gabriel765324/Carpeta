#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r = 0;
    cin>>n;
    bool Mal = 1;
    while(n--){
        string s;
        cin>>s;
        if(s == "login") Mal = 0;
        if(s == "logout") Mal = 1;
        if(s == "private" and Mal) r++;
    }
    cout<<r;
    return 0;
}