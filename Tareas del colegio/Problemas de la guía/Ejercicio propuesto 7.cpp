#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Ingrese un valor.\n";
    long long n;
    cin>>n;
    cout<<"La suma de los "<<n<<" primeros números es "<<n * (n + 1) / 2<<".";
    return 0;
} //La fórmula n * (n + 1) / 2 puede calcular la suma velozmente.