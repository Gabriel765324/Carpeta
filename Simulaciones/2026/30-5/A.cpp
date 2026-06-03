#include "bits/stdc++.h"
using namespace std;
bitset<800022> _rbol;
vector<int> Propagar;
void Progando(int i, int d, int p){
    if(Propagar[p] == -2) return;
    _rbol[p] = Propagar[p];
    if(i != d){
        Propagar[p * 2] = Propagar[p];
        Propagar[p * 2 + 1] = Propagar[p];
    }
    Propagar[p] = -2;
}
bool Consulta(int i, int d, int p, int c){
    Progando(i, d, p);
    if(i == d and d == c) return _rbol[p];
    if(i > c or d < c) return 0;
    int P = (i + d) / 2;
    return Consulta(i, P, p * 2, c) or Consulta(P + 1, d, p * 2 + 1, c);
}
void Actualizar(int i, int d, int p, int I, int D, int v){
    if(D < I) return;
    Progando(i, d, p);
    if(I <= i and d <= D){
        Propagar[p] = v;
        Progando(i, d, p);
        return;
    }
    if(D < i or d < I) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D, v);
    Actualizar(P + 1, d, p * 2 + 1, I, D, v);
    _rbol[p] = _rbol[p * 2] or _rbol[p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    Propagar.assign(n * 4 + 22, -2);
    int v = 0;
    while(q--){
        int a;
        cin>>a;
        if(a > 0){
            if(Consulta(0, n - 1, 1, a)){
                v++;
                Actualizar(0, n - 1, 1, 0, a - 1, 0);
                Actualizar(0, n - 1, 1, a + 1, n - 1, 0);
            } else {
                Actualizar(0, n - 1, 1, a, a, 1);
            }
        } else {
            Actualizar(0, n - 1, 1, -a, -a, 0);
        }
    }
    cout<<v;
    return 0;
}