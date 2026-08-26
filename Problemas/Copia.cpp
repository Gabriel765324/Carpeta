#include "bits/stdc++.h"
using namespace std;
struct Valor{
    long long v, M_scara, Capa;
    Valor(){
        v = -2;
    }
};
struct Nodo{
    long long i, Suma, o;
    Nodo(){}
    Nodo(long long I){
        i = I;
        Suma = 0;
        o = 0;
    }
    bool operator<(const Nodo& a){
        return o < a.o;
    }
};
struct Arista{
    long long v, w;
    Arista(){}
    Arista(long long V, long long W){
        v = V;
        w = W;
    }
};
vector< vector< vector< vector<Valor> > > > PD;
vector< vector<Arista> > Grafo;
vector< vector<long long> > GrafoT;
vector<Nodo> Nodos;
bitset<22> Visitados;
vector<long long> NodosI;
long long n, m, t = 0;
void DFS(long long Nodo){
    Visitados[Nodo] = 1;
    Nodos[Nodo].i = Nodo;
    for(auto E: Grafo[Nodo]) if(!Visitados[E.v]) DFS(E.v);
    Nodos[Nodo].o = t;
    t++;
}
long long Resolver(long long M_scara, long long Capa, long long Tomado, long long i){
    if(M_scara == ((1<<n) - 1)){
        PD[M_scara][Capa][Tomado][i].M_scara = M_scara;
        PD[M_scara][Capa][Tomado][i].Capa = Capa;
        return PD[M_scara][Capa][Tomado][i].v = 0;
    }
    if(Tomado == 0 and i == n) return 2e8;
    if(Tomado == 1 and i == n){
        PD[M_scara][Capa][Tomado][i].M_scara = M_scara;
        PD[M_scara][Capa][Tomado][i].Capa = Capa - 1;
        return PD[M_scara][Capa][Tomado][i].v = Resolver(M_scara, Capa - 1, 0, 0);
    }
    if(PD[M_scara][Capa][Tomado][i].v != -2) return PD[M_scara][Capa][Tomado][i].v;
    long long Nodo = Nodos[i].i;
    bool Tomable = (M_scara & (1<<i)) ? false : true;
    for(auto E: GrafoT[Nodo]){
        if(!Tomable) break;
        long long NodoE = NodosI[E];
        //cerr<<i + 1<<": "<<Nodo + 1<<" -> "<<E + 1<<": "<<NodoE + 1<<"\n";
        Tomable = Tomable and ((M_scara & (1<<NodoE)) ? true : false);
    }
    if(!Tomable){
        PD[M_scara][Capa][Tomado][i].M_scara = M_scara;
        PD[M_scara][Capa][Tomado][i].Capa = Capa;
        return PD[M_scara][Capa][Tomado][i].v = Resolver(M_scara, Capa, Tomado, i + 1);
    }
    long long v0 = Resolver(M_scara, Capa, Tomado, i + 1), v1 = Resolver(M_scara | (1<<i), Capa, 1, i + 1) - Nodos[i].Suma * Capa;
    if(v0 < v1){
        PD[M_scara][Capa][Tomado][i].M_scara = M_scara;
        PD[M_scara][Capa][Tomado][i].Capa = Capa;
        return PD[M_scara][Capa][Tomado][i].v = v0;
    }
    PD[M_scara][Capa][Tomado][i].M_scara = M_scara | (1<<i);
    PD[M_scara][Capa][Tomado][i].Capa = Capa;
    return PD[M_scara][Capa][Tomado][i].v = v1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    PD.assign(1<<n, vector< vector< vector<Valor> > >(22, vector< vector<Valor> >(2, vector<Valor>(n + 1))));
    Grafo.assign(n, {});
    GrafoT.assign(n, {});
    Nodos.assign(n, Nodo());
    NodosI.assign(n, 0);
    while(m--){
        long long a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        Grafo[a].push_back(Arista(b, c));
        GrafoT[b].push_back(a);
        Nodos[a].Suma += c;
        Nodos[b].Suma -= c;
    }
    /*for(auto E: GrafoT){
        for(auto e: E){
            cerr<<e + 1<<" ";
        }
        cerr<<"\n";
    }*/
    for(long long i = 0; i < n; i++) if(!Visitados[i]) DFS(i);
    sort(Nodos.begin(), Nodos.end());
    for(long long i = 0; i < n; i++) NodosI[Nodos[i].i] = i;
    /*for(auto E: Nodos) cerr<<E.i + 1<<" ";
    cerr<<"\n";*/
    long long Nada = Resolver(0, 21, 0, 0);
    vector<long long> Asignaci_n(n);
    long long M_scara_actual = 0, Capa_actual = 21, Tomado = 0, i = 0;
    while(1){
        if(M_scara_actual == ((1<<n) - 1)) break;
        long long M_scara_siguiente = PD[M_scara_actual][Capa_actual][Tomado][i].M_scara;
        long long Capa_siguiente = PD[M_scara_actual][Capa_actual][Tomado][i].Capa;
        if(Capa_siguiente != Capa_actual){
            Capa_actual = Capa_siguiente;
            Tomado = 0;
            i = 0;
            continue;
        }
        if(M_scara_actual == M_scara_siguiente){
            i++;
            continue;
        }
        M_scara_actual = M_scara_siguiente;
        Tomado = 1;
        Asignaci_n[Nodos[i].i] = Capa_actual;
        i++;
    }
    for(auto E: Asignaci_n) cout<<E<<" ";
    return 0;
}