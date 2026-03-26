#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Ingrese su altura en centímetros y su peso en kilogramos.\n";
    double h, W, p;
    cin>>h>>W;
    h /= (double)100;
    p = W / (h * h);
    cout<<"Su índice de masa corporal es "<<p<<", tiene ";
    if(p < (double)15) cout<<"delgadez muy severa.";
    else if(p < (double)16) cout<<"delgadez severa.";
    else if(p < 18.5) cout<<"delgadez.";
    else if(p < (double)25) cout<<"un peso saludable.";
    else if(p < (double)30) cout<<"sobrepeso.";
    else if(p < (double)35) cout<<"obesidad moderada.";
    else if(p < (double)40) cout<<"obesidad severa.";
    else cout<<"obesidad muy severa.";
    return 0;
}