#include "bits/stdc++.h"
using namespace std;
struct Arista{
    int v, ID_inverso, Capacidad, Flujo;
};
vector<Arista> Lista;
vector< vector<int> > Grafo;
vector<int> Niveles, Punteros;
bool BFS(int i, int f){
    for(int j = 0; j < Niveles.size(); j++) Niveles[j] = 2222;
    Niveles[i] = 0;
    deque<int> Cola = {i};
    while(!Cola.empty()){
        int Nodo = Cola[0];
        Cola.pop_front();
        for(auto E: Grafo[Nodo]){
            if(Lista[E].Flujo >= Lista[E].Capacidad or Niveles[Lista[E].v] <= Niveles[Nodo] + 1) continue;
            Niveles[Lista[E].v] = Niveles[Nodo] + 1;
            Cola.push_back(Lista[E].v);
        }
    }
    return Niveles[f] != 2222;
}
int DFS(int Nodo, int Final, int Flujo){
    if(Nodo == Final) return Flujo;
    for(; Punteros[Nodo] < Grafo[Nodo].size(); Punteros[Nodo]++){
        int ID = Grafo[Nodo][Punteros[Nodo]];
        if(Lista[ID].Flujo >= Lista[ID].Capacidad or Niveles[Lista[ID].v] != Niveles[Nodo] + 1) continue;
        Flujo = min(Flujo, Lista[ID].Capacidad - Lista[ID].Flujo);
        int Mandar = DFS(Lista[ID].v, Final, Flujo);
        if(Mandar != 0){
            Lista[ID].Flujo += Mandar;
            Lista[Lista[ID].ID_inverso].Flujo -= Mandar;
            Punteros[Nodo]++;
            return Mandar;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, nn, m;
    cin>>n>>nn>>m;
    Grafo.assign(n + nn + 22, {});
    Niveles.assign(n + nn + 22, 2222);
    int ID = 0;
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b = b - 1 + n;
        Grafo[a].push_back(ID);
        Grafo[b].push_back(ID + 1);
        Lista.push_back((Arista){b, ID + 1, 1, 0});
        Lista.push_back((Arista){a, ID, 0, 0});
        ID += 2;
    }
    for(int i = 0; i < n; i++){
        Grafo[n + nn + 2].push_back(ID);
        Grafo[i].push_back(ID + 1);
        Lista.push_back((Arista){i, ID + 1, 1, 0});
        Lista.push_back((Arista){n + nn + 2, ID, 0, 0});
        ID += 2;
    }
    for(int i = n; i < nn + n; i++){
        Grafo[i].push_back(ID);
        Grafo[n + nn + 4].push_back(ID + 1);
        Lista.push_back((Arista){n + nn + 4, ID + 1, 1, 0});
        Lista.push_back((Arista){i, ID, 0, 0});
        ID += 2;
    }
    int Flujo = 0;
    Punteros.assign(n + nn + 22, 0);
    while(BFS(n + nn + 2, n + nn + 4)){
        int Mandar;
        while(Mandar = DFS(n + nn + 2, n + nn + 4, 2222)){
            if(Mandar == 0) break;
            Flujo += Mandar;
        }
        for(int i = 0; i < n + nn + 22; i++) Punteros[i] = 0;
    }
    cout<<Flujo;
    return 0;
}