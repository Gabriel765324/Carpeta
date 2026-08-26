#include "bits/stdc++.h"
using namespace std;
long long Potencia(long long b, long long e){
    if(e == 0) return 1;
    if(e == 1) return b;
    long long a = Potencia(b, e / 2);
    a *= a;
    if(e % 2 == 1) a *= b;
    return a;
}
bool Verificar(long long MCD, long long mcm, long long a, long long b){
    if(a % MCD != 0) return 0;
    if(b % MCD != 0) return 0;
    if(__gcd(a, b) != MCD) return 0;
    if(mcm % a != 0) return 0;
    if(mcm % b != 0) return 0;
    if(a / __gcd(a, b) * b != mcm) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long a, b, ca, cb;
        cin>>a>>b;
        ca = a;
        cb = b;
        if(a > b){
            cout<<"-1\n";
            continue;
        }
        map<long long, long long> Descomponer;
        set<long long> Hay;
        for(long long i = 2; i * i <= ca; i++){
            while(ca % i == 0){
                Descomponer[i]++;
                Hay.insert(i);
                ca /= i;
            }
        }
        if(ca > 1){
            Descomponer[ca]++;
            Hay.insert(ca);
        }
        for(long long i = 2; i * i <= cb; i++){
            while(cb % i == 0){
                Descomponer[i]++;
                Hay.insert(i);
                cb /= i;
            }
        }
        if(cb > 1){
            Descomponer[cb]++;
            Hay.insert(cb);
        }
        bool S_ = 0;
        vector<long long> Asignar;
        for(auto E: Hay) Asignar.push_back(E);
        bool Seguir = 1;
        long long r1, r2;
        /*for(auto E: Hay) cout<<Descomponer[E]<<" ";
        cout<<"\n";*/
        for(vector<long long> Probar(Hay.size(), 0); Seguir; ){
            long long n = 1;
            for(long long i = 0; i < Hay.size(); i++){
                n *= Potencia(Asignar[i], Probar[i]);
                //cout<<Probar[i]<<" ";
            }
            //cout<<"\n";
            long long Posible_1 = n, Posible_2 = a * b / n;
            if(Posible_1 > Posible_2) swap(Posible_1, Posible_2);
            //cout<<Posible_1<<" "<<Posible_2<<"\n";
            if(Verificar(a, b, Posible_1, Posible_2)){
                r1 = Posible_1;
                r2 = Posible_2;
                break;
            }
            for(long long i = Hay.size() - 1; i > -1; i--){
                Probar[i]++;
                if(Probar[i] > Descomponer[Asignar[i]]){
                    if(i > 0) Probar[i] = 0;
                    else Seguir = 0;
                } else break;
            }
        }
        if(Seguir) cout<<r1<<" "<<r2<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}