#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    s.erase(s.begin());
    s.erase(s.begin());
    s.erase(s.begin());
    if(s == "SP") cout<<"S\n";
    else if(s == "S?" or s == "?P") cout<<"T\n";
    else cout<<"N\n";
    return 0;
}