#include "bits/stdc++.h"
using namespace std;
int main(){
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    long long n, w;
    cin>>n>>w;
    vector< vector< pair<long long, long long> > > Memoria(3000 * n + 1, vector< pair<long long, long long> >(n + 1, {2222222222222222, 2222222222222222}));
    vector< pair<long long, long long> > Vacas(n);
    for(long long i = 0; i < n; i++) cin>>Vacas[i].first>>Vacas[i].second;
    for(long long i = 0; i < n + 1; i++){
        Memoria[0][i] = {0, 0};
    }
    long long m = 0;
    for(long long i = 0; i < Memoria.size(); i++){
        for(long long j = 0; j < n + 1; j++){
            if(Memoria[i][j].first == 2222222222222222 and Memoria[i][j].second == 2222222222222222) continue;
            if(Memoria[i][j].first >= w and Memoria[i][j].first != 2222222222222222) m = max(m, i * 1000 / Memoria[i][j].first);
            if(j == n) continue;
            long long Costo_1 = Vacas[j].first + Memoria[i][j].first, Costo_2 = Vacas[j].first + Memoria[i][j].second;
            if(Costo_1 >= w and i + Vacas[j].second < Memoria.size()) Memoria[i + Vacas[j].second][j + 1].first = min(Memoria[i + Vacas[j].second][j + 1].first, Costo_1);
            if(i + Vacas[j].second < Memoria.size()){
                Memoria[i + Vacas[j].second][j + 1].second = min(Memoria[i + Vacas[j].second][j + 1].second, Costo_2);
                if(Costo_2 >= w) Memoria[i + Vacas[j].second][j + 1].first = min(Memoria[i + Vacas[j].second][j + 1].first, Costo_2);
            }
        }
    }
    /*long long i = 0;
    for(auto E: Memoria){
        cout<<i<<"  ";
        for(auto e: E){
            cout<<e.first<<" ";
        }
        i++;
        cout<<"\n";
    }
    i = 0;
    for(auto E: Memoria){
        cout<<i<<"  ";
        for(auto e: E){
            cout<<e.second<<" ";
        }
        i++;
        cout<<"\n";
    }*/
    cout<<m;
    return 0;
}//Está mal. :(