#include "bits/stdc++.h"
using namespace std;
struct Nadador{
    long long Altura_inicial, Velocidad, Carril;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, l, r, m, k;
    cin>>n>>m>>l>>r>>k;
    vector<Nadador> a(k);
    for(int i = 0; i < k; i++){
        cin>>a[i].Altura_inicial>>a[i].Carril>>a[i].Velocidad;
        a[i].Carril++;
    }
    set<long long> Mal;
    for(long long i = 0; i < k; i++){
        long long p = abs(a[i].Altura_inicial + a[i].Velocidad * a[i].Carril);
        p %= 2LL * n - 2LL;
        if(p >= n) p = 2LL * n - 2LL - p;
        /*a[i].Altura_inicial;
        long long Sentido = a[i].Velocidad >= 0LL ? 1LL : -1LL;
        for(long long j = 0; j < abs(a[i].Velocidad) * a[i].Carril; j++){
            p += Sentido;
            if(p >= n){
                p = n - 2;
                Sentido = -Sentido;
            }
            if(p < 0){
                p = 1;
                Sentido = -Sentido;
            }
        }*/
        /*abs(a[i].Altura_inicial + a[i].Velocidad * a[i].Carril);
        if(p >= n){
            p -= n;
            if((long long)(p / (n - 1LL)) % 2LL == 0LL){
                p %= n - 1LL;
                p = n - p - 2LL;
            } else {
                p %= n - 1LL;
                p++;
            }
        }*/
        //cerr<<p<<"\n";
        Mal.insert(p);
    }
    long long Respuesta = r - l + 1LL;
    for(auto E: Mal){
        if(E >= l and E <= r) Respuesta--;
    }
    cout<<Respuesta<<"\n";
    return 0;
}