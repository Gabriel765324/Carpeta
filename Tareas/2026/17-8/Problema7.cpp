#include "bits/stdc++.h"
using namespace std;
int main(){
    long double Monto;
    int Descuento;
    cout<<"Monto de la compra: ";
    cin>>Monto;
    if(Monto >= (long double)2000) Descuento = 15;
    else if(Monto >= (long double)1000) Descuento = 10;
    else if(Monto >= (long double)500) Descuento = 5;
    else Descuento = 0;
    cout<<"Descuento aplicado: "<<Descuento<<"%.\n";
    cout<<"Monto del descuento: "<<(long double)Descuento / (long double)100 * Monto<<" bolivianos.\n";
    cout<<"Total a pagar: "<<Monto - (long double)Descuento / (long double)100 * Monto<<" boilivianos.";
    return 0;
}