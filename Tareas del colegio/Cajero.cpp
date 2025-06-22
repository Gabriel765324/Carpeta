#include "bits/stdc++.h"
using namespace std;
int main(){
    string a;
    for(int i = 0; 1; i++){
        if(i == 3){
            cout<<"Muchos intentos fallidos.";
            return 0;
        }
        cout<<"Ingrese su código.\n";
        cin>>a;
        if(a == "4444" or a == "2222") break;
        cout<<"Código incorrecto.\n";
        system("pause");
        system("cls");
    }
    cout<<"Bienvenido ";
    if(a == "2222") cout<<"Gabriel";
    else cout<<"Cruz";
    cout<<"\n";
    long long Kromer = 500;
    while(1){
        system("pause");
        system("cls");
        if(a == "2222") cout<<"Gabriel";
        else cout<<"Cruz";
        cout<<", elija una opción.\n1. Retirar\n2. Depositar\n3. Consultar\n4. Salir\n";
        long long o;
        cin>>o;
        long long d;
        switch(o){
            case 1:
            cout<<"¿Cuánto dineró retirará?\n";
            cin>>d;
            if(Kromer >= d){
                Kromer -= d;
                cout<<"Le quedan "<<Kromer<<" boliviano(s).\nPor favor retire su dinero.\n";
            } else cout<<"Fondos insuficientes, usted tiene "<<Kromer<<" boliviano(s).\n";
            break;
            case 2:
                cout<<"¿Cuánto dinero depositará?\n";
                cin>>d;
                Kromer += d;
                cout<<"Tiene "<<Kromer<<" boliviano(s) en su cuenta.\n";
            break;
            case 3:
                cout<<"Tiene "<<Kromer<<" boliviano(s) en su cuenta.\n";
            break;
            case 4:
            cout<<"Gracias por su preferencia.\n";
            return 0;
            break;
            default:
            cout<<"Eso no es una opción.\n";
        }
    }
    return 0;
}
