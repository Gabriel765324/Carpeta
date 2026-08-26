#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        string s;
        cin>>n>>k>>s;
        for(int i = 0; i + k < n; i++){
            if(s[i] == '1'){
                s[i] = '0';
                s[i + k] = s[i + k] == '0' ? '1' : '0';
            }
        }
        bool Bien = 1;
        for(auto E: s) Bien = Bien and E == '0';
        if(Bien) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}