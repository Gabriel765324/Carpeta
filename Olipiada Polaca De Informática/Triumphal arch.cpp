//En progreso. Hay que tomar en cuanta que el rey puede tratar de hacer bait y hacernos peder valores de gratis.
#include "bits/stdc++.h"
using namespace std;
vector<bool> Visitados;
vector< vector<long long> > Grafo;
bool Probar(long long Nodo, long long Gratis, long long Constructores){
    Visitados[Nodo] = 1;
    Gratis += Constructores;
    long long Necesario = Grafo[Nodo].size() - 1;
    Gratis -= Necesario;
    //cout<<Nodo<<" "<<Gratis<<"\n";
    //cout<<Nodo + 1<<" "<<Constructores<<"\n";
    if(Gratis < 0) return 0;
    for(auto E: Grafo[Nodo]){
        //cout<<Nodo<<" "<<E<<" "<<Visitados[E]<<"\n";
        if(!Visitados[E]){
            //cout<<"Tomo.\n";
            bool Resultado = Probar(E, Gratis, Constructores);
            //cout<<Resultado<<" ";
            if(Resultado == 0) return 0;
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, i = 0, d, Mejor;
    cin>>n;
    if(n == 1){
        cout<<0;
        return 0;
    }
    d = n + 22;
    Mejor = d;
    Grafo.assign(n + 1, {});
    Grafo[0].push_back(n);
    Grafo[n].push_back(0);
    n--;
    while(n--){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    n = Grafo.size();
    while(1){
        long long p = (i + d) / 2;
        Visitados.assign(n, 0);
        Visitados.back() = 1;
        if(Probar(0, 0, p) == 1){
            d = p - 1;
            Mejor = p;
            //cout<<p<<" sirve.\n";
        } else {
            i = p + 1;
            //cout<<p<<" no sirve.\n";
        }
        //for(auto E: Visitados) cout<<E<<" ";
        //cout<<"\n";
        if(i >= d + 1) break;
    }
    cout<<Mejor;
    return 0;
}
/*
14
1 2
2 3
2 4
2 5
5 9
4 7
4 6
3 8
10 8
8 11
8 12
8 13
8 14
*/