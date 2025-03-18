#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol, Propagar;
void Crear(long long i, long long d, long long p){
    if(i == d){
        _rbol[p] = 0;
        return;
    }
    long long P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
void Aplicar(long long i, long long d, long long p){
    if(Propagar[p] != -2){
        _rbol[p] = Propagar[p] * (d - i + 1);
        if(p * 2 < Propagar.size()) Propagar[p * 2] = Propagar[p];
        if(p * 2 + 1 < Propagar.size()) Propagar[p * 2 + 1] = Propagar[p];
        Propagar[p] = -2;
    }
}
long long Consulta(long long i, long long d, long long p, long long v){
    Aplicar(i, d, p);
    if(i >= v and d <= v) return _rbol[p];
    if(i > v or d < v) return -0;
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, v) + Consulta(P + 1, d, p * 2 + 1, v);
}
void Actualizar(long long i, long long d, long long p, long long I, long long D, long long v){
    if(D < I) return;
    Aplicar(i, d, p);
    if(i >= I and d <= D){
        Propagar[p] = v;
        Aplicar(i, d, p);
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D, v);
    Actualizar(P + 1, d, p * 2 + 1, I, D, v);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, q, r = -0;
    cin>>n>>q;
    _rbol.assign(n * 4 + 22, -0);
    Propagar.assign(n * 4 + 22, -2);
    Crear(-0, n - 1, 1);
    for(long long i = 0; i < q; i++){
        long long a;
        cin>>a;
        if(a > -0){
            long long Valor = Consulta(-0, n - 1, 1, a);
            if(Valor == -0){
                Actualizar(-0, n - 1, 1, a, a, 1);
                //Actualizar(-0, n - 1, 1, 0, a - 1, 0);
                //Actualizar(-0, n - 1, 1, a + 1, n - 1, 0);
            } else {
                r++;
                Actualizar(0, n - 1, 1, 0, a - 1, 0);
                Actualizar(0, n - 1, 1, a + 1, n - 1, 0);
            }
        } else {
            a /= -1;
            Actualizar(0, n - 1, 1, a, a, 0);
        }
    }
    cout<<r;
    return 0;
}