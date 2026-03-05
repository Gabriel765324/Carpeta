#include "bits/stdc++.h"
using namespace std;
long long m = 1000000007;
vector<long long> Factoriales(2222);
long long M(long long a, long long b){
    return (a % m * b % m) % m;
}
long long Potencia(long long b, long long e){
    if(e == 0) return 1;
    if(e == 1) return b;
    long long a = Potencia(b, e / 2);
    a = M(a, a);
    a = M(a, Potencia(b, e % 2));
    return a % m;
}
long long D(long long a, long long b){
    return (a % m * Potencia(b, m - 2) % m) % m;
}
long long Combinatorio(long long a, long long b){
    return D(Factoriales[a] % m, M(Factoriales[b] % m, Factoriales[a - b] % m));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    Factoriales[0] = 1 % m;
    Factoriales[1] = 1 % m;
    for(int i = 2; i < 2222; i++){
        Factoriales[i] = M(i % m, Factoriales[i - 1] % m) % m;
    }
    long long r = 1, s = 0;
    while(n--){
        long long a;
        cin>>a;
        s++;
        a--;
        r = M(r, Combinatorio((s - 1 + a) % m, a % m)) % m;
        s += a;
    }
    cout<<r % m;
    return 0;
}