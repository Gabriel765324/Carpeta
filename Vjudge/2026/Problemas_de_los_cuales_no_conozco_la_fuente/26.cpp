#include "bits/stdc++.h"
using namespace std;
long long Mucho = 2222222222222222;
struct Arista{
    long long Capacidad, Flujo, Distancia, u, v, ID, iID;
    Arista(long long c, long long f, long long d, long long U, long long V, long long i, long long ii){
        Capacidad = c;
        Flujo = f;
        Distancia = d;
        u = U;
        v = V;
        ID = i;
        iID = ii;
    }
};
struct En_la_cola{
    long long Nodo, Distancia;
    En_la_cola(long long n, long long d){
        Nodo = n;
        Distancia = d;
    }
};
bool operator==(const En_la_cola& a, const En_la_cola& b){
    return a.Nodo == b.Nodo and a.Distancia == b.Distancia;
}
bool operator<(const En_la_cola& a, const En_la_cola& b){
    if(a == b) return 0;
    if(a.Distancia < b.Distancia) return 1;
    if(a.Distancia > b.Distancia) return 0;
    return a.Nodo < b.Nodo;
}
bool operator<=(const En_la_cola& a, const En_la_cola& b){
    if(a == b) return 1;
    if(a.Distancia < b.Distancia) return 1;
    if(a.Distancia > b.Distancia) return 0;
    return a.Nodo < b.Nodo;
}
bool operator>(const En_la_cola& a, const En_la_cola& b){
    if(a == b) return 0;
    if(a.Distancia > b.Distancia) return 1;
    if(a.Distancia < b.Distancia) return 0;
    return a.Nodo > b.Nodo;
}
bool operator>=(const En_la_cola& a, const En_la_cola& b){
    if(a == b) return 1;
    if(a.Distancia > b.Distancia) return 1;
    if(a.Distancia < b.Distancia) return 0;
    return a.Nodo > b.Nodo;
}
struct Flujito{
    long long n, ID;
    vector<long long> Distancias, Potenciales, Padres, Flujitos;
    vector<Arista> Aristas;
    vector< vector<long long> > Grafo;
    Flujito(long long N){
        n = N;
        ID = 0;
        Grafo.assign(n, {});
        Distancias.assign(n, Mucho);
        Potenciales.assign(n, 0);
        Flujitos.assign(n, 0);
        Padres.assign(n, -2);
    }
    void Aristear(long long u, long long v){
        Aristas.push_back(Arista(1, 0, 1, u, v, ID, ID + 1));
        Aristas.push_back(Arista(0, 0, -1, v, u, ID + 1, ID));
        Grafo[u].push_back(ID);
        Grafo[v].push_back(ID + 1);
        ID += 2;
    }
    long long Flujo_m_ximo(){
        long long Flujito = 0;
        bool Seguir = 1;
        while(Seguir){
            Seguir = 0;
            for(long long i = 1; i < n; i++){
                Distancias[i] = Mucho;
                Flujitos[i] = 0;
            }
            Distancias[0] = 0;
            Flujitos[0] = Mucho;
            priority_queue< En_la_cola, vector<En_la_cola>, greater<En_la_cola> > Cola;
            Cola.push(En_la_cola(0, 0));
            while(!Cola.empty()){
                long long Nodo = Cola.top().Nodo, Distancia = Cola.top().Distancia;
                //cerr<<Nodo<<" Nodo del algoritmo de Dijkstra.\n";
                Cola.pop();
                if(Nodo == n - 1){
                    Seguir = 1;
                    //continue;
                }
                if(Distancia > Distancias[Nodo]) continue;
                for(auto E: Grafo[Nodo]){
                    long long Siguiente = Aristas[E].v;
                    if(Aristas[E].Flujo < Aristas[E].Capacidad and Aristas[E].Distancia + Distancia - Potenciales[Siguiente] + Potenciales[Nodo] < Distancias[Siguiente]){
                        Distancias[Siguiente] = Aristas[E].Distancia + Distancia - Potenciales[Siguiente] + Potenciales[Nodo];
                        Cola.push(En_la_cola(Siguiente, Distancias[Siguiente]));
                        Padres[Siguiente] = E;
                        Flujitos[Siguiente] = min(Flujitos[Nodo], Aristas[E].Capacidad - Aristas[E].Flujo);
                    }
                }
            }
            if(Distancias[n - 1] == Mucho) return Flujito;
            Flujitos[n - 1] = min(Flujitos[n - 1], Mucho - Flujitos[n - 1]);
            Flujito += Flujitos[n - 1];
            //bitset<522> Visitados;
            long long Nodo = n - 1;
            while(Nodo != 0){
                //Visitados[Nodo] = 1;
                Aristas[Padres[Nodo]].Flujo += Flujitos[n - 1];
                Aristas[Aristas[Padres[Nodo]].iID].Flujo -= Flujitos[n - 1];
                Nodo = Aristas[Padres[Nodo]].u;
                //if(Visitados[Nodo]) Nodo = Aristas[Padres[Nodo]].v;
                //cerr<<Nodo<<" Nodo.\n";
            }
            for(long long i = 0; i < n; i++){
                if(Distancias[i] < Mucho) Potenciales[i] += Distancias[i];
            }
            //cerr<<Flujito<<"\n";
        }
        return Flujito;
    }
};
bool operator<(const vector<long long>& a, const vector<long long>& b){
    return int(a.size()) < int(b.size());
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, k, Corte;
    cin>>n>>m>>k;
    Flujito Red = Flujito(n);
    while(m--){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Red.Aristear(a, b);
    }
    Corte = Red.Flujo_m_ximo();
    if(Corte < k){
        cout<<-1;
        return 0;
    }
    vector< vector<long long> > Caminos;
    while(1){
        vector<long long> Posible = {0};
        long long Nodo = 0;
        while(Nodo != n - 1){
            bool Finalizar = 1;
            for(auto E: Red.Grafo[Nodo]){
                if(Red.Aristas[E].Capacidad <= Red.Aristas[E].Flujo){
                    Red.Aristas[E].Capacidad++;
                    Red.Aristas[E].Flujo -= Mucho;
                    Nodo = Red.Aristas[E].v;
                    Finalizar = 0;
                    break;
                }
            }
            if(Finalizar) break;
            Posible.push_back(Nodo);
        }
        if(Posible.back() == n - 1) Caminos.push_back(Posible);
    }
    sort(Caminos.begin(), Caminos.end());
    long long Kromer = 0;
    for(long long i = 0; i < k; i++){
        Kromer += (long long)(Caminos[i].size()) - 1LL;
    }
    cout<<Kromer<<"\n";
    for(long long i = 0; i < n; i++){
        cout<<(long long)(Caminos[i].size())<<"\n";
        for(auto E: Caminos[i]){
            cout<<E + 1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}