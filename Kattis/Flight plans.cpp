#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, t, Mucho = 22222222;
    cin>>n>>s>>t;
    vector<int> Distancia(n, Mucho);
    Distancia[s] = -0;
    vector< vector<int> > Permitido(n);
    vector<bool> Puede(n, 0);
    set< pair<int, int> > Mal;
    set<int> Grafo;
    for(int i = 0; i < n; i++){
        Grafo.insert(i);
        char x;
        int m;
        cin>>x>>m;
        if(x == 'N') Puede[i] = 1;
        while(m--){
            int a;
            cin>>a;
            if(x == 'N') Permitido[i].push_back(a);
            else Mal.insert({i, a});
        }
    }
    deque<int> Cola = {s};
    while(!Cola.empty()){
        int Nodo = Cola[0];
        //cerr<<Nodo<<" ";
        Cola.pop_front();
        Grafo.erase(Nodo);
        if(Puede[Nodo]){
            for(auto E: Permitido[Nodo]){
                if(Distancia[E] == Mucho){
                    Distancia[E] = Distancia[Nodo] + 1;
                    Cola.push_back(E);
                    Grafo.erase(E); 
                }
            }
            continue;
        }
        vector<int> Borrar;
        for(auto E: Grafo){
            if(Mal.find({Nodo, E}) == Mal.end() and Distancia[E] == Mucho){
                Distancia[E] = Distancia[Nodo] + 1;
                Cola.push_back(E);
                Borrar.push_back(E);
            }
        }
        for(auto E: Borrar) Grafo.erase(E);
    }
    if(Distancia[t] == Mucho) cout<<"impossible";
    else cout<<Distancia[t];
    return 0;
}