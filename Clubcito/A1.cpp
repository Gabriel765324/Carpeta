#include "bits/stdc++.h"
using namespace std;
void Resolver(){
    int n;
    long long r = 0;
    cin>>n;
    map<int, long long> Mapa;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        r += Mapa[a - i];
        Mapa[a - i]++;
    }
    cout<<r<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}