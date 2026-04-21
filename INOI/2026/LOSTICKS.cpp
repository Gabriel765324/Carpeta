#include "bits/stdc++.h"
using namespace std;
vector< vector< pair<int, int> > > Grafo;
vector<int> Primero, Mapeo, Quedarse, Lista_de_llaves, M_nimo;
vector<long long> Distancias, _rbol, Arreglo;
vector< vector<long long> > PD;
void DFS(int Nodo, int Se_necesita){
    //cerr<<Nodo<<" ";
    M_nimo[Nodo] = Se_necesita;
    Primero[Nodo] = int(Arreglo.size());
    Arreglo.push_back(Distancias[Nodo]);
    for(auto E: Grafo[Nodo]){
        if(Distancias[E.first] <= Distancias[Nodo] + 1) continue;
        Distancias[E.first] = Distancias[Nodo] + 1LL;
        if(E.second != -2){
            Se_necesita += (1<<Mapeo[E.second]);
            DFS(E.first, Se_necesita);
            Se_necesita -= (1<<Mapeo[E.second]);
            Arreglo.push_back(Distancias[Nodo]);
            Quedarse[Mapeo[E.second]] = Nodo;
            continue;
        }
        DFS(E.first, Se_necesita);
        Arreglo.push_back(Distancias[Nodo]);
    }
}
void Crear(int i, int d, int p){
    if(i == d){
        _rbol[p] = Arreglo[i];
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol[p] = min(_rbol[p * 2], _rbol[p * 2 + 1]);
}
long long Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return 2222222222222222LL;
    int P = (i + d) / 2;
    return min(Consulta(i, P, p * 2, I, D), Consulta(P + 1, d, p * 2 + 1, I, D));
}
int n, i, f, ID, m;
long long Hallar_distancia(int Nodo0, int Nodo1){
    return Distancias[Nodo0] + Distancias[Nodo1] - 2LL * Consulta(0, m - 1, 1, min(Primero[Nodo0], Primero[Nodo1]), max(Primero[Nodo0], Primero[Nodo1]));
}
long long Resolver(int M_scara, int _ltimo){
    if(M_scara & M_nimo[f] == M_nimo[f]) return PD[M_scara][_ltimo] = Hallar_distancia(f, Quedarse[_ltimo]);
    if(PD[M_scara][_ltimo] != -2LL) return PD[M_scara][_ltimo];
    PD[M_scara][_ltimo] = -1LL;
    for(int i = 0; i < ID; i++){
        if(M_scara & (1<<i)) continue;
        //cerr<<M_nimo[Quedarse[i]]<<" "<<M_scara<<" "<<(M_nimo[Quedarse[i]] & M_scara)<<" "<<M_nimo[Quedarse[i]]<<"\n";
        if(((M_nimo[Quedarse[i]] & M_scara) == M_nimo[Quedarse[i]]) and ((M_nimo[Lista_de_llaves[i]] & M_scara) == M_nimo[Lista_de_llaves[i]])){
            //cerr<<M_nimo[Quedarse[i]]<<" "<<M_scara<<" Entró.\n";
            long long Respuesta = Resolver(M_scara + (1<<i), i);
            cerr<<M_scara<<" >> "<<M_scara + (1<<i)<<"\n";
            if(Respuesta < 0LL) continue;
            Respuesta += Hallar_distancia(Quedarse[_ltimo], Lista_de_llaves[i]) + Hallar_distancia(Lista_de_llaves[i], Quedarse[i]);
            if(PD[M_scara][_ltimo] == -1LL) PD[M_scara][_ltimo] = Respuesta;
            else PD[M_scara][_ltimo] = min(PD[M_scara][_ltimo], Respuesta);
        }
    }
    /*for(int i = 0; i < 6; i++){
        if((1<<i) & M_scara){
            cerr<<1;
        } else {
            cerr<<0;
        }
    }
    cerr<<" "<<_ltimo<<" "<<Quedarse[_ltimo]<<" "<<PD[M_scara][_ltimo]<<"\n";*/
    return PD[M_scara][_ltimo];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>i>>f;
    i--;
    f--;
    Grafo.assign(n, {});
    Distancias.assign(n, 2222222);
    Primero.assign(n, 0);
    Mapeo.assign(n, -2);
    Quedarse.assign(21, -2);
    M_nimo.assign(n, 0);
    Distancias[i] = 0;
    if(i == f){
        cout<<0;
        return 0;
    }
    set<int> Llaves;
    for(int a = 0; a < n - 1; a++){
        int u, v, t;
        cin>>u>>v>>t;
        u--;
        v--;
        t--;
        if(t == -1) t--;
        else Llaves.insert(t);
        Grafo[u].push_back({v, t});
        Grafo[v].push_back({u, t});
    }
    ID = 0;
    for(auto E: Llaves){
        Lista_de_llaves.push_back(E);
        Mapeo[E] = ID;
        ID++;
    }
    DFS(i, 0);
    /*for(auto E: M_nimo){
        for(int i = 0; i < 5; i++){
            if((1<<i) & E){
                cerr<<1;
            } else {
                cerr<<0;
            }
        }
        cerr<<"\n";
    }*/
    //Arreglo.push_back(0);
    m = int(Arreglo.size());
    _rbol.assign(m * 4 + 22, 0);
    Crear(0, m - 1, 1);
    /*for(auto E: Arreglo) cerr<<E<<" ";
    cerr<<"\n";
    for(auto E: _rbol) cerr<<E<<" ";
    cerr<<"\n";*/
    Quedarse[ID] = i;
    PD.assign((1<<ID), vector<long long>(ID + 1, -2));
    cout<<Resolver(0, ID);
    return 0;
}