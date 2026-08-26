#include "bits/stdc++.h"
using namespace std;
struct Valor{
    long long u, v, ID;
};
bool operator<(const Valor& a, const Valor& b){
    if(a.u < b.u) return 1;
    else if(a.u > b.u) return 0;
    else if(a.v < b.v) return 1;
    else if(a.v > b.v) return 0;
    else return a.ID < b.ID;
}
bool o(Valor &a, Valor &b){
    if(a.v < b.v) return 1;
    else if(a.v > b.v) return 0;
    else if(a.u < b.u) return 1;
    else if(a.u > b.u) return 0;
    else return a.ID < b.ID;
}
vector<long long> Orden, Distancia;
vector<bool> Visitados, Segundos;
vector< vector<long long> > Grafo;
void DFS(long long Nodo, long long d){
    Orden.push_back(Nodo);
    Visitados[Nodo] = 1;
    Distancia[Nodo] = d;
    d++;
    Segundos.push_back(0);
    for(auto E: Grafo[Nodo]) if(!Visitados[E]) DFS(E, d);
    Orden.push_back(Nodo);
    Segundos.push_back(1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, q;
    cin>>n>>q;
    Grafo.assign(n, {});
    Visitados.assign(n, 0);
    Distancia.assign(n, 0);
    for(long long i = 1; i < n; i++){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    DFS(0, 0);
    unordered_map<long long, pair<long long, long long> > Mapa;
    vector<bool> Primero(n, 1);
    for(long long i = 0; i < Orden.size(); i++){
        if(Primero[Orden[i]]){
            Primero[Orden[i]] = 0;
            Mapa[Orden[i]].first = i;
        } else Mapa[Orden[i]].second = i;
    }
    vector<Valor> Consultas(q);
    unordered_map<long long, Valor> Lista;
    for(long long i = 0; i < q; i++){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Consultas[i].u = min(Mapa[a].first, Mapa[b].first);
        Consultas[i].v = max(Mapa[a].second, Mapa[b].second);
        Consultas[i].ID = i;
        Lista[i].ID = i;
        Lista[i].u = a;
        Lista[i].v = b;
    }
    vector<long long> Respuestas(q);
    sort(Consultas.begin(), Consultas.end(), o);
    long long c = 0;
    set< pair<long long, long long> > Posibles;
    /*for(auto E: Consultas){
        cout<<E.u<<" "<<E.v<<" "<<E.ID<<"\n";
    }
    for(auto E: Orden){
        cout<<E<<" ";
    }
    cout<<"\n";*/
    for(long long i = 0; c < q or Posibles.size() > 0; i++){
        //cout<<Orden[i]<<" "<<Segundos[i]<<"\n";
        //cout<<i<<"\n";
        for(; c < q and Consultas[c].v == i; c++){
            long long aaa = Posibles.size();
            Posibles.insert(make_pair(Consultas[c].u, Consultas[c].ID));
            //cout<<Consultas[c].u<<" "<<Consultas[c].v<<" "<<Consultas[c].ID<<" "<<(Posibles.size() != aaa ? "Bien" : "Mal")<<"\n";
        }
        /*for(auto E: Posibles){
            cout<<Lista[E.second].u<<" "<<Lista[E.second].v<<" "<<E.second<<"\n";
        }*/
        if(Segundos[i]){
            long long Actual = Mapa[Orden[i]].first;
            while(1){
                if(Posibles.size() == 0) break;
                auto E = Posibles.end();
                E--;
                if((*E).first < Actual) break;
                Valor a_b = Lista[(*E).second];
                Respuestas[(*E).second] = Distancia[a_b.u] + Distancia[a_b.v] - 2 * Distancia[Orden[i]];
                //cout<<a_b.u<<" "<<a_b.v<<" "<<a_b.ID<<"\n";
                Posibles.erase(E);
            }
        }
    }
    for(auto E: Respuestas) cout<<E<<"\n";
    return 0;
}