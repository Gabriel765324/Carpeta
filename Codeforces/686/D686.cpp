#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        map<long long, long long> Mapa;
        set<long long> Disponibles;
        for(long long i = 2; (i * i) <= n; i++){
            while((n % i) == 0){
                Disponibles.insert(i);
                Mapa[i]++;
                n /= i;
            }
        }
        if(n > 1){
            Disponibles.insert(n);
            Mapa[n]++;
        }
        long long Mayor = -2222222222222222;
        long long So = 0;
        for(auto E: Disponibles){
            if(Mapa[E] > Mayor) So = E;
            Mayor = max(Mayor, Mapa[E]);
        }
        long long Final = 1;
        vector<long long> a(Mayor, So);
        for(auto E: Disponibles){
            for(long long i = 0; i < Mapa[E] and E != So; i++) Final *= E;
        }
        a.back() *= Final;
        cout<<a.size()<<"\n";
        for(auto E: a) cout<<E<<" ";
        cout<<"\n";
    }
    return 0;
}