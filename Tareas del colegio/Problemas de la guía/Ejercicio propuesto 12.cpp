#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Ingrese un número.\n";
    long long n;
    cin>>n;
    if(n < 10) return 0;
    cout<<(n - (n % 10LL)) / 10LL;
    return 0;
}