#include "bits/stdc++.h"
using namespace std;
int main(){
    freopen("01.out", "r", stdin);
    vector<long long> Verificar;
    long long a;
    while(cin>>a) Verificar.push_back(a);
    vector<long long> _01, _01F;
    for(long long i = 0; i < Verificar.size(); i++){
        if(i < Verificar.size() / 2) _01.push_back(Verificar[i]);
        else _01F.push_back(Verificar[i]);
    }
    if(_01 == _01F) cout<<"Correcto.";
    else cout<<"Incorrecto.";
    return 0;
}