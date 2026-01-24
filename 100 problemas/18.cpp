#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long k;
    __int128 r = 1, Diez = 1;
    cin>>n>>k;
    while(k--){
        Diez *= (__int128)10;
    }
    while(n--){
        long long a;
        cin>>a;
        __int128 Copia = a;
        r *= Copia;
        if(r >= Diez) r = 1;
    }
    cout<<(long long)r;
    return 0;
}