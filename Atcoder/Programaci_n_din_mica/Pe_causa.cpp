#include "bits/stdc++.h"
using namespace std;
struct M_dulo{
    long long v, m;
    M_dulo(long long a){
        m = 1000000007;
        v = a % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo((v % m + a.v % m) % m);
    }
    M_dulo operator*(const M_dulo& a){
        return M_dulo((v % m * a.v % m) % m);
    }
    bool operator!=(const M_dulo& a){
        return a.v != v;
    }
};
vector< vector<int> > Grafo;
vector< vector<M_dulo> > PD;
M_dulo Resolver(int Nodo, int Anterior, bool Blanco){
    if(PD[Nodo][Blanco] != M_dulo(-2)) return PD[Nodo][Blanco];
    M_dulo r = M_dulo(1);
    for(auto E: Grafo[Nodo]){
        if(E == Anterior) continue;
        M_dulo Nuevo = Resolver(E, Nodo, 1);
        if(Blanco) Nuevo = Nuevo + Resolver(E, Nodo, 0);
        r = r * Nuevo;
    }
    return PD[Nodo][Blanco] = r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    Grafo.assign(n, {});
    PD.assign(n + 2, vector<M_dulo>(2, M_dulo(-2)));
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    cout<<(Resolver(0, -2, 0) + Resolver(0, -2, 1)).v;
    return 0;
}