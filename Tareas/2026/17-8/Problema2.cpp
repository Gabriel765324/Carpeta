#include "bits/stdc++.h"
using namespace std;
int main(){
    long double Precio, Unidades, Descuento;
    cout<<"Precio unitario: ";
    cin>>Precio;
    cout<<"Cantidad de unidades: ";
    cin>>Unidades;
    cout<<"Porcentaje de descuento: ";
    cin>>Descuento;
    cout<<"Importe antes del descuento: "<<Precio * Unidades<<" bolivianos.\n";
    cout<<"Monto descontado: "<<Precio * Unidades * Descuento / (long double)100<<" bolivianos.\n";
    cout<<"Monto final a pagar: "<<Precio * Unidades * ((long double)100 - Descuento) / (long double)100<<" bolivianos.";
    return 0;
}