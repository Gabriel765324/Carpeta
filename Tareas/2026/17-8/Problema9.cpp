#include "bits/stdc++.h"
using namespace std;
int main(){
    unsigned long long A_o;
    cout<<"Ingrese el año: ";
    cin>>A_o;
    cout<<"AÑO ";
    if(A_o % (unsigned long long)4 != (unsigned long long)0 or (A_o % (unsigned long long)100 == (unsigned long long)0 and A_o % (unsigned long long)400 != (unsigned long long)0)) cout<<"NO ";
    cout<<"BISIESTO.";
    return 0;
}