#include "bits/stdc++.h"
using namespace std;
int main(){
    unsigned long long Monto;
    cout<<"Monto a retirar: ";
    cin>>Monto;
    for(unsigned long long x: {(unsigned long long)100, (unsigned long long)50, (unsigned long long)20, (unsigned long long)10}){
        if(Monto >= x){
            cout<<"Billetes de "<<x<<" bolivianos: "<<Monto / x<<".\n";
            Monto %= x;
        }
    }
    return 0;
}