#include <bits/stdc++.h>
using namespace std;
vector<int> count(int n, vector<int> s, vector<int> p){
    vector< pair< pair<int, int>, int> > Tubos(n);
    for(int i = 0; i < n; i++) Tubos[i] = {{s[i], -p[i]}, i};
    sort(Tubos.rbegin(), Tubos.rend());
    vector< vector<int> > Le_gana(n);
    set< pair<int, int> > Para_contar;
    for(int i = 0; i < n; i++){
        int j;
        vector< pair< pair<int, int>, int> > Grupo = {Tubos[i]};
        for(j = i + 1; Tubos[j].first.first == Tubos[i].first.first and j < n; j++) Grupo.push_back(Tubos[j]);
        j--;
        for(int k = i; k <= j; k++){
            for(auto E = Para_contar.upper_bound({Grupo[k - i].first.second, -2}); E != Para_contar.end(); E++){
                if(Le_gana[Grupo[k - i].second].size() >= 2) break;
                Le_gana[Grupo[k - i].second].push_back((*E).second);
            }
        }
        for(int k = i; k <= j; k++) Para_contar.insert({Grupo[k - i].first.second, Grupo[k - i].second});
        i = j;
    }
    vector<int> r(n, 0);
    set<int> Cero;
    int Siempre = 0;
    vector<int> __le_gana_a_(n, 0);
    for(int i = 0; i < n; i++){
        switch(Le_gana[i].size()){
            case 0:
            Cero.insert(i);
            Siempre++;
            break;
            case 1:
            __le_gana_a_[Le_gana[i][0]]++;
            break;
        }
    }
    /*for(int i = 0; i < n; i++) cerr<<__le_gana_a_[i]<<" ";
    cerr<<"\n";*/
    for(int i = 0; i < n; i++){
        int Devolver = 0;
        if(Cero.count(i) >= 1){
            Devolver++;
            Siempre--;
        }
        Siempre += __le_gana_a_[i];
        r[i] = Siempre;
        Siempre -= __le_gana_a_[i];
        Siempre += Devolver;
    }
    return r;
}