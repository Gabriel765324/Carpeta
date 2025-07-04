#include "bits/stdc++.h"
using namespace std;
vector< vector< pair<long long, long long> > > Grafo;
vector<long long> Ancestros, Acumuladas;
map< pair<long long, long long>, long long > Pesos;
long long r = 0;
map<long long, long long> Propagante, _rbol;
void DFS(long long Nodo, long long Anterior, map<long long, long long> &Valores){
    vector<long long> Desahacer;
    if(Anterior != -2){
        Acumuladas[Nodo] = Acumuladas[Anterior] + Pesos[{Nodo, Anterior}];
        Ancestros[Nodo] = Anterior;
        r += Valores[Acumuladas[Nodo]];
        for(long long Actual = Anterior; Actual != -2; Actual = Ancestros[Actual]){
            Valores[2 * Acumuladas[Nodo] - Acumuladas[Actual]]++;
            Desahacer.push_back(2 * Acumuladas[Nodo] - Acumuladas[Actual]);
        }
    }
    for(auto E: Grafo[Nodo]){
        if(E.first != Anterior){
            DFS(E.first, Nodo, Valores);
        }
    }
    for(auto E: Desahacer) Valores[E]--;
}
long long Cero(long long Nodo, long long Anterior, long long Contador){
    long long Hijos = 0;
    for(auto E: Grafo[Nodo]){
        if(E.first != Anterior){
            Hijos += Cero(E.first, Nodo, Contador + 1);
        }
    }
    r += Hijos * Contador;
    return Hijos + 1;
}
void Propagar(long long p){
    _rbol[p] += Propagante[p];
    Propagante[p * 2] += Propagante[p];
    Propagante[p * 2 + 1] += Propagante[p];
    Propagante[p] = 0;
}
long long Consulta(long long i, long long d, long long p, long long I){
    //cerr<<p<<"\n";
    Propagar(p);
    if(i == I and d == I) return _rbol[p];
    if(i > I or d < I) return 0;
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, I) + Consulta(P + 1, d, p * 2 + 1, I);
}
void Actualizar(long long i, long long d, long long p, long long I, long long D, long long v){
    //cerr<<p<<"\n";
    Propagar(p);
    if(i >= I and d <= D){
        Propagante[p] += v;
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D, v);
    Actualizar(P + 1, d, p * 2 + 1, I, D, v);
}
void _rbol_de_segmentos(long long Nodo, long long Anterior, long long Contador){
    //cerr<<Nodo<<"\n";
    if(Anterior != -2){
        Acumuladas[Nodo] = Acumuladas[Anterior] + Pesos[{Nodo, Anterior}];
        Ancestros[Nodo] = Anterior;
        r += Consulta(-1e14, 1e14, 1, Acumuladas[Nodo]);
        Actualizar(-1e14, 1e14, 1, Acumuladas[Nodo] + 1, Acumuladas[Nodo] + Contador, 1);
    }
    for(auto E: Grafo[Nodo]){
        if(E.first != Anterior){
            _rbol_de_segmentos(E.first, Nodo, Contador + 1);
        }
    }
    if(Anterior != -2) Actualizar(-1e14, 1e14, 1, Acumuladas[Nodo] + 1, Acumuladas[Nodo] + Contador, -1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    Grafo.assign(n, {});
    Ancestros.assign(n, -2);
    Acumuladas.assign(n, 0);
    bool Ceroso = 1;
    bool Unoso = 1;
    for(long long i = 0; i < n - 1; i++){
        long long a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        if(c != 0) Ceroso = 0;
        if(c != 1) Unoso = 0;
        Grafo[a].push_back({b, c});
        Grafo[b].push_back({a, c});
        Pesos[{a, b}] = c;
        Pesos[{b, a}] = c;
    }
    map<long long, long long> Nada;
    if(Ceroso){
        long long No_messirve = Cero(0, -2, 0);
        cout<<r;
        return -0;
    }
    if(Unoso){
        _rbol_de_segmentos(0, -2, 0);
        cout<<r;
        return -0;
    }
    DFS(0, -2, Nada);
    cout<<r;
    return 0;
}
/*
7
1 2 0
2 4 0
2 5 0
3 6 0
3 7 0
1 3 0

7
1 2 1
2 4 1
2 5 1
3 6 1
3 7 1
1 3 1
*/