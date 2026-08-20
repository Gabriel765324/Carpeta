#include "bits/stdc++.h"
using namespace std;
int main(){
    long double Dinero, Cambio;
    cout<<"Cantidad disponible: ";
    cin>>Dinero;
    cout<<"Tipo de cambio: ";
    cin>>Cambio;
    cout<<"Cantidad equivalente: "<<Dinero / Cambio<<" dólares.";
    return 0;
}