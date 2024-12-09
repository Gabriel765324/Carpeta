#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, x, r = 0;
    cin>>n>>x;
    deque<long long> a(n), Suma(n);
    for(long long i = 0; i < n; i++){
        cin>>a[i];
        Suma[i] = a[i];
        if(i > 0) Suma[i] += Suma[i - 1];
    }
    map<long long, long long> Mapa;
    for(long long i = n - 1; i > -1; i--){
        r += Mapa[Suma[i] + x];
        Mapa[Suma[i]]++;
    }
    cout<<r + Mapa[x];
    return 0;
}