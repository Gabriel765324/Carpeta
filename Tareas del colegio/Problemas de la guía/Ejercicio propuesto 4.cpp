#include "bits/stdc++.h"
using namespace std;
int main(){
    long long n;
    do{
        cout<<"Ingrese un número del 1 al 10.\n";
        cin>>n;
    } while(n < 1 or n > 10);
    for(int i = 1; i < 11; i++){
        cout<<i<<" * "<<n<<" = "<<i * n<<"\n";
    }
    return 0;
}