#include "bits/stdc++.h"
using namespace std;
long long m = 998244353;
long long Potencia(long long b, long long e){
    if(e == 0) return 1LL;
    if(e == 1) return b % m;
    long long a = Potencia(b, e / 2);
    a = (a % m * a % m) % m;
    a = (a % m * Potencia(b, e % 2) % m) % m;
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> Factorial(2, 1);
    while(Factorial.size() < 1000022) Factorial.push_back(((long long)Factorial.size() % m * Factorial.back() % m) % m);
    int q;
    cin>>q;
    while(q--){
        int n, k;
        cin>>n>>k;
        n++;
        k++;
        cout<<((Factorial[n] % m * Potencia(Factorial[k], m - 2) % m) % m * Potencia(Factorial[n - k], m - 2) % m) % m<<"\n";
    }
    return 0;
}