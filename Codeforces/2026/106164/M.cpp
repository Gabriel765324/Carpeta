#include "bits/stdc++.h"
using namespace std;
int n;
vector<int> _rbol;
int t(int i, int d){
    return 2 * (d - i + 1);
}
void Crear(int i, int d, int p){
    if(i == d){
        _rbol[p] = 1;
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p + 1);
    Crear(P + 1, d, p + t(i, P));
    _rbol[p] = _rbol[p + 1] + _rbol[p + t(i, P)];
}
int Suma(int i, int d, int p, int I, int D){
    if(D < I) return Suma(0, n - 1, 0, 0, D) + Suma(0, n - 1, 0, I, n - 1);
    if(I <= i and d <= D) return _rbol[p];
    if(i > D or I > d) return 0;
    int P = (i + d) / 2;
    return Suma(i, P, p + 1, I, D) + Suma(P + 1, d, p + t(i, P), I, D);
}
void Actualizar(int i, int d, int p, int a){
    if(i == d){
        _rbol[p] = 0;
        return;
    }
    if(i > a or d < a) return;
    int P = (i + d) / 2;
    if(P >= a) Actualizar(i, P, p + 1, a);
    else Actualizar(P + 1, d, p + t(i, P), a);
    _rbol[p] = _rbol[p + 1] + _rbol[p + t(i, P)];
}
int Buscar_siguiente(int i, int d, int p, int Falta){
    if(i == d) return i;
    int P = (i + d) / 2;
    if(_rbol[p + 1] >= Falta) return Buscar_siguiente(i, P, p + 1, Falta);
    return Buscar_siguiente(P + 1, d, p + t(i, P), Falta - _rbol[p + 1]);
}
int Normalizar(int i){
    return (i % n + n) % n;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    _rbol.assign(n * 2 + 22, 0);
    Crear(0, n - 1, 0);
    vector<int> Posiciones(n), r;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        Posiciones[a - 1] = i;
    }
    int Inicio = 0;
    for(int i = n - 1; i > -1; i--){
        r.push_back(Suma(0, n - 1, 0, Posiciones[i], Normalizar(Inicio - 1)));
        Actualizar(0, n - 1, 0, Posiciones[i]);
        if(Suma(0, n - 1, 0, Posiciones[i], n - 1) >= 1) Inicio = Buscar_siguiente(0, n - 1, 0, Suma(0, n - 1, 0, 0, Posiciones[i]) + 1);
        else Inicio = Buscar_siguiente(0, n - 1, 0, 1);
        /*for(int j = 0; j < n; j++){
            cerr<<Suma(0, n - 1, 0, j, j)<<" ";
        }
        cerr<<"\n"<<Inicio<<"\n";*/
    }
    reverse(r.begin(), r.end());
    for(auto E: r) cout<<E<<" ";
    cout<<"\n";
    return 0;
}