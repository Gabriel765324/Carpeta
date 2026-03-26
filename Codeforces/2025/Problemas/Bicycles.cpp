#include "bits/stdc++.h"
using namespace std;
vector< vector< pair<long long, long long> > > Grafo;
vector<long long> Tortuguificaci_n;
vector< vector<long long> > Menores;
vector< vector<bool> > Visitados;
map<long long, long long> Bicicletas;
struct Valor{
    long long Nodo, Bicicleta, Distancia;
};
bool operator<(const Valor& a, const Valor& b){
    if(a.Distancia < b.Distancia) return 1;
    else if(a.Distancia > b.Distancia) return 0;
    else if(a.Bicicleta < b.Bicicleta) return 1;
    else if(a.Bicicleta > b.Bicicleta) return 0;
    else return a.Nodo < b.Nodo;
}
long long Dijkstra(){
    set<Valor> Cola;
    Valor Inicio;
    Inicio.Distancia = 0;
    Inicio.Bicicleta = Tortuguificaci_n[0];
    Inicio.Nodo = 0;
    Cola.insert(Inicio);
    while(!Cola.empty()){
        Valor Actual = *Cola.begin();
        Cola.erase(Cola.begin());
        Actual.Bicicleta = min(Actual.Bicicleta, Tortuguificaci_n[Actual.Nodo]);
        long long ID = Bicicletas[Actual.Bicicleta];
        if(!Visitados[Actual.Nodo][ID] or Menores[Actual.Nodo][ID] > Actual.Distancia){
            Menores[Actual.Nodo][ID] = min(Actual.Distancia, Menores[Actual.Nodo][ID]);
            for(auto E: Grafo[Actual.Nodo]){
                if(Menores[E.first][ID] > Actual.Distancia + Actual.Bicicleta * E.second){
                    Menores[E.first][ID] = Actual.Distancia + Actual.Bicicleta * E.second;
                    Valor Nuevo;
                    Nuevo.Bicicleta = Actual.Bicicleta;
                    Nuevo.Distancia = Menores[E.first][ID];
                    Nuevo.Nodo = E.first;
                    Visitados[E.first][ID] = 0;
                    /*if(Tortuguificaci_n[E.first] < Actual.Bicicleta and Menores[E.first][Bicicletas[Tortuguificaci_n[E.first]]] > Nuevo.Distancia){
                        Visitados[E.first][Bicicletas[Tortuguificaci_n[E.first]]] = 0;
                        Menores[E.first][Bicicletas[Tortuguificaci_n[E.first]]] = Nuevo.Distancia;
                    }*/
                    Cola.insert(Nuevo);
                }
            }
            Visitados[Actual.Nodo][ID] = 1;
        }
    }
    long long r = 2222222222222222;
    for(auto E: Menores.back()) r = min(r, E);
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        Tortuguificaci_n.assign(n, 0);
        Grafo.assign(n, {});
        for(long long i = 0; i < m; i++){
            long long u, v, w;
            cin>>u>>v>>w;
            u--;
            v--;
            Grafo[u].push_back(make_pair(v, w));
            Grafo[v].push_back(make_pair(u, w));
        }
        Bicicletas.clear();
        set<long long> Diferentes;
        for(long long i = 0; i < n; i++){
            cin>>Tortuguificaci_n[i];
            Diferentes.insert(Tortuguificaci_n[i]);
        }
        long long i = 0;
        for(auto E = Diferentes.begin(); E != Diferentes.end(); E++){
            Bicicletas[*E] = i;
            i++;
        }
        Menores.assign(n, vector<long long>(Diferentes.size(), 2222222222222222));
        Visitados.assign(n, vector<bool>(Diferentes.size(), 1));
        cout<<Dijkstra()<<"\n";
    }
    return 0;
}