#include "bits/stdc++.h"
using namespace std;
mt19937 Aleatorio(2);
int main(){
    long long n, m;
    cin>>n>>m;
    freopen("01.in", "w", stdout);
    cout<<n<<" "<<m<<"\n";
    uniform_int_distribution<long long> Aleatorizadoruv(1, n);
    uniform_int_distribution<long long> Aleatorizadorw(222222, 1000000000);
    for(long long i = 1; i < n; i++){
        cout<<i<<" "<<i + 1<<" 1\n";
    }
    for(long long i = n; i <= m; i++){
        cout<<Aleatorizadoruv(Aleatorio)<<" "<<Aleatorizadoruv(Aleatorio)<<" "<<Aleatorizadorw(Aleatorio)<<"\n";
    }
    return 0;
}