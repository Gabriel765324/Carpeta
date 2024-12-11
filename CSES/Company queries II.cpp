#include "bits/stdc++.h"
using namespace std;
struct Valor{
    long long u, v, ID;
};
bool operator<(const Valor& a, const Valor& b){
    if(a.u < b.u) return 1;
    else if(a.u > b.u) return 0;
    else return a.v < b.v;
}
/*vector<long long> Distancias;
bool o(Valor &a, Valor &b){
    long long v1 = min(Distancias[a.u], Distancias[a.v]), v2 = min(Distancias[b.u], Distancias[b.v]);
    return v1 > v2;
}
vector<long long> r;
long long Buscar(long long a){
    if(r[a] == a) return a;
    return r[a] = Buscar(r[a]);
}
void Unir(long long a, long long b){
    a = Buscar(a);
    b = Buscar(b);
    r[a] = b;
}*/
vector<long long> Orden;
vector<bool> Visitados;
vector< vector<long long> > Grafo;
void DFS(long long Nodo){
    Orden.push_back(Nodo);
    Visitados[Nodo] = 0;
    for(auto E: Grafo[Nodo]) if(!Visitados[E]) DFS(E);
    Orden.push_back(Nodo);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, q;
    cin>>n>>q;
    Grafo.assign(n, {});
    Visitados.assign(n, 0);
    for(long long i = 1; i < n; i++){
        long long a;
        cin>>a;
        a--;
        Grafo[a].push_back(i);
    }
    DFS(0);
    map<long long, pair<long long, long long> > Mapa;
    vector<bool> Primero(n, 1);
    for(long long i = 0; i < Orden.size(); i++){
        if(Primero[Orden[i]]){
            Primero[Orden[i]] = 0;
            Mapa[Orden[i]].first = i;
        } else Mapa[Orden[i]].second = i;
    }
    vector<Valor> Consultas(q);
    for(long long i = 0; i < q; i++){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Consultas[i].u = min(Mapa[a].first, Mapa[b].first);
        Consultas[i].v = max(Mapa[a].second, Mapa[b].second);
        Consultas[i].ID = i;
        //cout<<a<<" "<<b<<" "<<Consultas[i].u<<" "<<Consultas[i].v<<"\n";
    }
    vector< vector< pair<Valor, bool> > > Posiciones(Orden.size());
    for(long long i = 0; i < q; i++){
        Posiciones[Consultas[i].u].push_back(make_pair(Consultas[i], 0));
        Posiciones[Consultas[i].v].push_back(make_pair(Consultas[i], 1));
    }
    /*for(long long i = 0; i < Posiciones.size(); i++){
        cout<<i<<"\n";
        for(auto E: Posiciones[i]) cout<<E.first.u<<" "<<E.first.v<<" "<<E.first.ID<<" "<<E.second<<"    ";
        cout<<"\n";
    }*/
    multiset<Valor> s;
    vector<long long> Respuestas(q);
    for(long long i = 0; i < Orden.size(); i++){
        //cout<<i<<"\n";
        for(auto E: Posiciones[i]){
            if(E.second) s.insert(E.first);
            //cout<<E.first.u<<" "<<E.first.v<<" "<<E.first.ID<<" "<<E.second<<"    ";
            //cout<<"\n";
        }
        /*for(auto E: s) cout<<E.u<<" "<<E.v<<" "<<E.ID<<"    ";
        cout<<"\n";*/
        pair<long long, long long> Actual = Mapa[Orden[i]];
        if(i == Actual.second){
            Valor a;
            a.u = Actual.first;
            a.v = -2;
            a.ID = -2222;
            while(1){
                auto E = s.lower_bound(a);
                if(E == s.end() or (*E).u > i) break;
                Respuestas[(*E).ID] = Orden[i] + 1;
                s.erase(E);
            }
        }
    }
    for(auto E: Respuestas) cout<<E<<"\n";
    return 0;
}