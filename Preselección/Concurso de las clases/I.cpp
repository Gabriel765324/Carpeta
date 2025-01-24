#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n>>m;
    vector<string> Matriz(n);
    for(long long i = 0; i < n; i++){
        cin>>Matriz[i];
    }
    vector< vector<bool> > Visitados(n, vector<bool>(m, 0));
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            Visitados[i][j] = Matriz[i][j] == '#';
        }
    }
    long long c = 0;
    vector<long long> x = {0, 1, 0, -1}, y = {1, 0, -1, 0};
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            if(!Visitados[i][j]){
                c++;
                deque< pair<long long, long long> > Cola = {{i, j}};
                while(!Cola.empty()){
                    pair<long long, long long> Nodo = Cola[0];
                    Cola.pop_front();
                    if(Visitados[Nodo.first][Nodo.second]) continue;
                    Visitados[Nodo.first][Nodo.second] = 1;
                    for(long long k = 0; k < 4; k++){
                        long long ni = Nodo.first + y[k], nj = Nodo.second + x[k];
                        if(ni >= 0 and ni < n and nj >= 0 and nj < m and !Visitados[ni][nj]) Cola.push_back({ni, nj});
                    }
                }
            }
        }
    }
    cout<<c;
    return 0;
}