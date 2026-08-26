#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol;
long long Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return 0;
    int P = (i + d) / 2;
    return max(Consulta(i, P, p * 2, I, D), Consulta(P + 1, d, p * 2 + 1, I, D));
}
void Actualizar(int i, int d, int p, int I, long long v){
    if(i >= I and d <= I){
        _rbol[p] = v;
        return;
    }
    if(i > I or d < I) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, v);
    Actualizar(P + 1, d, p * 2 + 1, I, v);
    _rbol[p] = max(_rbol[p * 2], _rbol[p * 2 + 1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    _rbol.assign(n * 4 + 22, 0);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]--;
    }
    for(int i = 0; i < n; i++){
        long long b;
        cin>>b;
        Actualizar(0, n - 1, 1, a[i], Consulta(0, n - 1, 1, 0, a[i]) + b);
    }
    cout<<_rbol[1];
    return 0;
}