#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r = 0;
    cin>>n>>m;
    vector< vector<int> > Grafo(n);
    vector<int> Grados(n, 0);
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grados[a]++;
        Grados[b]++;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(Grados[i] >= 4){
            cerr<<i<<"\n";
            r++;
            continue;
        }
        if(Grados[i] <= 1) continue;
        vector< pair<int, int> > Posibles;
        for(auto E: Grafo[i]) Posibles.push_back(make_pair(Grados[E], E));
        sort(Posibles.rbegin(), Posibles.rend());
        if(Posibles[1].first >= 4){
            cerr<<i<<"\n";
            r++;
            continue;
        }
        set<int> Malos;
        for(auto E: Grafo[Posibles[0].second]) Malos.insert(E);
        bool Bien = 0;
        for(int j = 1; j < int(Posibles.size()); j++){
            if(Grados[Posibles[j].second] <= 2) break;
            if(Grados[Posibles[j].second] >= 3 and Malos.find(Posibles[j].second) == Malos.end()){
                Bien = 1;
                break;
            }
            if(Grados[Posibles[j].second] >= 4){
                Bien = 1;
                break;
            }
        }
        if(Bien){
            cerr<<i<<"\n";
            r++;
            continue;
        }
        if(Grados[i] == 2) continue;
        Malos.clear();
        Malos.insert(i);
        for(auto E: Grafo[i]) Malos.insert(E);
        int Buenos = 0;
        for(auto E: Grafo[i]){
            for(auto e: Grafo[E]){
                if(Malos.find(e) == Malos.end()) Buenos++;
            }
        }
        if(Buenos >= 2){
            cerr<<i<<"\n";
            r++;
        }
    }
    cout<<r<<"\n";
    return 0;
}