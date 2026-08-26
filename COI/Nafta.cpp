#include "bits/stdc++.h"
using namespace std;
struct Nodo{
    pair<int, int> r;
    int i, d, v;
    Nodo(){}
    bool operator<(const Nodo& a){
        if(i < a.i) return 1;
        if(i > a.i) return 0;
        return d < a.d;
    }
    bool Contiene(const int& a){
        return i <= a and a <= d;
    }
};
vector< vector<Nodo> > Representantes;
pair<int, int> Buscar(pair<int, int> p){
    if(Representantes[p.first][p.second].r == p) return p;
    return Representantes[p.first][p.second].r = Buscar(Representantes[p.first][p.second].r);
}
void Unir(pair<int, int> a, pair<int, int> b){
    a = Buscar(a);
    b = Buscar(b);
    Representantes[a.first][a.second].i = min(Representantes[a.first][a.second].i, Representantes[b.first][b.second].i);
    Representantes[a.first][a.second].d = max(Representantes[a.first][a.second].d, Representantes[b.first][b.second].d);
    if(a != b){
        Representantes[a.first][a.second].v += Representantes[b.first][b.second].v;
        Representantes[b.first][b.second].r = a;
    }
}
vector< vector<int> > PD;
vector<Nodo> Problema;
vector<int> Gano/*, Pierdo*/;
int Rangos_disponibles, Posiciones_tomables;
int Resolver(int Tomado, int Queda){
    if(Tomado >= Posiciones_tomables) return 0;
    if(Queda == 0) return 0;
    if(PD[Tomado][Queda] != -2) return PD[Tomado][Queda];
    int Mayor = 0, Pierdo = 0, p = 0;
    set< pair<int, pair<int, bool> > > Ayuda;
    for(int i = 0; i < Tomado; i++){
        for(; p < Rangos_disponibles; p++){
            //cerr<<Tomado - 1<<" "<<Problema[p].i<<" "<<Problema[p].d<<"\n";
            if(Problema[p].i <= i){
                if(Problema[p].Contiene(Tomado - 1)){
                    Pierdo += Problema[p].v;
                    Ayuda.insert({Problema[p].d, {Problema[p].v, 1}});
                } else {
                    Ayuda.insert({Problema[p].d, {Problema[p].v, 0}});
                }
            } else break;
        }
        while(!Ayuda.empty() and Ayuda.begin()->first <= i){
            if(Ayuda.begin()->second.second) Pierdo -= Ayuda.begin()->second.first;
            Ayuda.erase(Ayuda.begin());
        }
    }
    for(int i = Tomado; i < Posiciones_tomables; i++){
        for(; p < Rangos_disponibles; p++){
            //cerr<<Tomado - 1<<" "<<Problema[p].i<<" "<<Problema[p].d<<"\n";
            if(Problema[p].i <= i){
                if(Problema[p].Contiene(Tomado - 1)){
                    Pierdo += Problema[p].v;
                    Ayuda.insert({Problema[p].d, {Problema[p].v, 1}});
                } else {
                    Ayuda.insert({Problema[p].d, {Problema[p].v, 0}});
                }
            } else break;
        }
        //cerr<<Tomado<<" "<<i<<" "<<Gano[i]<<" "<<Pierdo<<" "<<Queda<<"\n";
        Mayor = max(Mayor, Resolver(i + 1, Queda - 1) + Gano[i] - Pierdo);
        while(!Ayuda.empty() and Ayuda.begin()->first <= i){
            if(Ayuda.begin()->second.second) Pierdo -= Ayuda.begin()->second.first;
            Ayuda.erase(Ayuda.begin());
        }
    }
    return PD[Tomado][Queda] = Mayor;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    Representantes.assign(n, vector<Nodo>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            Representantes[i][j].r = {i, j};
            Representantes[i][j].i = j;
            Representantes[i][j].d = j;
            if(a[i][j] == '.') Representantes[i][j].v = -2;
            else Representantes[i][j].v = a[i][j] - '0';
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '.') continue;
            if(i < n - 1 and a[i + 1][j] != '.') Unir({i, j}, {i + 1, j});
            if(j < m - 1 and a[i][j + 1] != '.') Unir({i, j}, {i, j + 1});
        }
    }
    vector< bitset<2222> > Visitados(n);
    vector<Nodo> Ranguitos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '.') continue;
            pair<int, int> r = Buscar(Representantes[i][j].r);
            if(!Visitados[r.first][r.second]){
                Ranguitos.push_back(Representantes[r.first][r.second]);
                Visitados[r.first][r.second] = 1;
            }
        }
    }
    sort(Ranguitos.begin(), Ranguitos.end());
    n = int(Ranguitos.size());
    for(int i = 0; i < n; i++){
        if(i == n - 1) Problema.push_back(Ranguitos[i]);
        else {
            if(Ranguitos[i].i == Ranguitos[i + 1].i and Ranguitos[i].d == Ranguitos[i + 1].d) Ranguitos[i + 1].v += Ranguitos[i].v;
            else Problema.push_back(Ranguitos[i]);
        }
    }
    n = int(Problema.size());
    /*for(auto E: Problema){
        cerr<<E.i<<" "<<E.d<<" "<<E.v<<"\n";
    }*/
    PD.assign(m + 2, vector<int>(m + 2, -2));
    Rangos_disponibles = n;
    Posiciones_tomables = m;
    set< pair<int, int> > Ayuda;
    int p = 0, Tengo = 0;
    for(int i = 0; i < m; i++){
        for(; p < n; p++){
            if(Problema[p].i <= i){
                Tengo += Problema[p].v;
                Ayuda.insert({Problema[p].d, Problema[p].v});
            } else break;
        }
        Gano.push_back(Tengo);
        //cerr<<Tengo<<" ";
        while(!Ayuda.empty() and Ayuda.begin()->first <= i){
            Tengo -= Ayuda.begin()->second;
            Ayuda.erase(Ayuda.begin());
        }
    }
    //cerr<<"\n";
    for(int i = 1; i <= m; i++) cout<<Resolver(0, i)<<"\n";
    return 0;
}
/*
5 5
1..9.
11.9.
1.1.9
111..
1...8

5 3
111
...
1..
...
..1

5 3
111
...
1..
.1.
..1

5 3
111
...
1..
.2.
..1

1 1
.

3 2
..
..
..

3 8
22.....9
..22.22.
.11.22..

3 8
22.....9
..22.22.
.1..22..

5 41
22222.22222.2222..2222....2...22222.2....
2.....2...2.2...2.2...2...2...2.....2....
2.222.22222.2222..2222....2...22222.2....
2...2.2...2.2...2.2..2....2...2.....2....
22222.2...2.2222..2...2...2...22222.22222

5 41
22222.22222.2222..222200002...22222.2....
2.....2...202...202...2...2...2...002....
2.222022222.22220.2222....2...22222.2....
2...2.2...2.2...2.2..2....2...2.....2....
22222.2...2.2222..2...2...200022222.22222
*/