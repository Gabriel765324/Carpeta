#include "bits/stdc++.h"
using namespace std;
bitset<262144> Posibles;
bitset<262144> Multiplicar(int Desplazar, int Factor){
    if(Factor == 0) return Posibles;
    if(Factor == 1) return Posibles | Posibles>>Desplazar;
    bitset<262144> a = Multiplicar(Desplazar, Factor / 2);
    a |= a>>(Desplazar * (Factor / 2));
    if(Factor & 1 == 1) a |= a>>(Desplazar * ((Factor / 2) * 2));
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m = 0, Suma = 0;
    cin>>n;
    vector<int> a(n);
    map<int, int> Mapa;
    bool Cero = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        Cero = Cero or a[i] == 0;
        Suma += a[i];
        a[i] *= 2;
        Mapa[a[i]]++;
        int b;
        cin>>b;
        m = __gcd(m, b);
    }
    if(Cero and Suma % m == 0){
        cout<<"Y";
        return 0;
    }
    vector<int> Valores, M_ximo;
    Posibles[Suma] = 1;
    for(auto E: Mapa){
        if(E.first != 0){
            Posibles = Multiplicar(E.first, E.second);
            /*for(int i = 0; i <= Suma; i++) cerr<<Posibles[i]<<" ";
            cerr<<"\n";*/
        }
    }
    for(int i = 0; i < Suma; i += m){
        if(Posibles[i]){
            cout<<"Y";
            return 0;
        }
    }
    cout<<"N";
    return 0;
}