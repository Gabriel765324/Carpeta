#include "soccer.h"
#include "bits/stdc++.h"
using namespace std;
int biggest_stadium(int n, vector< vector<int> > FULBO){
    int m = n;
    int r = 0;
    deque< deque<bool> > fulbo;
    for(int i = 0; i < n; i++){
        fulbo.push_back({});
        for(int j = 0; j < n; j++){
            if(FULBO[i][j] == 0) r++;
            fulbo.back().push_back(FULBO[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        int Componentes = 0;
        for(int j = 0; j < n; j++){
            if((j == 0 and fulbo[i][j] == 0) or (j > 0 and fulbo[i][j - 1] == 1 and fulbo[i][j] == 0)) Componentes++;
        }
        if(Componentes > 1) return 0;
    }
    for(int i = 0; i < n; i++){
        int Componentes = 0;
        for(int j = 0; j < n; j++){
            if((j == 0 and fulbo[j][i] == 0) or (j > 0 and fulbo[j - 1][i] == 1 and fulbo[j][i] == 0)) Componentes++;
        }
        if(Componentes > 1) return 0;
    }
    vector< pair<int, int> > Claves;
    for(; n > 0; ){
        bool Borrar = 1;
        for(int i = 0; i < m; i++) if(fulbo[0][i] == 0) Borrar = 0;
        if(Borrar){
            n--;
            fulbo.pop_front();
        } else break;
    }
    for(; n > 0; ){
        bool Borrar = 1;
        for(int i = 0; i < m; i++) if(fulbo[n - 1][i] == 0) Borrar = 0;
        if(Borrar){
            n--;
            fulbo.pop_back();
        } else break;
    }
    for(; m > 0; ){
        bool Borrar = 1;
        for(int i = 0; i < n; i++) if(fulbo[i][0] == 0) Borrar = 0;
        if(Borrar){
            m--;
            for(int i = 0; i < n; i++) fulbo[i].pop_front();
        } else break;
    }
    for(; m > 0; ){
        bool Borrar = 1;
        for(int i = 0; i < n; i++) if(fulbo[i][m - 1] == 0) Borrar = 0;
        if(Borrar){
            m--;
            for(int i = 0; i < n; i++) fulbo[i].pop_back();
        } else break;
    }
    int i;
    for(i = 0; i < m; i++) if(fulbo[0][i] == 0) break;
    Claves.push_back({0, i});
    for(i = 0; i < n; i++) if(fulbo[i][0] == 0) break;
    Claves.push_back({i, 0});
    for(i = n - 1; i > -1; i--) if(fulbo[i][0] == 0) break;
    Claves.push_back({i, 0});
    for(i = 0; i < m; i++) if(fulbo[n - 1][i] == 0) break;
    Claves.push_back({n - 1, i});
    for(i = m - 1; i > -1; i--) if(fulbo[n - 1][i] == 0) break;
    Claves.push_back({n - 1, i});
    for(i = n - 1; i > -1; i--) if(fulbo[i][m - 1] == 0) break;
    Claves.push_back({i, m - 1});
    for(i = 0; i < n; i++) if(fulbo[i][m - 1] == 0) break;
    Claves.push_back({i, m - 1});
    for(i = m - 1; i > -1; i--) if(fulbo[0][i] == 0) break;
    Claves.push_back({0, i});
    /*cerr<<n<<" "<<m<<" n y m.\n";
    for(i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cerr<<fulbo[i][j]<<" ";
        }
        cerr<<"\n";
    }*/
    for(i = 0; i < 7; i++){
        //cerr<<i<<"  ";
        if(Claves[i].first <= -1 or Claves[i].first >= n or Claves[i].second <= -1 or Claves[i].second >= m) continue;
        for(int j = i + 1; j < 8; j++){
            //cerr<<j<<" ";
            /*cerr<<i<<" "<<j<<" índices.\n";
            cerr<<Claves[i].first<<" "<<Claves[i].second<<"\n";
            cerr<<Claves[j].first<<" "<<Claves[j].second<<"\n";*/
            if(Claves[i].first == Claves[j].first or Claves[i].second == Claves[j].second) continue;
            //cerr<<"No son diferentes.\n";
            if(Claves[j].first <= -1 or Claves[j].first >= n or Claves[j].second <= -1 or Claves[j].second >= m) continue;
            bool No_se_puede = 1;
            for(int k = Claves[i].first; k < n and k > -1; k += (Claves[j].first - Claves[i].first) / abs(Claves[j].first - Claves[i].first)){
                if(fulbo[k][Claves[i].second] == 1) break;
                if(k == Claves[j].first){
                    No_se_puede = 0;
                    break;
                }
            }
            for(int k = Claves[i].second; k < m and k > -1; k += (Claves[j].second - Claves[i].second) / abs(Claves[j].second - Claves[i].second)){
                if(fulbo[Claves[i].first][k] == 1) break;
                if(k == Claves[j].second){
                    No_se_puede = 0;
                    break;
                }
            }
            if(No_se_puede) return -0;
        }
        //cerr<<"\n";
    }
    return r;
}