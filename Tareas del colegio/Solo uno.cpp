#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    set< pair<int, string> > Estos;
    set<string> Hay;
    int i = 1;
    while(getline(cin, s)){
        if(Hay.count(s) == 0){
            Estos.insert({i, s});
            Hay.insert(s);
            i++;
        }
    }
    for(auto E: Estos){
        cout<<E.second<<"\n";
        i++;
    }
    return 0;
}