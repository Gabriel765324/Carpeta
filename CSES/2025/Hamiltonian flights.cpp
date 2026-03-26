#include "bits/stdc++.h"
using namespace std;
struct intm{
    long long a;
};
long long n, m, M = 1000000007;
intm operator+(const intm& a, const intm& b){
    intm c;
    c.a = (a.a % M + b.a % M) % M;
    return c;
}
vector< vector<intm> > PD;
vector< vector<int> > Grafo;
intm Uno, Cero;
intm DFS(int Nodo, int Visitados){
    Visitados += (1<<Nodo);
    if((Nodo == (n - 1)) and (Visitados >= ((1<<n) - 1))) return Uno;
    if(Nodo == (n - 1)) return Cero;
    if(PD[Nodo][Visitados].a != -2) return PD[Nodo][Visitados];
    intm r;
    r.a = 0;
    for(auto E: Grafo[Nodo]){
        if((Visitados & (1<<E)) == 0){
            r = r + DFS(E, Visitados);
        }
    }
    return PD[Nodo][Visitados - (1<<Nodo)] = r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Uno.a = 1;
    Cero.a = 0;
    cin>>n>>m;
    Grafo.assign(n, {});
    intm Nada;
    Nada.a = -2;
    PD.assign(n - 1, vector<intm>((1<<(n - 1)), Nada));
    while(m--){
        int a, b;
        cin>>a>>b;
        if(a == b or a == n) continue;
        a--;
        b--;
        Grafo[a].push_back(b);
    }
    vector<int> i(n, -1), Cola = {0};
    int Visitados = 0;
    intm Retorno;
    while(!Cola.empty()){
        int Nodo = Cola.back();
        Visitados += (1<<Nodo);
        if(Nodo == n - 1){
            if(Visitados >= ((1<<n) - 1)) Retorno = Uno;
            else Retorno = Cero;
            Visitados -= (1<<Nodo);
            Cola.pop_back();
            continue;
        }
        if(i[Nodo] == 0) PD[Nodo][Visitados] = Cero;
        i[Nodo]++;
        if(i[Nodo] >= Grafo[Nodo].size()){
            Retorno = PD[Nodo][Visitados];
            break;
        } else {
            PD[Nodo][Visitados] = PD[Nodo][Visitados] + Retorno;
        }
        for(; i[Nodo] < Grafo[Nodo].size(); i[Nodo]++){
            if((Visitados & (1<<Grafo[Nodo][i[Nodo]])) != 0) continue;
            Cola.push_back(Grafo[Nodo][i[Nodo]]);
            break;
        }
    }
    cout<<PD[0][1].a;
    return 0;
}