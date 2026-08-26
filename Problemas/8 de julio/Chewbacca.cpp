#include "bits/stdc++.h"
using namespace std;
long long Potencia(long long b, long long e){
    if(e == 0) return 1;
    if(e == 1) return b;
    long long a = Potencia(b, e / 2);
    a *= a * Potencia(b, e % 2);
    return a;
}
deque<long long> Ancestros(long long Nodo, long long k){
    long long Capa, Suma = 1, _ltimo = 0;
    for(Capa = 1; Suma < Nodo; Capa++){
        Suma += Potencia(k, Capa);
        _ltimo = Potencia(k, Capa);
    }
    Suma -= _ltimo;
    Nodo -= Suma;
    deque<long long> r;
    while(r.size() < Capa){
        r.push_front(Nodo);
        Nodo = (Nodo + k - 1) / k;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k, q;
    cin>>n>>k>>q;
    while(q--){
        long long x, y;
        cin>>x>>y;
        if(k == 1){
            cout<<abs(x - y)<<"\n";
            continue;
        }
        deque<long long> Ancestrosx = Ancestros(x, k), Ancestrosy = Ancestros(y, k);
        for(int i = 0; i <= min(Ancestrosx.size(), Ancestrosy.size()); i++){
            if(i == min(Ancestrosx.size(), Ancestrosy.size()) or Ancestrosx[i] != Ancestrosy[i]){
                cout<<Ancestrosx.size() + Ancestrosy.size() - i<<"\n";
            }
        }
    }
    return 0;
}