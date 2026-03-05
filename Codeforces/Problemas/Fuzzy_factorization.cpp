#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x;
    cin>>x;
    if(x.size() < 12){
        long long n;
        stringstream c;
        c<<x;
        c>>n;
        map<long long, long long> Mapa;
        for(long long i = 2; i * i <= n; i++){
            while(n % i == 0){
                Mapa[i]++;
                n /= i;
            }
        }
        if(n > 1){
            Mapa[n]++;
        }
        cout<<Mapa.size()<<"\n";
        for(auto E: Mapa){
            cout<<E.first<<" "<<E.second<<"\n";
        }
        return 0;
    }
    string xx = x.substr(0, 11);
    long long n;
    stringstream c;
    c<<xx;
    c>>n;
    map<long long, long long> Mapa;
    for(long long i = 2; i * i <= n; i++){
        while(n % i == 0){
            Mapa[i]++;
            n /= i;
        }
    }
    if(n > 1){
        Mapa[n]++;
    }
    Mapa[2] += x.size() - 11;
    Mapa[5] += x.size() - 11;
    cout<<Mapa.size()<<"\n";
    for(auto E: Mapa){
        cout<<E.first<<" "<<E.second<<"\n";
    }
    return 0;
}