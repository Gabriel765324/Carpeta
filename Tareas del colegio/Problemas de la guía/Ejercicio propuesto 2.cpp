#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Ingrese un número.\n";
    long long a;
    cin>>a;
    if(a == 1 or a == 0){
        cout<<"No es primo.\n";
        return 0;
    }
    for(long long i = 2; (i * i) <= a; i++){
        if((a % i) == 0){
            cout<<"No es primo.";
            return 0;
        }
    }
    cout<<"Es primo.";
    return 0;
}