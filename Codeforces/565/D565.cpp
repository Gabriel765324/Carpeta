#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> Criba(2750132, 1);
    vector<long long> Primos(1, 1);
    long long i;
    for(i = 2; (i * i) < Criba.size(); i++){
        if(Criba[i] == 1){
            for(long long j = i * i; j < Criba.size(); j += i){
                if(Criba[j] == 1) Criba[j] = i;
            }
            Primos.push_back(i);
        }
    }
    for(; i < Criba.size(); i++){
        if(Criba[i] == 1) Primos.push_back(i);
    }
        long long n;
        cin>>n;
        map<long long, long long> b;
        vector<long long> Disponibles(n * 2);
        for(long long i = 0; i < (2 * n); i++){
            cin>>Disponibles[i];
            b[Disponibles[i]]++;
        }
        vector<long long> a;
        sort(Disponibles.rbegin(), Disponibles.rend());
        for(long long i = 0; i < (2 * n); i++){
            //cout<<i<<" ";
            if(b[Disponibles[i]] > 0){
                if(Criba[Disponibles[i]] == 1){
                    a.push_back(lower_bound(Primos.begin(), Primos.end(), Disponibles[i]) - Primos.begin());
                    b[Disponibles[i]]--;
                    b[lower_bound(Primos.begin(), Primos.end(), Disponibles[i]) - Primos.begin()]--;
                } else {
                    b[Disponibles[i]]--;
                    long long e = Disponibles[i] / Criba[Disponibles[i]];
                    b[e]--;
                    a.push_back(Disponibles[i]);
                }
            }
        }
        for(auto E: a) cout<<E<<" ";
        cout<<"\n";
    return 0;
}