#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        bool Bien = 0;
        set<char> Hay;
        Hay.insert(s[0]);
        Hay.insert(s.back());
        for(int i = 1; i < n - 1; i++){
            if(Hay.count(s[i]) == 1){
                Bien = 1;
                break;
            } else Hay.insert(s[i]);
        }
        if(Bien) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}