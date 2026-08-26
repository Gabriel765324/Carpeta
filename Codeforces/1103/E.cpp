#include "bits/stdc++.h"
using namespace std;
vector<bool> _rbol;
int Tama_o(int i, int d){
    return 2 * (d - i + 1);
}
bool Consulta(int i, int d, int p, int I, int D){
    if(I > D) return 1;
    if(I <= i and d <= D) return _rbol[p];
    if(D < i or d < I) return 1;
    int P = (i + d) / 2;
    return Consulta(i, P, p + 1, I, D) and Consulta(P + 1, d, p + Tama_o(i, P), I, D);
}
void Actualizar(int i, int d, int p, int a){
    if(i == d){
        _rbol[p] = !_rbol[p];
        return;
    }
    int P = (i + d) / 2;
    if(a <= P) Actualizar(i, P, p + 1, a);
    else Actualizar(P + 1, d, p + Tama_o(i, P), a);
    _rbol[p] = _rbol[p] and _rbol[p + Tama_o(i, P)];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, r = 0;
        cin>>n;
        vector<int> a(n);
        vector<int> M_s_largo_derecha(n, 0), M_s_largo_izquierda(n, 0);
        for(int i = 0; i < n; i++){
            cin>>a[i];
            a[i]--;
        }

    }
    return 0;
}