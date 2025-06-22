#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Bienvenido al cajero automático.\n";
    long long Saldo = 1000LL;
    while(1){
        cout<<"Tiene "<<Saldo<<" boliviano(s).\n¿Quiere sacar dinero o meter dinero? (S/M)\n";
        char a;
        cin>>a;
        if(a == 'S'){
            long long Sacar;
            cout<<"¿Cuánto dinero va a sacar?\n";
            cin>>Sacar;
            if(Sacar > Saldo) cout<<"Fondos insuficientes.";
            else cout<<"Saque su dinero.";
        } else if(a == 'M'){
            long long Meter;
            cout<<"¿Cuánto dinero va a meter?\n";
            cin>>Meter;
            Saldo += Meter;
            cout<<"Se añadió el dinero exitosamente.";
        } else {
            cout<<"Eso no es una opción.";
        }
        cout<<"\n";
        system("pause");
        system("cls");
        cout<<"¿Quiere continuar? (S/N)\n";
        char r;
        cin>>r;
        if(r == 'N') return 0;
        system("cls");
    }
    return 0;
}