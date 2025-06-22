#include "bits/stdc++.h"
using namespace std;
struct Nodo{
    long long Prefijo, Sufijo, Suma, Valor;
};
Nodo Combinar(Nodo a, Nodo b){
    Nodo c;
    c.Prefijo = max(a.Prefijo, a.Suma + b.Prefijo);
    c.Sufijo = max(b.Sufijo, b.Suma + a.Sufijo);
    c.Suma = a.Suma + b.Suma;
    c.Valor = max(a.Valor, max(b.Valor, a.Sufijo + b.Prefijo));
    return c;
}
vector<Nodo> _rbolh, _rbolv;
vector<long long> Jajah, Jajav, h, v;
void Crearh(long long i, long long d, long long p){
    if(i == d){
        _rbolh[p].Valor = max(0LL, h[i]);
        _rbolh[p].Prefijo = max(0LL, h[i]);
        _rbolh[p].Sufijo = max(0LL, h[i]);
        _rbolh[p].Suma = h[i];
        Jajah[d] = p;
        return;
    }
    long long P = (i + d) / 2;
    Crearh(i, P, p * 2);
    Crearh(P + 1, d, p * 2 + 1);
    _rbolh[p] = Combinar(_rbolh[p * 2], _rbolh[p * 2 + 1]);
}
void Crearv(long long i, long long d, long long p){
    if(i == d){
        _rbolv[p].Valor = max(0LL, v[i]);
        _rbolv[p].Prefijo = max(0LL, v[i]);
        _rbolv[p].Sufijo = max(0LL, v[i]);
        _rbolv[p].Suma = v[i];
        Jajav[d] = p;
        return;
    }
    long long P = (i + d) / 2;
    Crearv(i, P, p * 2);
    Crearv(P + 1, d, p * 2 + 1);
    _rbolv[p] = Combinar(_rbolv[p * 2], _rbolv[p * 2 + 1]);
}
long long Consulta(){
    //cout<<_rbolh[1].Valor<<" "<<_rbolv[1].Valor<<"\n";
    return _rbolh[1].Valor * _rbolv[1].Valor;
}
void Actualizarh(long long p, long long o){
    if(p == 0) return;
    if(p == o){
        _rbolh[p].Suma = -_rbolh.size() - 22;
        _rbolh[p].Prefijo = 0;
        _rbolh[p].Sufijo = 0;
        _rbolh[p].Valor = 0;
    } else _rbolh[p] = Combinar(_rbolh[p * 2], _rbolh[p * 2 + 1]);
    Actualizarh(p / 2, o);
}
void Actualizarv(long long p, long long o){
    if(p == 0) return;
    if(p == o){
        _rbolv[p].Suma = -_rbolv.size() - 22;
        _rbolv[p].Prefijo = 0;
        _rbolv[p].Sufijo = 0;
        _rbolv[p].Valor = 0;
    } else _rbolv[p] = Combinar(_rbolv[p * 2], _rbolv[p * 2 + 1]);
    Actualizarv(p / 2, o);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, q;
    cin>>n>>m>>q;
    n *= 2;
    m *= 2;
    v.assign(m, 0);
    Jajav = v;
    for(long long i = 0; i < m; i += 2) v[i] = 1;
    h.assign(n, 0);
    Jajah = h;
    for(long long i = 0; i < n; i += 2) h[i] = 1;
    n--;
    m--;
    long long nh = n, nv = m;
    Nodo E;
    E.Prefijo = -0;
    E.Sufijo = 0;
    E.Suma = +0;
    E.Valor = +0-0;
    _rbolh.assign((nh + 22) * 4, E);
    _rbolv.assign((nv + 22) * 4, E);
    Crearh(0, nh, 1);
    Crearv(0, nv, 1);
    //cout<<Consulta()<<"\n";
    while(q--){
        char t;
        long long c;
        cin>>t>>c;
        if(t == 'V'){
            h[1 + 2 * (c - 1)] = -_rbolh.size() - 22;
            Actualizarh(Jajah[1 + 2 * (c - 1)], Jajah[1 + 2 * (c - 1)]);
        } else {
            v[1 + 2 * (c - 1)] = -_rbolv.size() - 22;
            Actualizarv(Jajav[1 + 2 * (c - 1)], Jajav[1 + 2 * (c - 1)]);
        }
        /*for(auto E: h) cout<<E<<" ";
        cout<<"\n";
        for(auto E: v) cout<<E<<" ";
        cout<<"\n";*/
        cout<<Consulta()<<"\n";
    }
    return 0;
}