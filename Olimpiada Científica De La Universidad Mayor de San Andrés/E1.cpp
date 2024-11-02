#include "bits/stdc++.h"
using namespace std;
vector<long long> Factorial(1022, 0);
void aaa(){
    Factorial[0] = 1;
    Factorial[1] = 1;
    for(long long i = 2; i < 1022; i++){
        Factorial[i] = (i % 100 * Factorial[i - 1] % 100) % 100;
    }
    for(long long i = 2; i < 1022; i++){
        Factorial[i] = (Factorial[i] % 100 + Factorial[i - 1] % 100) % 100;
    }
}
long long p(long long b, long long e){
    if(e == 0) return 1;
    if(e == 1) return b % 100;
    long long a = p(b, e / 2);
    a = (a % 100 * a % 100) % 100;
    if((e % 2) == 1) a = (a % 100 * b % 100) % 100;
    return a % 100;
}
long long f(long long n){
    return p(Factorial[n], n) % 100;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    aaa();
    while(t--){
        long long n;
        cin>>n;
        cout<<f(n) % 100<<"\n";
    }
    return 0;
}