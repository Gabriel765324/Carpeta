#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    vector<bool> Letras(44, 1);
    for(auto E: s) Letras[E - 'a'] = 0;
    for(int i = 'a'; i <= 'z'; i++){
        if(Letras[i - 'a']){
            cout<<(char)i;
            return 0;
        }
    }
    return 0;
}