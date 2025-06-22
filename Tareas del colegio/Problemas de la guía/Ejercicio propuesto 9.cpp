#include "bits/stdc++.h"
using namespace std;
long long p(long long b, long long e){
    if(e == 0) return 1LL;
    if(e == 1) return b;
    long long a = p(b, e / 2);
    a *= a;
    if((e % 2) == 1) a *= b;
    return a;
}
int main(){
    cout<<"Ingrese un valor.\n";
    long long n;
    cin>>n;
    cout<<"La suma de las "<<n<<" primeras potencias de 2 es "<<p(2LL, n + 1LL) - 2LL<<".";
    return 0;
} //La fórmula 2 + 2^2 + ... + 2^n = 2^(n + 1) - 2 es útil, pero usar potenciación binaria deja correr el código aun más rápido.