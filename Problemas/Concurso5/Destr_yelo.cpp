#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Cartas, PD;
int n;
long long Resolver(int i, int f){
    if(i == n) return 0;
    if(PD[i][f] != -2) return PD[i][f];
    long long r = Resolver(i + 1, f), a = max(Cartas[i][0], max(Cartas[i][1], max(Cartas[i][2], max(Cartas[i][3], max(Cartas[i][4], Cartas[i][5])))));
    if(f == 9) r = max(r, Resolver(i + 1, 0) + 2 * a);
    else r = max(r, Resolver(i + 1, f + 1) + a);
    if(f >= 8){
        a = -2222222222222222;
        for(int j = 1; j < 5; j++){
            for(int k = j + 1; k < 6; k++){
                if(j == 1 and k == 2) continue;
                a = max(a, Cartas[i][j] + Cartas[i][k] + max(Cartas[i][j], Cartas[i][k]));
            }
        }
        r = max(r, Resolver(i + 1, (f + 2) % 10) + a);
    } else {
        a = -2222222222222222;
        for(int j = 1; j < 5; j++){
            for(int k = j + 1; k < 6; k++){
                if(j == 1 and k == 2) continue;
                a = max(a, Cartas[i][j] + Cartas[i][k]);
            }
        }
        r = max(r, Resolver(i + 1, f + 2) + a);
    }
    if(f >= 7) r = max(r, Resolver(i + 1, (f + 3) % 10) + Cartas[i][3] + Cartas[i][4] + Cartas[i][5] + max(Cartas[i][3], max(Cartas[i][4], Cartas[i][5])));
    else r = max(r, Resolver(i + 1, f + 3) + Cartas[i][3] + Cartas[i][4] + Cartas[i][5]);
    return PD[i][f] = r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    Cartas.assign(n, vector<long long>(6, -2222222222222222));
    PD.assign(n, vector<long long>(10, -2));
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        vector< vector<int> > Ronda(3);
        for(int j = 0; j < k; j++){
            int Precio, Poder;
            cin>>Precio>>Poder;
            Ronda[Precio - 1].push_back(Poder);
        }
        for(int j = 0; j < 3; j++){
            sort(Ronda[j].rbegin(), Ronda[j].rend());
            if(j == 0){
                for(int l = 0; l < 3 and l < Ronda[j].size(); l++){
                    Cartas[i][l + 3] = Ronda[j][l];
                }
            } else if(j == 1){
                for(int l = 0; l < 2 and l < Ronda[j].size(); l++){
                    Cartas[i][l + 1] = Ronda[j][l];
                }
            } else {
                for(int l = 0; l < 1 and l < Ronda[j].size(); l++){
                    Cartas[i][l] = Ronda[j][l];
                }
            }
        }
    }
    cout<<Resolver(0, 0);
    return 0;
}