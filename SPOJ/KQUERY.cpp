#include "bits/stdc++.h"
using namespace std;
vector<long long> a;
vector< vector<long long> > _rbol;
void Crear(long long Izquierda, long long Derecha, long long Posici_n){
    if(Izquierda == Derecha){
        _rbol[Posici_n] = {a[Izquierda]};
    } else {
        long long Promedio = (Izquierda + Derecha) / 2;
        Crear(Izquierda, Promedio, Posici_n * 2);
        Crear(Promedio + 1, Derecha, Posici_n * 2 + 1);
        long long i = 0, j = 0;
        vector<long long> G;
        while(i < _rbol[Posici_n * 2].size() or j < _rbol[Posici_n * 2 + 1].size()){
            if(i == _rbol[Posici_n * 2].size()){
                G.push_back(_rbol[Posici_n * 2 + 1][j]);
                j++;
            } else if(j == _rbol[Posici_n * 2 + 1].size()){
                G.push_back(_rbol[Posici_n * 2][i]);
                i++;
            } else {
                if(_rbol[Posici_n * 2][i] < _rbol[Posici_n * 2 + 1][j]){
                    G.push_back(_rbol[Posici_n * 2][i]);
                    i++;
                } else {
                    G.push_back(_rbol[Posici_n * 2 + 1][j]);
                    j++;
                }
            }
        }
        _rbol[Posici_n] = G;
    }
}
long long Consulta(long long Izquierda, long long Derecha, long long Posici_n, long long Inicio, long long Final, long long k){
    long long Promedio = (Izquierda + Derecha) / 2;
    if(Izquierda > Final or Derecha < Inicio) return 0;
    if(Izquierda >= Inicio and Derecha <= Final){
        return _rbol[Posici_n].size() - (upper_bound(_rbol[Posici_n].begin(), _rbol[Posici_n].end(), k) - _rbol[Posici_n].begin());
    }
    return Consulta(Izquierda, Promedio, Posici_n * 2, Inicio, Final, k) + Consulta(Promedio + 1, Derecha, Posici_n * 2 + 1, Inicio, Final, k);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n;
    a.assign(n, 0);
    _rbol.assign(n * 4, vector<long long>());
    for(long long i = 0; i < n; i++){
        cin>>a[i];
    }
    n--;
    Crear(0, n, 1);
    cin>>m;
    while(m--){
        long long i, j, k;
        cin>>i>>j>>k;
        i--;
        j--;
        cout<<Consulta(0, n, 1, i, j, k)<<"\n";
    }
    return 0;
}