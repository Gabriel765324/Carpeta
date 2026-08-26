#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin>>n>>m;
    vector< vector<int> > Grafo(n);
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    vector<int> Colores(n, 0);
    cin>>q;
    while(q--){
        int Nodo, d, c;
        cin>>Nodo>>d>>c;
        Nodo--;
        deque< pair<int, int> > Cola = {{0, Nodo}};
        vector<bool> Visitados(n, 0);
        Visitados[Nodo] = 1;
        while(!Cola.empty()){
            Nodo = Cola[0].second;
            int Distancia = Cola[0].first;
            Colores[Nodo] = c;
            Cola.pop_front();
            if(Distancia >= d) continue;
            for(auto E: Grafo[Nodo]){
                if(!Visitados[E]){
                    Visitados[E] = 1;
                    Cola.push_back({Distancia + 1, E});
                }
            }
        }
    }
    for(auto E: Colores) cout<<E<<"\n";
    return 0;
}