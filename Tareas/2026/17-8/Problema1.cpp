#include "bits/stdc++.h"
using namespace std;
int main(){
    long double Distancia, Combustible;
    cout<<"Distancia recorrida: ";
    cin>>Distancia;
    cout<<"Combustible consumido: ";
    cin>>Combustible;
    cout<<"Rendimiento promedio: "<<Distancia / Combustible<<" kilómetros / litro.";
    return 0;
}