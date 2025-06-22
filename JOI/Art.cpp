#include "bits/stdc++.h"
using namespace std;
struct Obra{
    long long Tama_o, Valor;
};
bool operator<(const Obra& a, const Obra& b){
    if(a.Tama_o < b.Tama_o) return 1;
    if(b.Tama_o < a.Tama_o) return 0;
    return a.Valor > b.Valor;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector<Obra> a(n);
    for(long long i = 0; i < n; i++) cin>>a[i].Tama_o>>a[i].Valor;
    sort(a.begin(), a.end());
    long long Mejor, Suma, i = 0;
    for(long long d = 0; d < n; d++){
        if(d == 0){
            Mejor = a[d].Valor;
            Suma = a[d].Valor;
            continue;
        }
        if(Suma + a[i].Tama_o - a[d].Tama_o >= 0) Suma += a[d].Valor;
        else {
            Suma = a[d].Valor;
            i = d;
        }
        Mejor = max(Mejor, Suma + a[i].Tama_o - a[d].Tama_o);
    }
    cout<<Mejor;
    return 0;
}