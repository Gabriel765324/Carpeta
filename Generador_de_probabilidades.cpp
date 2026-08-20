#include <bits/stdc++.h>
using namespace std;
mt19937 Aleatorizador(chrono::steady_clock::now().time_since_epoch().count());
int main(){
    long double p = (long double)1 / (long double)512;
    while(1){
        uniform_real_distribution<long double> Aleatorio(0, 1);
        int Contador = 0;
        while(1){
            Contador++;
            if(Aleatorio(Aleatorizador) <= p) break;
        }
        cout<<Contador<<"\n";
        break;
    }
    return 0;
}