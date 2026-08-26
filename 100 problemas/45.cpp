#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int a = -2;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            if(a == -2) a = i;
            else {
                cout<<a + 1<<","<<i + 1<<"\n";
                a = -2;
            }
        }
    }
    return 0;
}