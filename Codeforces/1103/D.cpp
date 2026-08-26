#include "bits/stdc++.h"
using namespace std;
vector< bitset<2> > _rbol;
bitset<2> Todo, Nada;
int Tama_o(int i, int d){
    return 2 * (d - i + 1);
}
bitset<2> operator+(const bitset<2>& a, const bitset<2>& b){
    bitset<2> r;
    r = a & b;
    return r;
}
bitset<2> Consulta(int i, int d, int p, int I, int D){
    if(I > D) return Todo;
    if(I <= i and d <= D) return _rbol[p];
    if(D < i or d < I) return Todo;
    int P = (i + d) / 2;
    return Consulta(i, P, p + 1, I, D) + Consulta(P + 1, d, p + Tama_o(i, P), I, D);
}
void Actualizar(int i, int d, int p, int a, bitset<2> v){
    if(i == d){
        _rbol[p] = v;
        return;
    }
    int P = (i + d) / 2;
    if(a <= P) Actualizar(i, P, p + 1, a, v);
    else Actualizar(P + 1, d, p + Tama_o(i, P), a, v);
    _rbol[p] = _rbol[p] + _rbol[p + Tama_o(i, P)];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    Todo[0] = 1;
    Todo[1] = 1;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector< vector< bitset<2> > > PD(n + 1);
        for(int i = 0; i < n; i++){
            int a;
            cin>>a;
            PD[a].push_back(Nada);
            if(int(PD[a].size()) == 1) PD[a].push_back(Nada);
        }
        _rbol.assign(n * 2 + 2222, Todo);
        for(int i = n; i > -1; i--){
            //cerr<<i<<" ";
            int m = int(PD[i].size());
            /*for(int j = 0; j <= n; j++) cerr<<Consulta(0, n, 0, j, j)<<" ";
            cerr<<"\n";*/
            if(m <= 0) continue;
            bitset<2> Rango = Consulta(0, n, 0, i + 1, min(i + k, n));
            for(int j = 0; j < m; j++){
                if(j == 0){
                    PD[i][j][0] = Rango[1];
                    PD[i][j][1] = Rango[0];
                } else {
                    PD[i][j][0] = PD[i][j - 1][0] == 0 or PD[i][j - 1][1] == 0;
                    PD[i][j][1] = PD[i][j - 1][0] == 0 or PD[i][j - 1][1] == 0 or Rango[0] == 0;
                }
            }
            Rango[0] = PD[i].back()[0] == 0;
            Rango[1] = PD[i].back()[1] == 0;
            Actualizar(0, n, 0, i, Rango);
        }
        bool Mal = 1;
        for(auto E: PD){
            if(int(E.size()) <= 1) continue;
            if(E[int(E.size()) - 2][0] == 1 or E[int(E.size()) - 2][1] == 1){
                Mal = 0;
                cout<<"YES\n";
            }
        }
        /*for(auto E: PD){
            for(auto e: E) cerr<<e<<" ";
            cerr<<"\n";
        }*/
        if(Mal) cout<<"NO\n";
    }
    return 0;
}