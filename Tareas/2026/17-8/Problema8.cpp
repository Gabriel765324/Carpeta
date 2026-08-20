#include "bits/stdc++.h"
using namespace std;
int main(){
    unsigned long long a, b, c;
    cout<<"Lado 1: ";
    cin>>a;
    cout<<"Lado 2: ";
    cin>>b;
    cout<<"Lado 3: ";
    cin>>c;
    if(a == b and b == c) cout<<"EQUILÁTERO.";
    else if(a != b and b != c and c != a) cout<<"ESCALENO.";
    else cout<<"ISÓSCELES.";
    return 0;
}