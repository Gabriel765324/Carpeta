#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin>>n>>s;
    vector<string> Bosque(n);
    pair<int, int> Inicio, Casa;
    deque< pair< pair<int, int>, int> > Cola;
    for(int i = 0; i < n; i++){
        cin>>Bosque[i];
        for(int j = 0; j < n; j++){
            if(Bosque[i][j] == 'D') Casa = {i, j};
            if(Bosque[i][j] == 'M') Inicio = {i, j};
            if(Bosque[i][j] == 'H') Cola.push_back({{i, j}, 0});
        }
    }
    vector< vector<int> > Distancia(n, vector<int>(n, INT_MAX));
    for(auto E: Cola) Distancia[E.first.first][E.first.second] = -0;
    vector<int> ci = {0, 1, 0, -1}, cj = {1, 0, -1, 0};
    while(!Cola.empty()){
        pair< pair<int, int>, int> Actual = Cola[0];
        Cola.pop_front();
        if(Distancia[Actual.first.first][Actual.first.second] < Actual.second) continue;
        pair<int, int> Nodo = Actual.first;
        for(int i = 0; i < 4; i++){
            int ni = Nodo.first + ci[i], nj = Nodo.second + cj[i];
            if(ni > -1 and ni < n and nj > -1 and nj < n and Distancia[ni][nj] > Distancia[Nodo.first][Nodo.second] + 1 and Bosque[ni][nj] != 'T' and Bosque[ni][nj] != 'D' and Bosque[ni][nj] != 'H'){
                Distancia[ni][nj] = Distancia[Nodo.first][Nodo.second] + 1;
                Cola.push_back({{ni, nj}, Distancia[ni][nj]});
            }
        }
    }
    /*for(auto E: Distancia){
        for(auto e: E) cerr<<e<<" ";
        cerr<<"\n";
    }*/
    int i = 0, d = n * n + 1, m = 0;
    while(1){
        int p = (i + d) / 2;
        vector< vector<bool> > Visitados(n, vector<bool>(n, 0));
        Cola = {{Inicio, p * s}};
        bool Bien = 0;
        while(!Cola.empty()){
            pair< pair<int, int>, int> Actual = Cola[0];
            pair<int, int> Nodo = Actual.first;
            Cola.pop_front();
            if(Nodo == Casa){
                Bien = 1;
                break;
            }
            /*for(auto E: Visitados){
                for(auto e: E) cerr<<e<<" ";
                cerr<<"\n";
            }
            cerr<<"----\n";*/
            //cerr<<Nodo.first<<" "<<Nodo.second<<" "<<Actual.second / s<<" "<<p<<" "<<Distancia[Nodo.first][Nodo.second]<<"\n";
            if(Actual.second / s >= Distancia[Nodo.first][Nodo.second] or Visitados[Nodo.first][Nodo.second]) continue;
            /*for(auto E: Visitados){
                for(auto e: E) cerr<<e<<" ";
                cerr<<"\n";
            }
            cerr<<"----\n";*/
            for(int i = 0; i < 4; i++){
                int ni = Nodo.first + ci[i], nj = Nodo.second + cj[i];
                if(ni > -1 and ni < n and nj > -1 and nj < n and !Visitados[ni][nj] and Bosque[ni][nj] != 'T' and Bosque[ni][nj] != 'H'){
                    Cola.push_back({{ni, nj}, Actual.second + 1});
                }
            }
            Visitados[Nodo.first][Nodo.second] = 1;
        }
        //cerr<<"Fin.\n----\n";
        if(Bien){
            m = p;
            i = p + 1;
        } else {
            if(p == 0) m = -1;
            d = p - 1;
        }
        if(i >= d + 1) break;
    }
    cout<<m;
    return 0;
}