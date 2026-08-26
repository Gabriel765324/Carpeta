#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> a = {"#"};
    string Punto = ".";
    while(n--){
        vector<string> b = a;
        vector<string> c = a;
        vector<string> d = a;
        for(int i = 0; i < b.size(); i++){
            b[i] += b[i] + b[i];
            c[i] += Punto + c[i];
            d[i] += d[i] + d[i];
        }
        int i = Punto.size() * 3;
        while(Punto.size() < i) Punto += '.';
        a.clear();
        for(auto E: b) a.push_back(E);
        for(auto E: c) a.push_back(E);
        for(auto E: d) a.push_back(E);
    }
    for(auto E: a) cout<<E<<"\n";
    return 0;
}