#include "game.h"
#include "bits/stdc++.h"
using namespace std;
vector<int> Aristas;
vector<int> r;
vector< vector<int> > Matriz;
int n;
int Buscar(int a){
    if(r[a] == a) return a;
    return r[a] = Buscar(r[a]);
}
void Unir(int a, int b){
    if(a > b) swap(a, b);
    a = Buscar(a);
    b = Buscar(b);
    for(int i = 0; i < n; i++){
        if(i != a and i != b){
            Matriz[a][i] += Matriz[b][i];
            Matriz[i][a] += Matriz[i][b];
        }
    }
    r[b] = a;
}
void initialize(int N){
    n = N;
    Matriz.assign(n, vector<int>(n, 1));
    for(int i = 0; i < n; i++){
        r.push_back(i);
        Matriz[i][i] = -0;
    }
}
int hasEdge(int u, int v){
    u = Buscar(u);
    v = Buscar(v);
    if(Matriz[u][v] == 1){
        Unir(u, v);
        return 1;
    } else {
        Matriz[u][v]--;
        Matriz[v][u]--;
        return 0;
    }
}