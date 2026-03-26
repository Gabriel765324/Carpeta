#include "bits/stdc++.h"
using namespace std;
mt19937 Aleatorio(465515);
int main(){
    freopen("01.in", "w", stdout);
    long long f, c, q;
    uniform_int_distribution<long long> Aleatorizador(1, 1);
    uniform_int_distribution<long long> Consultas(1, 2102);
    f = Aleatorizador(Aleatorio);
    c = Aleatorizador(Aleatorio);
    q = Consultas(Aleatorio);
    cout<<f<<" "<<c<<" "<<q<<"\n";
    uniform_int_distribution<long long> Uno_o_dos(1, 2);
    uniform_int_distribution<long long> F(1, f);
    uniform_int_distribution<long long> C(1, c);
    while(q--){
        long long t, i, co;
        co = Consultas(Aleatorio);
        t = Uno_o_dos(Aleatorio);
        if(t == 1){
            i = F(Aleatorio);
        } else {
            i = C(Aleatorio);
        }
        cout<<t<<" "<<i<<" "<<co<<"\n";
    }
    return 0;
}