#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n>>m;
    bool Infinito = 0;
    long long Suma = 0, Base = 1;
    for(int i = 0; i <= m; i++){
        Suma += Base;
        if(Suma > 1e9){
            Infinito = 1;
            break;
        }
        Base *= n;
        if(i < m and Base > 1e9){
            Infinito = 1;
            break;
        }
    }
    if(Infinito) cout<<"inf";
    else cout<<Suma;
    return 0;
}