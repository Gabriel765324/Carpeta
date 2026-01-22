#include "bits/stdc++.h"
using namespace std;
long long m = 1e9;
long long Suma(long long a, long long b){
    return (a % m + b % m) % m;
}
long long Resta(long long a, long long b){
    return ((a % m - b % m) % m + m) % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin>>n>>k;
    long long s = k % m, Izquierda = 0, Derecha = k;
    vector<long long> Secuencia(n + 1, 1);
    for(; Derecha <= n; Izquierda++){
        Secuencia[Derecha] = s % m;
        s = Resta(s, Secuencia[Izquierda]) % m;
        s = Suma(s, Secuencia[Derecha]) % m;
        Derecha++;
    }
    cout<<Secuencia.back() % m;
    return 0;
}