#include "bits/stdc++.h"
using namespace std;
int main(){
    string Nombre, Contrase_a, Apellido1, Apellido2;
    long long Edad;
    bool Existe = 0;
    while(1){
        cout<<"Elija una opción.\n1. Crear usuario\n2. Ingresar al sistema\n3. Modificar datos\n4. Eliminar datos\n5. Salir\n";
        long long Opci_n;
        cin>>Opci_n;
        switch(Opci_n){
            case 1:
                if(Existe) cout<<"Ya existe un usuario.\n";
                else {
                    cout<<"Ingrese su nombre, contraseña, apellido paterno, apellido materno y edad.\n";
                    cin>>Nombre>>Contrase_a>>Apellido1>>Apellido2>>Edad;
                    Existe = 1;
                }
            break;
            case 2:
                if(Existe){
                    string IN, IC;
                    cout<<"Ingrese su nombre y su contraseña.\n";
                    cin>>IN>>IC;
                    if(IN == Nombre and IC == Contrase_a) cout<<"Bienvenido.\n";
                    else cout<<"Usuario o contraseña incorrectos.\n";
                } else {
                    cout<<"No existe un usuario\n";
                }
            break;
            case 3:
                if(!Existe) cout<<"No existe un usuario.\n";
                else {
                    cout<<"Ingrese su nombre, contraseña, apellido paterno, apellido materno y edad.\n";
                    cin>>Nombre>>Contrase_a>>Apellido1>>Apellido2>>Edad;
                }
            break;
            case 4:
                if(Existe){
                    Existe = 0;
                    cout<<"Datos borrados\n";
                } else {
                    cout<<"No existe un usuario.\n";
                }
            break;
            case 5:
                cout<<"Chau.\n";
                return 0;
            break;
        }
    }
    return 0;
}