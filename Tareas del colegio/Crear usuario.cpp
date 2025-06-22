#include "bits/stdc++.h"
using namespace std;
int main(){
    string a, b, c, d, u = "";
    cout<<"Nombres: ";
    getline(cin, a);
    cout<<"Apellido paterno: ";
    cin>>b;
    cout<<"Apellido materno: ";
    cin>>c;
    stringstream Conversor;
    Conversor<<a;
    while(Conversor>>d){
        u += d[0];
    }
    u += b[0];
    u += c[0];
    system("pause");
    system("cls");
    cout<<"Gracias, sus datos fueron registrados.\nSu nombre de usuario es: "<<u<<"\n";
    system("pause");
    return 0;
}