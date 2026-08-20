#include "bits/stdc++.h"
using namespace std;
int main(){
    int Horas, Minutos, Segundos;
    cout<<"Horas: ";
    cin>>Horas;
    cout<<"Minutos: ";
    cin>>Minutos;
    cout<<"Segundos: ";
    cin>>Segundos;
    cout<<"Segundos transcurridos: "<<Horas * 3600 + Minutos * 60 + Segundos<<".";
    return 0;
}