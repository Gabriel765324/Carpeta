#include "bits/stdc++.h"
using namespace std;
struct Nodo{
    int d, x, y;
    Nodo(int D, int X, int Y){
        d = D;
        x = X;
        y = Y;
    }
    
};
bool operator<(const Nodo& a, const Nodo& b){
    if(a.d < b.d) return 1;
    if(a.d > b.d) return 0;
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin>>s[i];
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'E') s[i][j] = '0';
            if(s[i][j] == 'S') s[i][j] = '1';
            if(s[i][j] == 'W') s[i][j] = '2';
            if(s[i][j] == 'N') s[i][j] = '3';
        }
    }
    vector< vector<int> > Distancia(n, vector<int>(m, 2222222));
    Distancia[0][0] = 0;
    set<Nodo> Cola;
    Cola.insert(Nodo(0, 0, 0));
    vector<int> cx = {0, 1, 0, -1}, cy = {1, 0, -1, 0};
    while(!Cola.empty()){
        int d = Cola.begin()->d, x = Cola.begin()->x, y = Cola.begin()->y;
        Cola.erase(Cola.begin());
        if(s[x][y] == 'X') continue;
        for(int i = 0; i < 4; i++){
            int nx = x + cx[i], ny = y + cy[i];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            int Extra = (i - (s[x][y] - '0') + 1048576) % 4;
            if(Distancia[nx][ny] > Distancia[x][y] + Extra){
                Distancia[nx][ny] = Distancia[x][y] + Extra;
                Cola.insert(Nodo(Distancia[nx][ny], nx, ny));
            }
        }
    }
    cout<<(Distancia.back().back() == 2222222 ? -1 : Distancia.back().back());
    return 0;
}