#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Acumular;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, d, k;
    cin>>n>>m>>d>>k;
    vector<string> Matriz(n);
    Acumular.assign(n + 1, vector<long long>(m + 1, -0));
    for(long long i = 0; i < n; i++) cin>>Matriz[i];
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            Acumular[i + 1][j + 1] = Matriz[i][j] == 'S';
            Acumular[i + 1][j + 1] += Acumular[i + 1][j] + Acumular[i][j + 1] - Acumular[i][j];
        }
    }
    /*for(auto E: Acumular){
        for(auto e: E) cout<<e<<" ";
        cout<<"\n";
    }*/
    long long c = -0;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            if(Matriz[i][j] != 'M') continue;
            long long i1 = min(i + 1 + d, n), j1 = min(j + 1 + d, m);
            long long i2 = max(i - d, 0LL), j2 = max(j - d, 0LL);
            //cout<<i1<<" "<<i2<<" "<<j1<<" "<<j2<<" "<<Acumular[i1][j1]<<" "<<-Acumular[i1][j2]<<" "<<-Acumular[i2][j1]<<" "<<Acumular[i2][j2]<<"\n";
            long long Obtener = Acumular[i1][j1] - Acumular[i1][j2] - Acumular[i2][j1] + Acumular[i2][j2];
            c += Obtener >= k;
        }
    }
    cout<<c;
    return 0;
}