#include "soccer.h"
#include "bits/stdc++.h"
using namespace std;
int biggest_stadium(int n, vector< vector<int> > fulbo){
    int r = 0;
    vector< pair<int, int> > Pares;
    for(int i = 0; i < n; i++){
        int Componentes = 0;
        int m = -2, M = -2;
        for(int j = 0; j < n; j++){
            r += 1 - fulbo[i][j];
            if(fulbo[i][j] == 0 and (j == 0 or fulbo[i][j - 1] == 1)) m = j;
            if(fulbo[i][j] == 0 and (j == n - 1 or fulbo[i][j + 1] == 1)) M = j;
            if((j == 0 and fulbo[i][j] == 0) or (j > 0 and fulbo[i][j - 1] == 1 and fulbo[i][j] == 0)) Componentes++;
        }
        if(m != -2 and M != -2) Pares.push_back({m, M});
        if(Componentes > 1){
            //cerr<<"No conexo.\n";
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        int Componentes = 0;
        for(int j = 0; j < n; j++){
            if((j == 0 and fulbo[j][i] == 0) or (j > 0 and fulbo[j - 1][i] == 1 and fulbo[j][i] == 0)) Componentes++;
        }
        if(Componentes > 1){
            //cerr<<"No conexo.\n";
            return 0;
        }
    }
    for(int i = 0; i < Pares.size() - 1; i++){
        for(int j = i + 1; j < Pares.size(); j++){
            if(Pares[i].first < Pares[j].first and Pares[i].second < Pares[j].second) return 0;
            if(Pares[j].first < Pares[i].first and Pares[j].second < Pares[i].second) return 0;
        }
    }
    return r;
}