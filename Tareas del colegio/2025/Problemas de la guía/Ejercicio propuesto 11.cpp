#include "bits/stdc++.h"
using namespace std;
int main(){
    cout<<"Ingrese un número.\n";
    long long n;
    cin>>n;
    cout<<n<<" tiene ";
    if(n == 0) cout<<1;
    else cout<<(long long)log10(n) + 1LL;
    cout<<" dígito(s).";
    return 0;
}