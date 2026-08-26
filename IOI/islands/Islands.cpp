#include "bits/stdc++.h"
using namespace std;
struct Arista{
    long long Siguiente, Peso;
};
struct Hijo{
    long long Valor_abierto, Valor_cerrado, _ndice;
};
long long Menos = -2222222222222222;
vector< vector<Arista> > Grafo;
map< pair<long long, long long>, long long > Pesos;
vector<bool> Visitados;
vector<long long> Padres, Valor_de_los_nodos;
vector< pair<long long, long long> > Nodos_que_hacen_los_ciclos, Memorizaci_n;
long long Ciclante, Inicio_del_ciclo;
set<long long> No_pasar_por_aqu_;
vector<long long> _rbol_izquierdo, _rbol_derecho, Propagar_izquierdo, Propagar_derecho, Izquierdo, Derecho;
void DFS(long long Nodo, long long Anterior){
    Visitados[Nodo] = 1;
    Padres[Nodo] = Anterior;
    bool Padre_visitado = 0;
    for(auto E: Grafo[Nodo]){
        if(Visitados[E.Siguiente]){
            //Detectar el único ciclo del componente conexo.
            if(E.Siguiente == Anterior){
                if(Padre_visitado){
                    Ciclante = Nodo;
                    Inicio_del_ciclo = E.Siguiente;
                } else Padre_visitado = 1;
            } else {
                Ciclante = Nodo;
                Inicio_del_ciclo = E.Siguiente;
            }
        } else DFS(E.Siguiente, Nodo);
    }
}
bool o(Hijo &a, Hijo &b){
    return a.Valor_abierto > b.Valor_abierto;
}
void PD(long long Nodo){
    //Obtener los caminos más largos dentro de los subárboles de los nodos que forman los ciclos.
    Visitados[Nodo] = 1;
    bool Final = 1;
    vector<Hijo> Hijos;
    long long Cerrado = 0, Abierto = 0;
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E.Siguiente] and No_pasar_por_aqu_.count(E.Siguiente) == 0){
            PD(E.Siguiente);
            Final = 0;
            Hijo Siguiente;
            Siguiente._ndice = E.Siguiente;
            Siguiente.Valor_abierto = Memorizaci_n[E.Siguiente].first;
            Siguiente.Valor_cerrado = Memorizaci_n[E.Siguiente].second;
            Hijos.push_back(Siguiente);
            Cerrado = max(Cerrado, Siguiente.Valor_cerrado);
            Abierto = max(Abierto, Siguiente.Valor_abierto + E.Peso);
        }
    }
    if(Final){
        Memorizaci_n[Nodo] = {0, 0};
        return;
    }
    sort(Hijos.begin(), Hijos.end(), o);
    if(Hijos.size() == 1) Cerrado = max(Cerrado, Hijos[0].Valor_abierto + Pesos[{Nodo, Hijos[0]._ndice}]);
    else Cerrado = max(Cerrado, Hijos[0].Valor_abierto + Pesos[{Nodo, Hijos[0]._ndice}] + Hijos[1].Valor_abierto + Pesos[{Nodo, Hijos[1]._ndice}]);
    Memorizaci_n[Nodo] = {Abierto, Cerrado};
}
void Crear(long long i, long long d, long long p){
    if(i == d){
        _rbol_izquierdo[p] = Izquierdo[i];
        _rbol_derecho[p] = Derecho[i];
        return;
    }
    long long P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol_izquierdo[p] = max(_rbol_izquierdo[p * 2], _rbol_izquierdo[p * 2 + 1]);
    _rbol_derecho[p] = max(_rbol_derecho[p * 2], _rbol_derecho[p * 2 + 1]);
}
void Propagar(long long p){
    if(Propagar_izquierdo[p] != 0){
        if(p * 2 < Propagar_izquierdo.size()) Propagar_izquierdo[p * 2] += Propagar_izquierdo[p];
        if(p * 2 + 1 < Propagar_izquierdo.size()) Propagar_izquierdo[p * 2 + 1] += Propagar_izquierdo[p];
        _rbol_izquierdo[p] += Propagar_izquierdo[p];
        Propagar_izquierdo[p] = 0;
    }
    if(Propagar_derecho[p] != 0){
        if(p * 2 < Propagar_derecho.size()) Propagar_derecho[p * 2] += Propagar_derecho[p];
        if(p * 2 + 1 < Propagar_derecho.size()) Propagar_derecho[p * 2 + 1] += Propagar_derecho[p];
        _rbol_derecho[p] += Propagar_derecho[p];
        Propagar_derecho[p] = 0;
    }
    ////cerr<<"Propagado. "<<p<<"\n";
}
long long Consulta_izquierda(long long i, long long d, long long p, long long I, long long D){
    if(D < I) return 0;
    Propagar(p);
    if(i >= I and d <= D) return _rbol_izquierdo[p];
    if(i > D or d < I) return Menos;
    long long P = (i + d) / 2;
    return max(Consulta_izquierda(i, P, p * 2, I, D), Consulta_izquierda(P + 1, d, p * 2 + 1, I, D));
}
long long Consulta_derecha(long long i, long long d, long long p, long long I, long long D){
    if(D < I) return 0;
    Propagar(p);
    if(i >= I and d <= D) return _rbol_derecho[p];
    if(i > D or d < I) return Menos;
    long long P = (i + d) / 2;
    return max(Consulta_derecha(i, P, p * 2, I, D), Consulta_derecha(P + 1, d, p * 2 + 1, I, D));
}
void Actualizar_izquierdo(long long i, long long d, long long p, long long I, long long D, long long v){
    if(D < I) return;
    Propagar(p);
    if(i >= I and d <= D){
        _rbol_izquierdo[p] += v;
        if(i != d){
            Propagar_izquierdo[p * 2] += v;
            Propagar_izquierdo[p * 2 + 1] += v;
        }
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar_izquierdo(i, P, p * 2, I, D, v);
    Actualizar_izquierdo(P + 1, d, p * 2 + 1, I, D, v);
    _rbol_izquierdo[p] = max(_rbol_izquierdo[p * 2], _rbol_izquierdo[p * 2 + 1]);
}
void Actualizar_derecho(long long i, long long d, long long p, long long I, long long D, long long v){
    if(D < I) return;
    Propagar(p);
    if(i >= I and d <= D){
        _rbol_derecho[p] += v;
        if(i != d){
            Propagar_derecho[p * 2] += v;
            Propagar_derecho[p * 2 + 1] += v;
        }
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar_derecho(i, P, p * 2, I, D, v);
    Actualizar_derecho(P + 1, d, p * 2 + 1, I, D, v);
    _rbol_derecho[p] = max(_rbol_derecho[p * 2], _rbol_derecho[p * 2 + 1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    Grafo.assign(n, vector<Arista>());
    Visitados.assign(n, 0);
    Padres.assign(n, 0);
    Valor_de_los_nodos.assign(n, 0);
    Memorizaci_n.assign(n, {-2, -2});
    for(long long i = 0; i < n; i++){
        long long u, w;
        cin>>u>>w;
        u--;
        Arista A;
        A.Siguiente = u;
        A.Peso = w;
        Grafo[i].push_back(A);
        A.Siguiente = i;
        Grafo[u].push_back(A);
        Pesos[{i, u}] = max(w, Pesos[{i, u}]);
        Pesos[{u, i}] = max(w, Pesos[{u, i}]);
    }
    for(long long i = 0; i < n; i++){
        if(!Visitados[i]){
            DFS(i, -2);
            Nodos_que_hacen_los_ciclos.push_back({Ciclante, Inicio_del_ciclo});
            swap(Nodos_que_hacen_los_ciclos.back().first, Nodos_que_hacen_los_ciclos.back().second);
            //cerr<<"-> "<<Nodos_que_hacen_los_ciclos.back().first<<" "<<Nodos_que_hacen_los_ciclos.back().second<<"\n";
        }
    }
    //cerr<<"¿Aquí?\n";
    vector< vector<long long> > Ciclos;
    for(long long i = 0; i < Nodos_que_hacen_los_ciclos.size(); i++){
        //Guardar los ciclos.
        vector<long long> Ciclo;
        for(long long Actual = Nodos_que_hacen_los_ciclos[i].first; Actual != Nodos_que_hacen_los_ciclos[i].second; Actual = Padres[Actual]){
            Ciclo.push_back(Actual);
            No_pasar_por_aqu_.insert(Actual);
            //cerr<<Actual<<" ";
            ////cerr<<Actual<<"\n";
        }
        Ciclo.push_back(Nodos_que_hacen_los_ciclos[i].second);
        No_pasar_por_aqu_.insert(Nodos_que_hacen_los_ciclos[i].second);
        Ciclos.push_back(Ciclo);
        //cerr<<Nodos_que_hacen_los_ciclos[i].second<<"\n";
    }
    //cerr<<"Ciclado.\n";
    long long Respuesta_final = 0;
    Visitados.assign(n, 0);
    for(auto E: Ciclos){
        //Encontrar la mejor respuesta de cada ciclo.
        long long m = E.size(), Respuesta = 0;
        Izquierdo.assign(m, 0);
        Derecho.assign(m, 0);
        _rbol_izquierdo.assign(m * 4 + 2, 0);
        _rbol_derecho.assign(m * 4 + 2, 0);
        Propagar_izquierdo.assign(m * 4 + 2, 0);
        Propagar_derecho.assign(m * 4 + 2, 0);
        for(long long i = 0; i < m; i++){
            PD(E[i]);
            Respuesta = max(Respuesta, max(Memorizaci_n[E[i]].first, Memorizaci_n[E[i]].second));
            Izquierdo[i] = Memorizaci_n[E[i]].first;
            Derecho[i] = Memorizaci_n[E[i]].first;
            Valor_de_los_nodos[E[i]] = Memorizaci_n[E[i]].first;
            //cerr<<E[i] + 1<<" "<<Valor_de_los_nodos[E[i]]<<" Nodo dentro del árbol más lejano.\n";
        }
        //cerr<<"Dinámico.\n";
        long long Acumulada = 0;
        for(long long i = 1; i < m; i++){
            Acumulada += Pesos[{E[i], E[i - 1]}];
            Derecho[i] += Acumulada;
        }
        Derecho[0] += Acumulada + Pesos[{E[0], E[m - 1]}];
        long long Longitud_del_ciclo = 0;
        for(long long i = 0; i < m - 1; i++){
            Longitud_del_ciclo += Pesos[{E[i], E[i + 1]}];
            //cerr<<"De "<<E[i]<<" a "<<E[i + 1]<<" hay "<<Pesos[{E[i], E[i + 1]}]<<"\n";
        }
        Longitud_del_ciclo += Pesos[{E[0], E[m - 1]}];
        Acumulada = Pesos[{E[0], E[m - 1]}];
        //cerr<<"De "<<E[0]<<" a "<<E[m - 1]<<" hay "<<Pesos[{E[0], E[m - 1]}]<<"\n";
        for(long long i = m - 1; i > 0; i--){
            Izquierdo[i] += Acumulada;
            Acumulada += Pesos[{E[i], E[i - 1]}];
        }
        //cerr<<Longitud_del_ciclo<<" Longitud del ciclo.\n";
        Crear(0, m - 1, 1);
        //cerr<<"Creado.\n";
        for(long long i = 0; i < m; i++){
            long long Posible = max(Consulta_izquierda(0, m - 1, 1, 0, i - 1), Consulta_izquierda(0, m - 1, 1, i + 1, m - 1)) + Valor_de_los_nodos[E[i]];
            Respuesta = max(Respuesta, Posible);
            //cerr<<"Consulta izquierda.\n";
            Posible = max(Consulta_derecha(0, m - 1, 1, 0, i - 1), Consulta_derecha(0, m - 1, 1, i + 1, m - 1)) + Valor_de_los_nodos[E[i]];
            Respuesta = max(Respuesta, Posible);
            //cerr<<"Consulta derecha.\n";
            if(i == m - 1) continue;
            Actualizar_izquierdo(0, m - 1, 1, 0, m - 1, Pesos[{E[i], E[i + 1]}]);
            Actualizar_derecho(0, m - 1, 1, 0, m - 1, -Pesos[{E[i], E[i + 1]}]);
            long long Valor_izquierdo_del_siguiente = Consulta_izquierda(0, m - 1, 1, i + 1, i + 1), Valor_derecho_del_siguiente = Consulta_derecha(0, m - 1, 1, i + 1, i + 1);
            Actualizar_izquierdo(0, m - 1, 1, i + 1, i + 1, Valor_de_los_nodos[E[i + 1]] - Valor_izquierdo_del_siguiente);
            Actualizar_derecho(0, m - 1, 1, i + 1, i + 1, Longitud_del_ciclo - Valor_derecho_del_siguiente + Valor_de_los_nodos[E[i + 1]]);
            /*for(long long j = 0; j < m; j++){
                cerr<<Consulta_izquierda(0, m - 1, 1, j, j)<<" ";
            }
            cerr<<"\n";
            for(long long j = 0; j < m; j++){
                cerr<<Consulta_derecha(0, m - 1, 1, j, j)<<" ";
            }
            cerr<<"\n\n";*/
        }
        Respuesta_final += Respuesta;
    }
    cout<<Respuesta_final;
    return 0;
}
/*
15
2 2
1 1
4 4
3 3
7 2
8 2
6 4
5 1
7 5
9 7
9 6
6 8
12 9
13 11
13 10
Da: 51.
¿Debería dar 52?
*/