#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Grafo;
vector<bool> Visitados;
vector<long long> Padres;
long long Ciclado = -1, Final = -1;
void DFS(long long Nodo, long long Anterior){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(Visitados[E] and E != Anterior and Ciclado == -1){
            Ciclado = Nodo;
            Padres[E] = Nodo;
            Final = E;
        }
        if(!Visitados[E]){
            Padres[E] = Nodo;
            DFS(E, Nodo);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        Grafo.assign(n, vector<long long>());
        Visitados.assign(n, 0);
        Padres.assign(n, -1);
        Ciclado = -1;
        Final = -1;
        for(long long i = 0; i < n; i++){
            long long a, b;
            cin>>a>>b;
            a--;
            b--;
            Grafo[a].push_back(b);
            Grafo[b].push_back(a);
        }
        bool Iniciado = 0;
        for(long long i = 0; i < n; i++){
            //cout<<Grafo[i].size()<<" ";
            if(Grafo[i].size() == 1){
                DFS(i, -1);
                Iniciado = 1;
                Padres[i] = i;
                break;
            }
        }
        /*for(long long i = 0; i < n; i++){
            cout<<Padres[i]<<" ";
        }
        cout<<"\n";*/
        if(!Iniciado) cout<<n * (n - 1)<<"\n";
        else {
            Visitados.assign(n, 0);
            long long Nodo = Ciclado;
            set<long long> Ciclo;
            while(!Visitados[Nodo]){
                Visitados[Nodo] = 1;
                Nodo = Padres[Nodo];
                //cout<<Nodo<<" ";
                Ciclo.insert(Nodo);
            }
            long long No = 0;
            for(long long i = 0; i < n; i++){
                if(Visitados[i] and Ciclo.find(i) != Ciclo.end()){
                    long long Non = 0;
                    for(auto E: Grafo[i]){
                        if(!Visitados[E]){
                            deque<long long> Cola(1, E);
                            while(!Cola.empty()){
                                Non++;
                                Nodo = Cola[0];
                                Cola.pop_front();
                                Visitados[Nodo] = 1;
                                for(auto e: Grafo[Nodo]){
                                    if(!Visitados[e]) Cola.push_back(e);
                                }
                            }
                        }
                    }
                    No += Non * (Non + 1) / 2;
                    //cout<<"Ñ "<<i + 1<<" "<<No<<"\n";
                }
            }
            cout<<n * (n - 1) - No<<"\n"; 
        }
    }
    return 0;
}