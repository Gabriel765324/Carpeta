#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Introduzca 3 números.\n";
    long long a, b, c;
    cin>>a>>b>>c;
    cout<<"El mayor es "<<max(a, max(b, c))<<".";
    return 0;
}