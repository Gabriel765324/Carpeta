#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo;
vector<int> Llaves;
map< pair<int, int>, int> Mapa;
int Permitido;
bitset<7> Visitados, Nada;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(Permitido == Llaves[Mapa[{Nodo, E}]] and !Visitados[E]) DFS(E);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    Grafo.assign(n, {});
    if(n <= 5){
        int t = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int a;
                cin>>a;
                if(a == 1){
                    Mapa[{i, j}] = t;
                    t++;
                    Grafo[i].push_back(j);
                }
            }
        }
        for(int i = 2; i <= 5; i++){
            Llaves.assign(n, 1);
            bool Seguir = 1;
            while(Seguir){
                for(int j = 0; j < n; j++){
                    Llaves[j]++;
                    if(Llaves[j] > i){
                        Llaves[j] = 1;
                        if(j == n - 1) Seguir = 0;
                    } else {
                        break;
                    }
                }
                if(!Seguir) break;
                bool Bien = 1;
                for(int j = 0; j < n; j++){
                    bitset<7> Total;
                    for(Permitido = 1; Permitido <= 5; Permitido++){
                        Visitados &= Nada;
                        DFS(j);
                        Total |= Visitados;
                    }
                    Bien = Bien and Total.count() < n;
                }
                if(Bien){
                    cout<<i<<"\n";
                    for(int j = 0; j < n; j++){
                        for(int k = 0; k < n; k++){
                            if(Mapa.count({j, k}) == 0) cout<<"0 ";
                            else cout<<Llaves[Mapa[{j, k}]]<<" ";
                        }
                        cout<<"\n";
                    }
                    return 0;
                }
            }
        }
    }
    cout<<-1;
    return 0;
}