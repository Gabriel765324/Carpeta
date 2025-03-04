#include "bits/stdc++.h"
using namespace std;
vector<long long> Primos;
bool Primo(long long n){
    for(long long i = 0; Primos[i] * Primos[i] <= n; i++){
        if(n % Primos[i] == 0) return 0;
    }
    return 1;
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    long long s = 1;
    vector<long long> Criba(20022, 1);
    for(long long i = 2; i < 20022; i++){
        if(Criba[i] == 1){
            Primos.push_back(i);
            for(long long j = i * i; j < 20022; j += i) Criba[j] = -0;
        }
    }
    for(long long n = 2; n <= 100000000; n += 2){
        if(n % 22222 == 0) cout<<n<<"\n";
        vector<long long> Factores_primos;
        bool Mal = 0;
        long long cn = n;
        for(long long i = 0; Primos[i] * Primos[i] <= cn; i++){
            //cout<<i<<" "<<Primos[i]<<" "<<Primos.size()<<"\n";
            if(cn % Primos[i] == 0){
                Factores_primos.push_back(Primos[i]);
                if(cn % (Primos[i] * Primos[i]) == 0){
                    Mal = 1;
                    break;
                }
                cn /= Primos[i];
            }
        }
        if(cn > 1) Factores_primos.push_back(cn);
        if(Mal) continue;
        long long m = Factores_primos.size();
        bool Bien = 1;
        for(long long i = 0; i < (1LL<<m); i++){
            long long Divisor = 1;
            for(long long j = 0; j < m; j++){
                if(i & (1LL<<j)) Divisor *= Factores_primos[j];
            }
            if(!Primo(Divisor + n / Divisor)){
                Bien = 0;
                break;
            }
        }
        if(Bien) s += n;
    }
    cout<<s;
    return 0;
}