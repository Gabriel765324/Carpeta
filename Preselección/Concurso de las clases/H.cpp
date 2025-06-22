#include "bits/stdc++.h"
using namespace std;
long long m = 1e9 + 7;
vector<long long> Memorizaci_n;
long long Suma(long long a, long long b){
    return (a % m + b % m) % m;
}
long long Resolver(long long n){
    if(n < 0) return 0;
    if(n == 0) return Memorizaci_n[n] = 1;
    if(Memorizaci_n[n] != -2) return Memorizaci_n[n];
    long long s = Resolver(n - 1) % m;
    s = Suma(s, Resolver(n - 2)) % m;
    s = Suma(s, Resolver(n - 3)) % m;
    s = Suma(s, Resolver(n - 4)) % m;
    s = Suma(s, Resolver(n - 5)) % m;
    s = Suma(s, Resolver(n - 6)) % m;
    return Memorizaci_n[n] = s % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    Memorizaci_n.assign(n + 1, -2);
    cout<<Resolver(n) % m;
    return 0;
}