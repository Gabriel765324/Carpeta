#include "bits/stdc++.h"
using namespace std;
random_device Hola;
mt19937 Aleatorizador(Hola());
struct Arista{
    int u, v;
    long long w;
    Arista(){}
    Arista(int U, int V, long long W){
        u = U;
        v = V;
        w = W;
    }
};
vector< vector<Arista> > Grafo, GrafoT;
vector< pair<int, int> > Orden;
vector<Arista> Lista;
int n, m, t = 0;
bitset<22> Visitados, Nada;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E.v]){
            DFS(E.v);
        }
    }
    Orden[Nodo] = {t, Nodo};
    t++;
}
vector<long long> Copia;
long long Calcular(vector<int>& a, bool Copiar){
    vector<long long> Asignados(n, 0);
    for(auto E: a){
        long long Menor = n + 22;
        for(auto e: GrafoT[E]){
            Menor = min(Menor, Asignados[e.v]);
        }
        Asignados[E] = Menor - 1LL;
    }
    long long Valor = 0;
    for(int i = 0; i < m; i++){
        Valor += (Asignados[Lista[i].u] - Asignados[Lista[i].v]) * Lista[i].w;
    }
    if(Copiar) Copia = Asignados;
    return Valor;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> Mejor_orden;
    long long Mejor = LLONG_MAX;
    uniform_real_distribution<double> Aleatorio_0_1(0, 1);
    uniform_int_distribution<int> Aleatorio_n(0, n - 1);
    Grafo.assign(n, {});
    GrafoT.assign(n, {});
    Orden.assign(n, {});
    Lista.assign(m, {});
    for(int i = 0; i < m; i++){
        cin>>Lista[i].u>>Lista[i].v>>Lista[i].w;
        Lista[i].u--;
        Lista[i].v--;
        Grafo[Lista[i].u].push_back(Lista[i]);
        swap(Lista[i].u, Lista[i].v);
        GrafoT[Lista[i].u].push_back(Lista[i]);
        swap(Lista[i].u, Lista[i].v);
    }
    if(n == 2){
        cout<<Lista[0].w<<"\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(!Visitados[i]){
            DFS(i);
        }
    }
    sort(Orden.rbegin(), Orden.rend());
    for(auto E: Orden) Mejor_orden.push_back(E.second);
    Mejor = Calcular(Mejor_orden, 0);
    double Temperatura = 10000;
    vector<int> Orden_actual = Mejor_orden;
    while(Temperatura >= 1e-6){
        //cerr<<Temperatura<<"\n";
        int Candidatoi, Candidatoj;
        while(1){
            int i = Aleatorio_n(Aleatorizador), j = Aleatorio_n(Aleatorizador);
            if(i == j) continue;
            swap(Orden_actual[i], Orden_actual[j]);
            Visitados &= Nada;
            bool Parar = 1;
            for(int k = 0; k < n and Parar; k++){
                Visitados[Orden_actual[k]] = 1;
                if(k == i or k == j){
                    for(auto E: GrafoT[Orden_actual[k]]){
                        if(!Visitados[E.v]){
                            Parar = 0;
                            break;
                        }
                    }
                }
            }
            Candidatoi = i;
            Candidatoj = j;
            if(Parar or (clock() / CLOCKS_PER_SEC >= 1.9)) break;
            else swap(Orden_actual[i], Orden_actual[j]);
        }
        long long Posible = Calcular(Orden_actual, 0);
        if(Posible < Mejor){
            Mejor = Posible;
            Mejor_orden = Orden_actual;
        } else {
            if(Aleatorio_0_1(Aleatorizador) > exp(-abs(Mejor - Posible) / Temperatura)){
                swap(Orden_actual[Candidatoi], Orden_actual[Candidatoj]);
            }
        }
        Temperatura *= 0.9999;
        if(clock() / CLOCKS_PER_SEC >= 1.9){
            cerr<<"Tiempo.\n";
            break;
        }
    }
    Calcular(Mejor_orden, 1);
    for(auto E: Copia) cout<<E<<" ";
    cout<<"\n";
    return 0;
}