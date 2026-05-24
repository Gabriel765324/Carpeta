#include "bits/stdc++.h"
using namespace std;
vector< pair<int, int> > Orden;
vector< vector<int> > Grafo;
vector<int> Visitados;
int t = 0;
bool Mal = 0;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(Visitados[E] == 0) DFS(E);
        else if(Visitados[E] == 1) Mal = 1;
    }
    Orden[Nodo].first = t;
    Orden[Nodo].second = Nodo;
    Visitados[Nodo] = 2;
    t++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c = 0;
    cin>>n>>m;
    vector<string> a(n);
    vector< vector<int> > ID(n, vector<int>(m, -2));
    vector< pair<int, int> > Inversos;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] != '.'){
                ID[i][j] = c;
                Inversos.push_back({i + 1, j + 1});
                c++;
            }
        }
    }
    if(c == 0) return 0;
    Grafo.assign(c, {});
    Orden.assign(c, {-2, -2});
    Visitados.assign(c, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != '.'){
                int di = 0, dj = 0, ii = i, jj = j;
                if(a[i][j] == 'U') di = -1;
                if(a[i][j] == 'D') di = 1;
                if(a[i][j] == 'L') dj = -1;
                if(a[i][j] == 'R') dj = 1;
                for(ii += di, jj += dj; ii >= 0 and ii < n and jj >= 0 and jj < m; ii += di, jj += dj){
                    if(a[ii][jj] != '.') break;
                }
                //cerr<<"d "<<di<<" "<<dj<<"\n";
                if(!(ii < 0 or ii >= n or jj < 0 or jj >= m)){
                    //cerr<<"Borde -> "<<i<<" "<<j<<"\n";
                    //Grafo.back().push_back(ID[i][j]);
                //} else {
                    //cerr<<ii<<" "<<jj<<" -> "<<i<<" "<<j<<"\n";
                    Grafo[ID[ii][jj]].push_back(ID[i][j]);
                }
            }
        }
    }
    for(int i = 0; i < c; i++){
        if(Visitados[i] == 0){
            DFS(i);
        }
    }
    if(Mal){
        cout<<"-1\n";
        return 0;
    }
    sort(Orden.rbegin(), Orden.rend());
    for(auto E: Orden){
        cout<<Inversos[E.second].first<<" "<<Inversos[E.second].second<<"\n";
    }
    return 0;
}