#include "bits/stdc++.h"
using namespace std;
vector<int> Combo;
vector< vector<int> > Cambio, Costos;
vector< vector<long long> > PD;
int n, m, k;
string s;
long long Resolver(int i, int c){
    if(i == n) return 0;
    if(i > n) return 2222222222222222;
    if(PD[i][c] != -2) return PD[i][c];
    long long r = Resolver(i + 1, c) + Cambio[Combo[i]][c];
    for(int j = 0; j < m and i < Costos.size(); j++){
        r = min(r, Resolver(i + k, j) + Costos[i][j]);
    }
    return PD[i][c] = r;
}
int main(){
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    cin>>n>>m>>k>>s;
    Cambio.assign(m, vector<int>(m));
    PD.assign(n, vector<long long>(m, -2));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin>>Cambio[i][j];
        }
    }
    for(int Intermedio = 0; Intermedio < m; Intermedio++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                Cambio[i][j] = min(Cambio[i][Intermedio] + Cambio[Intermedio][j], Cambio[i][j]);
            }
        }
    }
    unordered_map<char, int> Mapa;
    for(int i = 0; i < m; i++) Mapa[i + 'a'] = i;
    for(int i = 0; i < n; i++) Combo.push_back(Mapa[s[i]]);
    vector<int> Costo_actual(m, 0);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++){
            Costo_actual[j] += Cambio[Combo[i]][j];
        }
    }
    Costos.push_back(Costo_actual);
    for(int i = k; i < n; i++){
        for(int j = 0; j < m; j++){
            Costo_actual[j] += Cambio[Combo[i]][j];
            Costo_actual[j] -= Cambio[Combo[i - k]][j];
        }
        Costos.push_back(Costo_actual);
    }
    long long r = 2222222222222222;
    for(int i = 0; i < m; i++){
        r = min(r, Resolver(k, i) + Costos[0][i]);
    }
    cout<<r;
    return 0;
}