#include "bits/stdc++.h"
using namespace std;
#define el "\n"
void Resolver(){
    long long n, c = 0, d = 1, v = 9;
    cin>>n;
    //n = vvvv;
    while(1){
        if(d * v >= n) break;
        n -= d * v;
        c += v;
        v *= 10LL;
        d++;
    }
    long long Valor = (n + d - 1LL) / d + c;
    //cerr<<n<<" n0."<<el;
    n = (n + d - 1LL) % d;
    //cerr<<Valor<<" Valor. "<<n<<" n."<<el;
    string s;
    stringstream Conversor;
    Conversor<<Valor;
    Conversor>>s;
    cout<<s[n]<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--) Resolver();
    //for(long long v = 1; v <= 200; v++) Resolver(v);
    return 0;
}