#include "bits/stdc++.h"
using namespace std;
int main(){
    long long s = 0, n;
    do{
        cout<<"Ingrese un número del 20 al 30 o 0 para terminar.\n";
        cin>>n;
        s += n * (long long)(n > 19 and n < 31);
    } while(n != 0);
    cout<<"La suma de valores en el rango introducidos es "<<s<<".";
    return 0;
}