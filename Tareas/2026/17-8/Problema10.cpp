#include "bits/stdc++.h"
using namespace std;
int main(){
    unsigned long long Horas;
    long double Tarifa;
    cout<<"Horas estacionado: ";
    cin>>Horas;
    if(Horas > (long double)6) Tarifa = 2.5;
    else if(Horas > (long double)3) Tarifa = 3;
    else if(Horas > (long double)1) Tarifa = 4;
    else Tarifa = 5;
    cout<<"Tarifa aplicada: "<<Tarifa<<" bolivianos / hora.\n";
    cout<<"Total a pagar: "<<(long double)Horas * Tarifa<<" bolivianos.";
    return 0;
}