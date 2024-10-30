#include "bits/stdc++.h"
#include "conio.h"
using namespace std;
int main(){
    long long f, c;
    cout<<"Ingrese el número de filas y columnas.\n";
    cin>>f>>c;
    vector< vector<long long> > m(f, vector<long long>(c));
    for(long long i = 0; i < f; i++){
        for(long long j = 0; j < c; j++){
            cout<<"Digite el valor para la posición ["<<i<<"]["<<j<<"]. ";
            cin>>m[i][j];
        }
    }
    //Esto tal vez solo funciona en C++ 11 o superior.
    for(auto i: m){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    // Esto sí debería funcionar en versiones anteriores.
    /*for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    getch();
    return 0;
}