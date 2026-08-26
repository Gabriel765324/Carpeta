#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    cin>>n;
    map<int, int> Mapa;
    while(n--){
        cin>>a;
        Mapa[a]++;
    }
    a = 0;
    for(auto E: Mapa){
        if(E.second >= E.first) a += E.second - E.first;
        else a += E.second;
    }
    cout<<a<<"\n";
    return 0;
}