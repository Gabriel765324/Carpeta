#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r;
    string s;
    cin>>n>>l>>r>>s;
    for(int i = l - 1; i < r; i++){
        if(s[i] != 'o'){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}