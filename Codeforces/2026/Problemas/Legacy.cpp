#include "bits/stdc++.h"
using namespace std;
struct Arista{
    int Nodo, Capa;
    long long Peso;
};
vector< vector< vector<Arista> > > Grafo;
int u, I, D, t;
const int MayorN = 1e5 + 2;
long long Peso;
//map< pair<int, int> , pair<int, int> > Mapeo;
int Originales[MayorN] = {};
void Crear(int i, int d, int p){
    Arista Nuevo;
    /*Mapeo[{0, p}] = {i, d};
    Mapeo[{1, p}] = {-i, -d};
    cerr<<"0 "<<p<<"  "<<i<<" "<<d<<"\n";
    cerr<<"1 "<<p<<"  "<<-i<<" "<<-d<<"\n";*/
    if(i == d){
        Originales[i] = p;
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    Nuevo.Nodo = p * 2;
    Nuevo.Capa = 0;
    Nuevo.Peso = 0;
    Grafo[0][p].push_back(Nuevo);
    Nuevo.Nodo++;
    Grafo[0][p].push_back(Nuevo);
    Nuevo.Capa = 1;
    Nuevo.Nodo = p;
    if(i == P){
        Grafo[0][p * 2].push_back(Nuevo);
    } else {
        Grafo[1][p * 2].push_back(Nuevo);
    }
    if(d == P + 1){
        Grafo[0][p * 2 + 1].push_back(Nuevo);
    } else {
        Grafo[1][p * 2 + 1].push_back(Nuevo);
    }
}
void A_adir(int i, int d, int p){
    if(i >= I and d <= D){
        Arista Nuevo;
        Nuevo.Capa = 0;
        Nuevo.Peso = Peso;
        Nuevo.Nodo = p;
        if(t == 0) Grafo[0][Originales[u]].push_back(Nuevo);
        else {
            Nuevo.Nodo = Originales[u];
            if(i != d) Grafo[1][p].push_back(Nuevo);
            else Grafo[0][p].push_back(Nuevo);
        }
        return;
    }
    if(i > D or d < I) return;
    int P = (i + d) / 2;
    A_adir(i, P, p * 2);
    A_adir(P + 1, d, p * 2 + 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, s;
    cin>>n>>q>>s;
    Grafo.push_back(vector< vector<Arista> >(4 * n + 22));
    Grafo.push_back(vector< vector<Arista> >(4 * n + 22));
    Crear(0, n - 1, 1);
    while(q--){
        cin>>t;
        if(t == 1){
            cin>>u>>I>>Peso;
            D = I;
        } else {
            cin>>u>>I>>D>>Peso;
            t--;
        }
        t--;
        u--;
        I--;
        D--;
        A_adir(0, n - 1, 1);
    }
    s--;
    vector< vector<long long> > Distancias(2, vector<long long>(n * 4 + 22, -1));
    Distancias[0][Originales[s]] = 0;
    set< pair<long long, pair<int, int> > > Cola;
    Cola.insert({0, {0, Originales[s]}});
    while(!Cola.empty()){
        auto Actual = *Cola.begin();
        //cerr<<Actual.first<<" "<<Mapeo[Actual.second].first<<" "<<Mapeo[Actual.second].second<<"\n";
        Cola.erase(Cola.begin());
        if(Actual.first > Distancias[Actual.second.first][Actual.second.second]) continue;
        for(auto E: Grafo[Actual.second.first][Actual.second.second]){
            if(Distancias[E.Capa][E.Nodo] == -1 or Distancias[E.Capa][E.Nodo] > Actual.first + E.Peso){
                Distancias[E.Capa][E.Nodo] = Actual.first + E.Peso;
                Cola.insert({Distancias[E.Capa][E.Nodo], {E.Capa, E.Nodo}});
            }
        }
    }
    for(int i = 0; i < n; i++) cout<<Distancias[0][Originales[i]]<<" ";
    return 0;
}