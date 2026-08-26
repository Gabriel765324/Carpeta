#include "bits/stdc++.h"
using namespace std;
struct M_dulo{
    long long v, m;
    M_dulo(long long a, long long b){
        m = b;
        v = a % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo((v % m + a.v % m) % m, m);
    }
    M_dulo operator-(const M_dulo& a){
        return M_dulo(((v % m - a.v % m) % m + m) % m, m);
    }
    M_dulo operator*(const M_dulo& a){
        return M_dulo((v % m * a.v % m) % m, m);
    }
};
vector< vector<int> > Grafo;
vector<M_dulo> PD, Respuestas;
vector< vector<M_dulo> > _rbol;
vector<int> t;
long long m;
void Actualizar(int ID, int i, int d, int p, int I, M_dulo v){
    if(d < i) return;
    if(i == I and d == I){
        _rbol[ID][p] = v;
        return;
    }
    if(i > I or d < I) return;
    int P = (i + d) / 2;
    Actualizar(ID, i, P, p * 2, I, v);
    Actualizar(ID, P + 1, d, p * 2 + 1, I, v);
    _rbol[ID][p] = _rbol[ID][p * 2] * _rbol[ID][p * 2 + 1];
}
void Resolver(int Nodo, int Anterior){
    t[Nodo] = Grafo[Nodo].size() + 4;
    _rbol[Nodo].assign(t[Nodo] * 4 + 22, M_dulo(1, m));
    if(Grafo[Nodo].size() == 1 and Nodo != 0){
        PD[Nodo] = M_dulo(2, m);
        return;
    }
    int i = 0;
    for(auto E: Grafo[Nodo]){
        if(E == Anterior){
            i++;
            continue;
        }
        Resolver(E, Nodo);
        PD[Nodo] = PD[Nodo] * PD[E];
        Actualizar(Nodo, 0, t[Nodo] - 1, 1, i, PD[E]);
        i++;
    }
    PD[Nodo] = PD[Nodo] + M_dulo(1, m);
    return;
}
void Reraizeando(int Nodo, int Anterior){
    Respuestas[Nodo] = PD[Nodo] - M_dulo(1, m);
    int i = 0;
    for(auto E: Grafo[Nodo]){
        if(E == Anterior){
            i++;
            continue;
        }
        M_dulo Volver = PD[E];
        Actualizar(Nodo, 0, t[Nodo] - 1, 1, i, M_dulo(1, m));
        PD[Nodo] = _rbol[Nodo][1] + M_dulo(1, m);
        Actualizar(E, 0, t[E] - 1, 1, t[E] - 1, PD[Nodo]);
        PD[E] = _rbol[E][1] + M_dulo(1, m);
        Reraizeando(E, Nodo);
        Actualizar(Nodo, 0, t[Nodo] - 1, 1, i, Volver);
        PD[Nodo] = _rbol[Nodo][1] + M_dulo(1, m);
        Actualizar(E, 0, t[E] - 1, 1, t[E] - 1, M_dulo(1, m));
        PD[E] = _rbol[E][1] + M_dulo(1, m);
        i++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>m;
    Grafo.assign(n, {});
    PD.assign(n, M_dulo(1, m));
    t.assign(n, 0);
    _rbol.assign(n + 2, {});
    Respuestas.assign(n, M_dulo(2222, m));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    Resolver(0, -2);
    Reraizeando(0, -2);
    for(auto E: Respuestas) cout<<E.v<<"\n";
    return 0;
}