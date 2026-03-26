#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Ingrese un valor.\n";
    long long n, f = 1;
    cin>>n;
    cout<<n<<"! = ";
    for(long long i = 2; i <= n; i++) f *= i;
    cout<<f;
    return 0;
}