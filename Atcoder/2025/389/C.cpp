#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol, Serpientes, Jaja;
void Crear(long long i, long long d, long long p){
    if(i == d){
        Jaja[i] = p;
        _rbol[p] = Serpientes[i];
        return;
    }
    long long P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
long long Consulta(long long i, long long d, long long p, long long I, long long D){
    if(i > d) return 0;
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return -0;
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(long long p, long long o, long long v){
    if(p == 0) return;
    if(p == o) _rbol[p] = v;
    else _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
    Actualizar(p / 2, o, v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long q, _ltimo = 0, Primero = 0;
    long long n = 300022;
    _rbol.assign(n * 4, 0);
    Serpientes.assign(n, 0);
    Jaja.assign(n, 0);
    n--;
    Crear(0, n, 1);
    cin>>q;
    while(q--){
        long long t;
        cin>>t;
        if(t == 1){
            long long l;
            cin>>l;
            Actualizar(Jaja[_ltimo], Jaja[_ltimo], l);
            _ltimo++;
        } else if(t == 2){
            Actualizar(Jaja[Primero], Jaja[Primero], 0);
            Primero++;
        } else {
            long long k;
            cin>>k;
            cout<<Consulta(0, n, 1, 0, Primero + k - 2)<<"\n";
        }
        //for(long long i = 0; i < 22; i++) cout<<Consulta(0, n, 1, i, i)<<" ";
        //cout<<"\n";
    }
    return 0;
}