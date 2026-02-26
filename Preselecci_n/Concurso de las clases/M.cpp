#include "bits/stdc++.h"
using namespace std;
long long m = 1000000007;
long long Exponenciar(long long Base, long long Exponente){
    if(Exponente == 0) return 1;
    else if(Exponente == 1) return Base;
    else {
        if(Exponente % 2 == 0){
            long long Carlos = Exponenciar(Base, Exponente / 2) % m;
            return (Carlos * Carlos) % m;
        } else {
            long long Carlos = Exponenciar(Base, Exponente / 2) % m;
            long long EL_CARLOS = (Carlos * Carlos) % m;
            return (EL_CARLOS * Base) % m;
        }
    }
}
long long Factorializar(long long n){
    if(n == 1) return 1;
    else return (Factorializar(n - 1) % m * n % m) % m;
}
long long Catalanizar(long long n){
    long long _1 = Factorializar(2 * n) % m;
    long long _2 = Factorializar(n) % m;
    _2 = (_2 * _2) % m;
    _2 = Exponenciar(_2, m - 2) % m;
    long long _3 = Exponenciar(n + 1, m - 2) % m;
    long long _4 = (_1 * _2) % m;
    long long _5 = (_4 * _3) % m;
    return _5 % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    if(n % 2 == 1) cout<<0;
    else cout<<Catalanizar(n / 2) % m;
    return 0;
}