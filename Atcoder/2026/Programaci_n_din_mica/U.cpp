#include "bits/stdc++.h"
using namespace std;
int n;
vector< vector<long long> > PD;
vector<long long> Precalcular;
vector<int> Potencias = {1};
long long Resolver(int i, int M_scara){
    if(M_scara == Potencias[n] - 1) return 0;
    if(i == n){
        int Tomados = 0, M_scara_para_capa_nueva = M_scara, Posici_n = 0;
        while(M_scara > 0){
            int Actual = M_scara % 3;
            M_scara /= 3;
            if(Actual == 1){
                Tomados += (1<<Posici_n);
                M_scara_para_capa_nueva += Potencias[Posici_n];
            }
            Posici_n++;
        }
        if(Tomados == 0) return -2222222222222222;
        return Resolver(0, M_scara_para_capa_nueva) + Precalcular[Tomados];
    }
    if(PD[i][M_scara] != -2LL) return PD[i][M_scara];
    int Tomados = (1<<i), Copia = M_scara, M_scara_para_capa_nueva = M_scara, Posici_n = 0;
    while(Copia > 0){
        int Actual = Copia % 3;
        Copia /= 3;
        if(Posici_n == i and Actual == 2){
            return PD[i][M_scara] = Resolver(i + 1, M_scara);
        }
        if(Posici_n == i){
            break;
        }
        if(Actual == 1){
            Tomados += (1<<Posici_n);
            M_scara_para_capa_nueva += Potencias[Posici_n];
        }
        Posici_n++;
    }
    long long _0 = Resolver(i + 1, M_scara);
    long long _1 = Resolver(i + 1, M_scara + Potencias[i]);
    long long _2 = Resolver(0, M_scara_para_capa_nueva + 2 * Potencias[i]) + Precalcular[Tomados];
    return PD[i][M_scara] = max(max(_0, _1), _2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(Potencias.size() < 17) Potencias.push_back(Potencias.back() * 3);
    cin>>n;
    vector< vector<long long> > Costos(n, vector<long long>(n, 0));
    PD.assign(n, vector<long long>(Potencias[n], -2));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>Costos[i][j];
        }
    }
    Precalcular.assign((1<<n), 0);
    for(int i = 0; i < (1<<n); i++){
        vector<int> _ndices;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                _ndices.push_back(j);
            }
        }
        for(int j = 0; j < (int)_ndices.size() - 1; j++){
            for(int k = j + 1; k < (int)_ndices.size(); k++){
                Precalcular[i] += Costos[_ndices[j]][_ndices[k]];
            }
        }
    }
    cout<<Resolver(0, 0);
    cerr<<"\n"<<clock() / CLOCKS_PER_SEC;
    return 0;
}