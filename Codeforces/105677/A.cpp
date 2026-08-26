#include "bits/stdc++.h"
using namespace std;
struct Valor{
    long long Mayor, Suma, Prefijo, Sufijo, Propagar;
    Valor(){
        Propagar = 0;
    }
    Valor(long long a){
        Mayor = max(0LL, a);
        Prefijo = max(0LL, a);
        Sufijo = max(0LL, a);
        Suma = a;
        Propagar = 0;
    }
    Valor(long long a, long long b, long long c, long long d){
        Mayor = a;
        Suma = b;
        Prefijo = c;
        Sufijo = d;
        Propagar = 0;
    }
    Valor operator+(const Valor& a){
        Valor r;
        r.Suma = this->Suma + a.Suma;
        r.Prefijo = max(this->Prefijo, this->Suma + a.Prefijo);
        r.Sufijo = max(a.Sufijo, a.Suma + this->Sufijo);
        r.Mayor = max(max(this->Mayor, a.Mayor), this->Sufijo + a.Prefijo);
        return r;
    }
};
vector<Valor> _rbol;
vector<long long> a;
int t(int i, int d){
    return 2 * (d - i + 1);
}
void Crear(int i, int d, int p){
    if(i == d){
        _rbol[p] = Valor(a[i]);
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p + 1);
    Crear(P + 1, d, p + t(i, P));
    _rbol[p] = _rbol[p + 1] + _rbol[p + t(i, P)];
}
void Propagar(int i, int d, int p){
    _rbol[p].Suma += (long long)(d - i + 1) * _rbol[p].Propagar;
    if(i == d){
        _rbol[p] = Valor(_rbol[p].Suma);
        return;
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    
    return 0;
}