#include "bits/stdc++.h"
using namespace std;
map<long long, long long> Mapa;
long long Encontrar(long long i){
    if(Mapa.count(i) >= 1) return Mapa[i];
    if(i % 2 == 0){
        return Mapa[i] = Encontrar(i / 2) * 2;
    } else {
        return Mapa[i] = Encontrar(i / 2) - 3 * Encontrar(i / 2 + 1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Mapa[1] = 1;
    Mapa[2] = 2;
    long long n;
    cin>>n;
    cout<<4 * Encontrar(1) + Encontrar(n) - 3 * Encontrar(n / 2);
    return 0;
}