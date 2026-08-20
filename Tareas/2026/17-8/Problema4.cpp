#include "bits/stdc++.h"
using namespace std;
int main(){
    long double Distancia, Rendimiento, Precio;
    cout<<"Distancia del viaje: ";
    cin>>Distancia;
    cout<<"Rendimiento del vehículo: ";
    cin>>Rendimiento;
    cout<<"Precio del combustible: ";
    cin>>Precio;
    cout<<"Combustible necesario: "<<Distancia / Rendimiento<<" litros.\n";
    cout<<"Costo estimado del viaje: "<<Distancia / Rendimiento * Precio<<" bolivianos.";
    return 0;
}