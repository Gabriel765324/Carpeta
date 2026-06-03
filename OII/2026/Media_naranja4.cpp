#include "bits/stdc++.h"
using namespace std;
struct Rango{
    int l, r;
    Rango(){}
    bool operator<(const Rango& a){
        if(r - l < a.r - a.l) return 1;
        if(r - l > a.r - a.l) return 0;
        if(l < a.l) return 1;
        if(l > a.l) return 0;
        return r < a.r;
    }
};
vector<long long> _rbol(4222222, 0);
int t(int i, int d){
    return (d - i + 1) << 1;
}
int P;
long long Consulta(int i, int d, int p, int I, int D){
    if(I <= i and d <= D) return _rbol[p];
    if(i > D or d < I) return 0;
    int m = (i + d) >> 1;
    return Consulta(i, m, p + 1, I, D) + Consulta(m + 1, d, p + t(i, m), I, D);
}
void Actualizar(int i, int d, int p){
    if(i == P and d == P){
        _rbol[p]++;
        return;
    }
    if(i > P or d < P) return;
    int m = (i + d) >> 1;
    if(P <= m) Actualizar(i, m, p + 1);
    else Actualizar(m + 1, d, p + t(i, m));
    _rbol[p]++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Rango> q(n);
    for(int i = 0; i < n; i++){
        cin>>q[i].l>>q[i].r;
        q[i].l <<= 1;
        q[i].r <<= 1;
    }
    sort(q.rbegin(), q.rend());
    long long r = 0;
    for(int i = 0; i < n; i++){
        r += Consulta(0, 2000022, 0, q[i].l, q[i].r);
        P = (q[i].l + q[i].r) >> 1;
        Actualizar(0, 2000022, 0);
    }
    cout<<r;
    return 0;
}