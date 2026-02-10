#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo, GrafoT;
vector<bool> Visitados;
vector<int> Pertenecer;
deque<int> Orden;
set<int> No_tomar;
int Tiempo, Actual, P, n, m;
void DFS(int Nodo, bool Transpuesto){
    if(Transpuesto){
        Pertenecer[Nodo] = Actual;
        No_tomar.erase(Nodo);
        if(Nodo >= n){
            int Anterior = Nodo - P + 1 - n;
            for(auto E = No_tomar.lower_bound(Anterior); E != No_tomar.end() and *E <= (Nodo + P - 1 - n); E = No_tomar.lower_bound(Anterior)){
                Anterior = *E + 1;
                if(*E == Nodo - n){
                    Anterior = Nodo - n + 1;
                    continue;
                }
                if(Pertenecer[*E] == -2){
                    DFS(*E, 1);
                }
            }
        }
        for(auto E: GrafoT[Nodo]){
            if(Pertenecer[E] == -2){
                DFS(E, 1);
            }
        }
        return;
    }
    Visitados[Nodo] = 1;
    No_tomar.erase(Nodo);
    if(Nodo < n){
        int Anterior = Nodo - P + 1 + n;
        for(auto E = No_tomar.lower_bound(Anterior); E != No_tomar.end() and *E <= (Nodo + P - 1 + n); E = No_tomar.lower_bound(Anterior)){
            Anterior = *E + 1;
            if(*E == n + Nodo){
                Anterior = n + Nodo + 1;
                continue;
            }
            if(!Visitados[*E]){
                DFS(*E, 0);
            }
        }
    }
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E]){
            DFS(E, 0);
        }
    }
    Orden.push_front(Nodo);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int Caso = 0; Caso < t; Caso++){
        cin>>n>>m;
        vector< pair<int, int> > Aristas;
        for(int i = 0; i < m; i++){
            int a, b;
            cin>>a>>b;
            a--;
            b--;
            Aristas.push_back({a, b});
        }
        int I = 2, D = n, M = 1;
        while(I < D + 1){
            P = (I + D) / 2;
            No_tomar.clear();
            for(int i = 0; i < n; i++){
                No_tomar.insert(i + n);
            }
            Grafo.assign(n * 2 + 22, {});
            GrafoT.assign(n * 2 + 22, {});
            for(auto E: Aristas){
                if(E.first == E.second){
                    Grafo[E.first + n].push_back(E.first);
                    GrafoT[E.first].push_back(E.first + n);
                } else if(abs(E.first - E.second) >= P){
                    Grafo[E.first + n].push_back(E.second);
                    GrafoT[E.second].push_back(E.first + n);
                    Grafo[E.second + n].push_back(E.first);
                    GrafoT[E.first].push_back(E.second + n);
                } else {
                    Grafo[E.first].push_back(E.second + n);
                    GrafoT[E.second + n].push_back(E.first);
                    Grafo[E.second].push_back(E.first + n);
                    GrafoT[E.first + n].push_back(E.second);
                    Grafo[E.first + n].push_back(E.second);
                    GrafoT[E.second].push_back(E.first + n);
                    Grafo[E.second + n].push_back(E.first);
                    GrafoT[E.first].push_back(E.second + n);
                }
            }
            Visitados.assign(n * 2 + 22, 0);
            Tiempo = -0;
            Orden.clear();
            for(int i = 0; i < n * 2; i++){
                if(!Visitados[i]) DFS(i, 0);
            }
            No_tomar.clear();
            for(int i = 0; i < n; i++){
                No_tomar.insert(i);
            }
            Pertenecer.assign(n * 2 + 22, -2);
            Actual = -0;
            for(auto E: Orden){
                if(Pertenecer[E] == -2){
                    DFS(E, 1);
                    Actual++;
                }
            }
            bool Bien = 1;
            for(int i = 0; i < n; i++){
                if(Pertenecer[i] == Pertenecer[i + n]){
                    Bien = 0;
                    break;
                }
            }
            if(Bien){
                I = P + 1;
                M = P;
            } else {
                D = P - 1;
            }
        }
        cout<<M<<"\n";
    }
    return 0;
}