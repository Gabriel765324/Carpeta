#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    s[2]++;
    if(s[2] == '9'){
        s[2] = '1';
        s[0]++;
    }
    cout<<s;
    return 0;
}