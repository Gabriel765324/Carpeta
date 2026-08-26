#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin>>s>>t;
    t += (char)(222);
    sort(t.begin(), t.end());
    for(int i = 1; i < s.size(); i++){
        if(s[i] >= 'A' and s[i] <= 'Z'){
            if(*lower_bound(t.begin(), t.end(), s[i - 1]) != s[i - 1]){
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}