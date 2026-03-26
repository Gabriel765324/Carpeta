#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r = 22;
    cin>>n>>m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin>>s[i];
    for(int i = 1; i < (1<<n); i++){
        string Bien(m, 'x'), Debe(m, 'o');
        int c = 0;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                c++;
                for(int k = 0; k < m; k++){
                    if(s[j][k] == 'o') Bien[k] = 'o';
                }
            }
        }
        if(Bien == Debe) r = min(r, c);
    }
    cout<<r;
    return 0;
}