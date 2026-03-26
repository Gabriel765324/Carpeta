#include "bits/stdc++.h"
using namespace std;
vector<int> _rbol;
int Consulta(int i, int d, int p, int k){
    if(i == d) return i;
    int P = (i + d) / 2;
    if(_rbol[p * 2 + 1] >= k) return Consulta(P + 1, d, p * 2 + 1, k);
    return Consulta(i, P, p * 2, k - _rbol[p * 2 + 1]);
}
void Actualizar(int i, int d, int p, int I){
    if(i == d and d == I){
        _rbol[p] = 1;
        return;
    }
    if(i > I or d < I) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, I);
    Actualizar(P + 1, d, p * 2 + 1, I);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    set<int> r;
    vector<int> a(n);
    _rbol.assign(n * 4 + 22, 0);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]--;
    }
    for(int i = 0; i < k - 1; i++) Actualizar(0, n - 1, 1, a[i]);
    for(int i = k - 1; i < n; i++){
        Actualizar(0, n - 1, 1, a[i]);
        cout<<Consulta(0, n - 1, 1, k) + 1<<"\n";
    }
    return 0;
}