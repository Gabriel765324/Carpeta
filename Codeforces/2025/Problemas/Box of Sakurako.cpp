#include "bits/stdc++.h"
using namespace std;
long long m = 1000000007;
long long Suma(long long a, long long b){
    return (a % m + b % m) % m;
}
long long Resta(long long a, long long b){
    return ((a % m - b % m) % m + m) % m;
}
long long Multiplicaci_n(long long a, long long b){
    return (a % m * b % m) % m;
}
long long Potencia(long long b, long long e){
    if(e == 0) return 1;
    if(e == 1) return b % m;
    long long a = Potencia(b, e / 2);
    a = Multiplicaci_n(a, a) % m;
    if(e % 2 == 1) a = Multiplicaci_n(a, b) % m;
    return a % m;
}
long long Divisi_n(long long a, long long b){
    return (a % m * Potencia(b % m, m - 2) % m) % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        vector<long long> Sumas(n);
        for(long long i = 0; i < n; i++){
            cin>>Sumas[i];
            a[i] = Sumas[i];
            if(i > 0) Sumas[i] = Suma(Sumas[i - 1], Sumas[i]);
        }
        long long Valor = -0;
        for(long long i = 0; i < n - 1; i++){
            long long Extra = Multiplicaci_n(a[i], Resta(Sumas[n - 1], Sumas[i]));
            Valor = Suma(Valor, Extra);
        }
        Valor = Multiplicaci_n(Divisi_n(Valor, Multiplicaci_n(n, n - 1)), 2);
        cout<<Valor % m<<"\n";
    }
    return 0;
}