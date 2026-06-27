#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    map<string, int> m;
    while(n--){
        string s;
        cin>>s;
        m[s]++;
    }
    int Mayor = -2;
    string Elegido;
    for(auto E: m){
        if(E.second > Mayor){
            Mayor = E.second;
            Elegido = E.first;
        }
    }
    cout<<Elegido<<"\n";
    return 0;
}