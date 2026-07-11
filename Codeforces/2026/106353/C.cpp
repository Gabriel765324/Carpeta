#include "bits/stdc++.h"
using namespace std;
bitset<600022> Aristas_usadas;
vector<int> Camino;
map< pair<int, int>, long long> Costos;
struct Arista{
    int a, b, ID;
    long long c;
    bool Bien, Orientado, Orientaci_n;
    Arista(){}
    Arista(int A, int B, int i, long long C, bool Bueno){
        a = A;
        b = B;
        ID = i;
        c = C;
        Bien = Bueno;
        Orientaci_n = 0;
        Orientado = 0;
    }
    bool operator<(const Arista& o){
        return make_pair(-c, ID) < make_pair(-o.c, o.ID);
    }
};
vector<Arista> Lista;
vector< vector<Arista> > Grafo;
int Restantes, Inicio;
long long Costo_total = 0;
bool Seguir = 1;
bool DFS(int Nodo){
    //cerr<<Nodo + 1<<"\n";
    Camino.push_back(Nodo);
    if(Restantes == 0 and Nodo == Inicio){
        Seguir = 0;
        return 1;
    }
    bool Sirvi_ = 0;
    for(; !Grafo[Nodo].empty() and Seguir; ){
        Arista Considerar = Grafo[Nodo].back();
        if(Aristas_usadas[Considerar.ID]) continue;
        Aristas_usadas[Considerar.ID] = 1;
        Grafo[Nodo].pop_back();
        if(Considerar.Bien){
            Restantes--;
            Sirvi_ = 1;
        }
        if(DFS(Considerar.b) or Considerar.Bien){
            Camino.push_back(Nodo);
        } else {
            Aristas_usadas[Considerar.ID] = 0;
        }
    }
    if(!Sirvi_) Camino.pop_back();
    return Sirvi_;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    Grafo.assign(n, {});
    for(int i = 0; i < n - 1; i++){
        int a, b;
        long long c;
        cin>>a>>b>>c;
        a--;
        b--;
        Costos[{a, b}] = c;
        Costos[{b, a}] = c;
        Lista.push_back(Arista(a, b, i, c, false));
        Grafo[a].push_back(Arista(a, b, i, c, false));
        Grafo[b].push_back(Arista(b, a, i, c, false));
    }
    cin>>Restantes;
    for(int i = 0; i < Restantes; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Inicio = a;
        Costos[{a, b}] = 0;
        Costos[{b, a}] = 0;
        Lista.push_back(Arista(a, b, i + n - 1, 0, true));
        Grafo[a].push_back(Arista(a, b, i + n - 1, 0, true));
        Grafo[b].push_back(Arista(b, a, i + n - 1, 0, true));
    }
    for(int i = 0; i < n; i++) sort(Grafo[i].begin(), Grafo[i].end());
    DFS(Inicio);
    for(int i = 1; i < int(Camino.size()); i++){
        Costo_total += Costos[{Camino[i - 1], Camino[i]}];
    }
    cout<<Costo_total<<"\n";
    return 0;
}