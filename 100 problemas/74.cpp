#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    if(s.substr(3, 3) >= "001" and s.substr(3, 3) <= "349" and s.substr(3, 3) != "316") cout<<"Yes";
    else cout<<"No";
    return 0;
}