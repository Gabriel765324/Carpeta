#include <bits/stdc++.h>
using namespace std;
struct Arista{
    int u, v, ID_del_opuesto, ID_del_inverso;
    long long Capacidad, Flujo;
};
vector<Arista> Lista;
vector< vector<int> > Grafo;
vector<int> Niveles, Punteros;
int n;
bool BFS(){
    Niveles.assign(n, 222222);
    Niveles[0] = 0;
    deque<int> Cola;
    Cola.push_back(0);
    while(!Cola.empty()){
        int Nodo = Cola[0];
        //cerr<<Nodo<<" Nodo.\n";
        Cola.pop_front();
        for(auto E: Grafo[Nodo]){
            if(Lista[E].Flujo >= Lista[E].Capacidad) continue;
            if(Niveles[Lista[E].v] > Niveles[Nodo] + 1){
                /*cerr<<Nodo<<" -> "<<Lista[E].v<<"\n";
                cerr<<Niveles[Nodo] + 1<<" "<<Niveles[Lista[E].v]<<"\n";*/
                //cerr<<Niveles[Lista[E].v]<<" ";
                Niveles[Lista[E].v] = Niveles[Nodo] + 1;
                //cerr<<Niveles[Lista[E].v]<<"\n";
                Cola.push_back(Lista[E].v);
            }
        }
        /*for(auto E: Niveles) cerr<<E<<" ";
        cerr<<"\n";*/
    }
    //cerr<<(int)(Niveles[n - 1] != 222222)<<" Resultado.\n";
    return Niveles[n - 1] != 222222;
}
long long DFS(int Nodo, long long Flujo){
    //cerr<<Nodo<<" ";
    if(Nodo == n - 1) return Flujo;
    for(; Punteros[Nodo] < Grafo[Nodo].size(); Punteros[Nodo]++){
        int ID = Grafo[Nodo][Punteros[Nodo]];
        //cerr<<Nodo<<" "<<Lista[ID].v<<"\n";
        if(Lista[ID].Flujo >= Lista[ID].Capacidad or Niveles[Lista[ID].v] != Niveles[Nodo] + 1){
            //cerr<<"No.\n";
            continue;
        }
        //cerr<<"Sí.\n";
        Flujo = min(Flujo, Lista[ID].Capacidad - Lista[ID].Flujo);
        long long Mandar = DFS(Lista[ID].v, Flujo);
        //cerr<<Nodo<<" "<<Lista[ID].v<<" "<<Lista[ID].Flujo<<" "<<Lista[ID].Capacidad<<" "<<Mandar<<"\n";
        if(Mandar != 0){
            Lista[ID].Flujo += Mandar;
            Lista[Lista[ID].ID_del_inverso].Flujo -= Mandar;
            return Mandar;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m;
    int ID = 0;
    Grafo.assign(n, {});
    while(m--){
        int a, b;
        long long c;
        cin>>a>>b>>c;
        if(a == b) continue;
        a--;
        b--;
        Lista.push_back(Arista{a, b, ID + 2, ID + 1, c, 0});
        Lista.push_back(Arista{b, a, ID + 3, ID, 0, 0});
        Lista.push_back(Arista{b, a, ID, ID + 3, c, 0});
        Lista.push_back(Arista{a, b, ID + 1, ID + 2, 0, 0});
        Grafo[a].push_back(ID);
        Grafo[a].push_back(ID + 3);
        Grafo[b].push_back(ID + 1);
        Grafo[b].push_back(ID + 2);
        ID += 4;
    }
    long long Flujo = 0;
    while(BFS()){
        //cerr<<Flujo<<"\n";
        Punteros.assign(n, 0);
        long long Actual = 0;
        while(Actual = DFS(0, LLONG_MAX)){
            if(Actual == 0) break;
            Flujo += Actual;
            //cerr<<Flujo<<" Flujo\n";
        }
    }
    cout<<Flujo;
    return 0;
}