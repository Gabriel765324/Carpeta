#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol(200022, 0), Propagar(200022, -2);
int Tama_o(int i, int d){
    return 2 * (d - i + 1);
}
void Propagando(int i, int d, int p){
    if(Propagar[p] == -2) return;
    _rbol[p] = Propagar[p];
    if(i != d){
        int P = (i + d) / 2;
        Propagar[p + 1] = Propagar[p];
        Propagar[p + Tama_o(i, P)] = Propagar[p];
    }
    Propagar[p] = -2;
}
long long Consulta(int i, int d, int p, int I, int D){
    Propagando(i, d, p);
    if(I <= i and d <= D) return _rbol[p];
    if(d < I or D < i) return -2;
    int P = (i + d) / 2;
    return max(Consulta(i, P, p + 1, I, D), Consulta(P + 1, d, p + Tama_o(i, P), I, D));
}
void Actualizar(int i, int d, int p, int I, int D, long long v){
    Propagando(i, d, p);
    if(I <= i and d <= D){
        Propagar[p] = v;
        Propagando(i, d, p);
        return;
    }
    if(d < I or D < i) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p + 1, I, D, v);
    Actualizar(P + 1, d, p + Tama_o(i, P), I, D, v);
    _rbol[p] = max(_rbol[p + 1], _rbol[p + Tama_o(i, P)]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long t = 0;
    vector<long long> r(n), k(n);
    for(int i = 0; i < n; i++) cin>>r[i];
    for(int i = 0; i < n; i++) cin>>k[i];
    for(int i = 0; i < n; i++){
        long long Mayor = Consulta(0, 100002, 0, 0, r[i]);
        //cerr<<Mayor<<"\n";
        if(Mayor >= t and Mayor > 0LL){
            t = Mayor;
            Actualizar(0, 100002, 0, r[i], r[i], t + r[i] + k[i]);
        } else {
            Actualizar(0, 100002, 0, r[i], r[i], t + r[i] + k[i]);
        }
        t++;
    }
    cout<<Consulta(0, 100002, 0, 0, 100002)<<"\n";
    return 0;
}