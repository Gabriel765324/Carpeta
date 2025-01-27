#include "bits/stdc++.h"
using namespace std;
long long m = 998244353;
long long Multiplicar(long long a, long long b){
    return (a % m * b % m) % m;
}
long long Potencia(long long b, long long e){
    if(e == 0) return 1;
    if(e == 1) return b % m;
    long long a = Potencia(b % m, e / 2) % m;
    a = Multiplicar(a, a) % m;
    if(e % 2 == 1) a = Multiplicar(a, b) % m;
    return a % m;
}
long long Dividir(long long a, long long b){
    return (a % m * Potencia(b, m - 2) % m) % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, M, l, r;
    cin>>n>>M>>l>>r;
    if(n * M % 2 == 1){
        cout<<Potencia(r - l + 1, n * M) % m;
    } else {
        long long k = r - l + 1, Par, Impar;
        if(l % 2 == 0){
            Par = k / 2;
            Impar = k / 2;
            Par += k - Par - Impar;
        } else {
            Par = k / 2;
            Impar = k / 2;
            Impar += k - Impar - Par;
        }
        cout<<Dividir((Potencia(Par + Impar, n * M) % m + Potencia(Par - Impar, n * M) % m) % m, 2) % m;
    }
    return 0;
}