#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol, Propagar;
long long Consulta(long long i, long long d, long long p, long long I, long long D){
    long long r = d - i + 1;
    if(Propagar[p] != 0){
        _rbol[p] += Propagar[p] * r;
        if(p * 2 < _rbol.size()){
            Propagar[p * 2] += Propagar[p];
        }
        if(p * 2 + 1 < _rbol.size()){
            Propagar[p * 2 + 1] += Propagar[p];
        }
        Propagar[p] = 0;
    }
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return -0;
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(long long i, long long d, long long p, long long I, long long D){
    long long r = d - i + 1;
    if(Propagar[p] != 0){
        _rbol[p] += Propagar[p] * r;
        if(p * 2 < _rbol.size()){
            Propagar[p * 2] += Propagar[p];
        }
        if(p * 2 + 1 < _rbol.size()){
            Propagar[p * 2 + 1] += Propagar[p];
        }
        Propagar[p] = 0;
    }
    if(i >= I and d <= D){
        Propagar[p]++;
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D);
    Actualizar(P + 1, d, p * 2 + 1, I, D);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, h, Mejor = 2222222222222222, Veces = 0;
    cin>>n>>h;
    _rbol.assign((h + 22) * 4, 0);
    Propagar.assign((h + 22) * 4, 0);
    h--;
    for(long long i = 0; i < n; i++){
        long long a;
        cin>>a;
        if(i % 2 == 0) Actualizar(0, h, 1, 0, a - 1);
        else Actualizar(0, h, 1, h - a + 1, h);
    }
    for(long long i = 0; i <= h; i++){
        long long Romper = Consulta(0, h, 1, i, i);
        if(Romper < Mejor){
            Mejor = Romper;
            Veces = 1;
        } else if(Mejor == Romper) Veces++;
    }
    cout<<Mejor<<" "<<Veces;
    return 0;
}