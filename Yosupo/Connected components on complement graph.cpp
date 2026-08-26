#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    set< pair<int, int> > Mal;
    vector<bool> Visitados(n, 0);
    while(m--){
        int a, b;
        cin>>a>>b;
        Mal.insert({a, b});
        Mal.insert({b, a});
    }
    set<int> Ir;
    for(int i = 0; i < n; i++) Ir.insert(i);
    vector< vector<int> > Respuesta;
    for(int i = 0; i < n; i++){
        if(!Visitados[i]){
            Respuesta.push_back({});
            deque<int> Cola = {i};
            while(!Cola.empty()){
                int Nodo = Cola[0];
                Cola.pop_front();
                Respuesta.back().push_back(Nodo);
                Visitados[Nodo] = 1;
                Ir.erase(Nodo);
                vector<int> Borrar;
                for(auto E: Ir){
                    if(Mal.find({Nodo, E}) == Mal.end() and !Visitados[E]){
                        Cola.push_back(E);
                        Borrar.push_back(E);
                    }
                }
                for(auto E: Borrar) Ir.erase(E);
            }
        }
    }
    cout<<Respuesta.size()<<"\n";
    for(auto E: Respuesta){
        cout<<E.size()<<" ";
        for(auto e: E) cout<<e<<" ";
        cout<<"\n";
    }
    return 0;
}