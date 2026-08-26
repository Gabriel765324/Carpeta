#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol, Jaja, a;
void Crear(long long i, long long d, long long p){
    if(i == d){
        Jaja[i] = p;
        _rbol[p] = a[i];
        return;
    }
    long long P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
long long Consulta(long long i, long long d, long long p, long long u, long long v){
    if(i >= u and d <= v) return _rbol[p];
    if(i > v or d < u) return -0;
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, u, v) + Consulta(P + 1, d, p * 2 + 1, u, v);
}
void Actualizar(long long p, long long o, long long v){
    if(p == 0) return;
    if(p == o){
        _rbol[p] = v;
    } else _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
    Actualizar(p / 2, o, v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    for(long long Ayuda = 0; Ayuda < t; Ayuda++){
        long long n, m;
        cin>>n>>m;
        bool Primero = 1;
        a.assign(n + m + 22, 0);
        Jaja.assign(n + m + 22, 0);
        _rbol.assign((n + m + 22) * 4, 0);
        map<long long, long long> Posiciones;
        for(long long i = 0; i < n; i++){
            a[i] = 1;
            Posiciones[n - i] = i;
        }
        long long Cima = n;
        n = n + m + 21;
        Crear(0, n, 1);
        string Espacio = " ";
        for(long long i = 0; i < m; i++){
            if(i == m - 1) Espacio = "";
            long long q;
            cin>>q;
            cout<<Consulta(0, n, 1, Posiciones[q] + 1, a.size() - 1)<<Espacio;
            Actualizar(Jaja[Posiciones[q]], Jaja[Posiciones[q]], 0);
            Posiciones[q] = Cima;
            Actualizar(Jaja[Cima], Jaja[Cima], 1);
            Cima++;
        }
        /*if(Ayuda < t - 1)*/ cout<<"\n";
    }
    return 0;
}