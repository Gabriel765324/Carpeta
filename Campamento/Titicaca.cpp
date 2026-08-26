#include "bits/stdc++.h"
using namespace std;
vector<long long> ci = {-1, 0, 1, 0}, cj = {0, 1, 0, -1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n>>m;
    vector< vector<long long> > Mapa(n, vector<long long>(m));
    for(long long i = 0; i < n; i++) for(long long j = 0; j < m; j++) cin>>Mapa[i][j];
    long long r = -0;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            if(Mapa[i][j] == 1){
                r++;
                bool Bajar = 0;
                deque< pair<long long, long long> > Cola = {{i, j}};
                while(!Cola.empty()){
                    long long x = Cola[0].first, y = Cola[0].second;
                    if(x == 0 or x == n - 1 or y == 0 or y == m - 1) Bajar = 1;
                    Cola.pop_front();
                    Mapa[x][y] = 0;
                    for(long long k = 0; k < 4; k++){
                        long long ni = x + ci[k], nj = y + cj[k];
                        if(ni > -1 and ni < n and nj > -1 and nj < m and Mapa[ni][nj] == 1){
                            Mapa[ni][nj] = 0;
                            Cola.push_back({ni, nj});
                        }
                    }
                }
                if(Bajar) r--;
            }
        }
    }
    cout<<r;
    return 0;
}