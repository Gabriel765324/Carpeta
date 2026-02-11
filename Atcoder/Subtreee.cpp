#include "bits/stdc++.h"
using namespace std;
long long m;
long long S(long long a, long long b){
    return (a % m + b % m) % m;
}
long long R(long long a, long long b){
    return ((a % m - b % m) % m + m) % m;
}
long long M(long long a, long long b){
    return (a % m * b % m) % m;
}
vector<long long> PD, r;
vector< vector<int> > Grafo, Arreglos;
vector< vector<long long> > _rbol;
void Crear__rbol(int i, int d, int p, int n){
    if (i == d){
        _rbol[n][p] = Arreglos[n][i] % m;
        return;
    }
    int P = (i + d) / 2;
    Crear__rbol(i, P, p * 2, n);
    Crear__rbol(P + 1, d, p * 2 + 1, n);
    _rbol[n][p] = M(_rbol[n][p * 2], _rbol[n][p * 2 + 1]);
}
long long Consulta(int i, int d, int p, int I, int D, int n){
    if (I > D) return 1 % m;
    if (i >= I and d <= D) return _rbol[n][p] % m;
    if (i > D or d < I) return 1 % m;
    int P = (i + d) / 2;
    return M(Consulta(i, P, p * 2, I, D, n), Consulta(P + 1, d, p * 2 + 1, I, D, n));
}
void Actualizar(int i, int d, int p, int I, int n, long long v){
    if (i == I and d == I){
        _rbol[n][p] = v % m;
        return;
    }
    if(i > I or d < I) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, n, v);
    Actualizar(P + 1, d, p * 2 + 1, I, n, v);
    _rbol[n][p] = M(_rbol[n][p * 2], _rbol[n][p * 2 + 1]);
}
long long Crear(int Nodo, int Anterior){
    //cerr<<Nodo<<" n\n";
    long long p = 1;
    for (auto E : Grafo[Nodo]){
        if(E != Anterior){
            Arreglos[Nodo].push_back(S(Crear(E, Nodo), 1));
            p = M(p, Arreglos[Nodo].back());
        }
        else {
            Arreglos[Nodo].push_back(1 % m);
        }
    }
    Arreglos[Nodo].push_back(1 % m);
    _rbol[Nodo].assign(4 * Arreglos[Nodo].size() + 2, 0);
    Crear__rbol(0, Arreglos[Nodo].size() - 1, 1, Nodo);
    return PD[Nodo] = p;
}
void Resolver(int Nodo, int Anterior){
    long long Devolver = PD[Nodo];
    PD[Nodo] = Consulta(0, Arreglos[Nodo].size() - 1, 1, 0, Arreglos[Nodo].size() - 1, Nodo);
    long long Actual = PD[Nodo] % m;
    r[Nodo] = Actual;
    for(int i = 0; i < Grafo[Nodo].size(); i++){
        if(Grafo[Nodo][i] == Anterior){
            continue;
        }
        int Siguiente = Grafo[Nodo][i];
        long long Restaurar = PD[Siguiente];
        PD[Nodo] = M(Consulta(0, Arreglos[Nodo].size() - 1, 1, 0, i - 1, Nodo), Consulta(0, Arreglos[Nodo].size() - 1, 1, i + 1, Arreglos[Nodo].size() - 1, Nodo));
        Actualizar(0, Arreglos[Siguiente].size() - 1, 1, Arreglos[Siguiente].size() - 1, Siguiente, S(PD[Nodo], 1));
        Resolver(Siguiente, Nodo);
        Actualizar(0, Arreglos[Siguiente].size() - 1, 1, Arreglos[Siguiente].size() - 1, Siguiente, 1);
        PD[Nodo] = Devolver;
    }
    PD[Nodo] = Devolver;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n>>m;
    PD.assign(n, 0);
    r = PD;
    Grafo.assign(n, {});
    _rbol.assign(n, {});
    Arreglos.assign(n, {});
    n--;
    while(n--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    Crear(0, 0);
    Resolver(0, 0);
    for(auto E : r) cout<<E % m<<"\n";
    return 0;
}