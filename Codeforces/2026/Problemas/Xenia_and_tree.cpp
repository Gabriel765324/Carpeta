#include "bits/stdc++.h"
using namespace std;
vector<int> Representantes, Distancias, _rbol, Primeros, Tama_os_sub_rboles, Tama_os_componentes, Capa, Grafo_descompuesto;
vector< vector<int> > Grafo;
vector< pair<int, int> > Respuestas;
bitset<222222> Visitados, Centrados, Nada;
int Centroides = 0, n, m, t = 0;
int Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return 22222222;
    int P = (i + d) / 2;
    return min(Consulta(i, P, p * 2, I, D), Consulta(P + 1, d, p * 2 + 1, I, D));
}
void Actualizar(int i, int d, int p, int c, int v){
    if(i == d and d == c){
        _rbol[p] = v;
        return;
    }
    if(i > c or d < c) return;
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, c, v);
    Actualizar(P + 1, d, p * 2 + 1, c, v);
    _rbol[p] = min(_rbol[p * 2], _rbol[p * 2 + 1]);
}
void Calcular_distancias(int Nodo, int d){
    Distancias[Nodo] = d;
    Actualizar(0, 2 * n - 1, 1, t, d);
    Primeros[Nodo] = t;
    t++;
    d++;
    for(auto E: Grafo[Nodo]){
        if(Distancias[E] > d){
            Calcular_distancias(E, d);
            Actualizar(0, 2 * n - 1, 1, t, d - 1);
            t++;
        }
    }
}
int Buscar(int a){
    if(Representantes[a] == a) return a;
    int r = Buscar(Representantes[a]);
    Tama_os_componentes[a] = Tama_os_componentes[r];
    return Representantes[a] = r;
}
void Unir(int a, int b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        if(Tama_os_componentes[a] < Tama_os_componentes[b]) swap(a, b);
        Tama_os_componentes[a] += Tama_os_componentes[b];
        Representantes[b] = a;
    }
}
void Calcular_tama_os(int Nodo, int& M_s_bajo, int& Candidato){
    Visitados[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(!Visitados[E] and !Centrados[E]){
            Calcular_tama_os(E, M_s_bajo, Candidato);
            Tama_os_sub_rboles[Nodo] += Tama_os_sub_rboles[E];
            Unir(Nodo, E);
        }
        if(Centrados[E] and Capa[E] > M_s_bajo){
            M_s_bajo = Capa[E];
            Candidato = E;
        }
    }
}
int Buscar_centroide(int Nodo, int Anterior){
    bool Bien = Tama_os_componentes[Buscar(Anterior)] - Tama_os_sub_rboles[Nodo] <= Tama_os_componentes[Buscar(Anterior)] / 2;
    int Siguiente = -2, Tama_o_siguiente = -2;
    for(auto E: Grafo[Nodo]){
        if(E != Anterior and !Centrados[E]){
            Bien = Bien and Tama_os_sub_rboles[E] <= Tama_os_componentes[Buscar(Anterior)] / 2;
            if(Tama_os_sub_rboles[E] > Tama_o_siguiente){
                Siguiente = E;
                Tama_o_siguiente = Tama_os_sub_rboles[E];
            }
        }
    }
    if(Bien) return Nodo;
    else return Buscar_centroide(Siguiente, Nodo);
}
int Hallar_distancia(int a, int b){
    if(Primeros[a] > Primeros[b]) swap(a, b);
    return Distancias[a] + Distancias[b] - 2 * Consulta(0, 2 * n - 1, 1, Primeros[a], Primeros[b]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    Distancias.assign(n, 222222);
    Grafo.assign(n, {});
    _rbol.assign(n * 8 + 22, 0);
    Primeros.assign(n, 0);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    Calcular_distancias(0, 0);
    /*for(auto E: Distancias) cerr<<E<<" ";
    cerr<<"\n";
    for(int i = 0; i < n * 2; i++) cerr<<Consulta(0, 2 * n - 1, 1, i, i)<<" ";
    cerr<<"\n";*/
    Representantes.assign(n, 0);
    Tama_os_sub_rboles.assign(n, 0);
    Tama_os_componentes.assign(n, 1);
    Grafo_descompuesto.assign(n, -2);
    Capa.assign(n, -222222);
    while(Centroides < n){
        for(int i = 0; i < n; i++){
            Representantes[i] = i;
            Tama_os_sub_rboles[i] = 1;
            Tama_os_componentes[i] = 1;
        }
        Visitados &= Nada;
        for(int i = 0; i < n; i++){
            if(!Visitados[i] and !Centrados[i]){
                int Bajito = -2, Candidato = -2;
                Calcular_tama_os(i, Bajito, Candidato);
                int Centroide_actual = Buscar_centroide(i, i);
                if(Centroides == 0){
                    Capa[Centroide_actual] = 0;
                    Centrados[Centroide_actual] = 1;
                    Centroides++;
                    break;
                } else {
                    Capa[Centroide_actual] = Bajito + 1;
                    Grafo_descompuesto[Centroide_actual] = Candidato;
                }
                Centrados[Centroide_actual] = 1;
                Centroides++;
            }
        }
    }
    int Actualizable = 0;
    Respuestas.assign(n, {-2, -2});
    while(Actualizable != -2){
        int Distancia_hasta_el_rojo = Hallar_distancia(Actualizable, 0);
        if(Respuestas[Actualizable] == make_pair(-2, -2)){
            Respuestas[Actualizable] = {Distancia_hasta_el_rojo, 0};
        } else if(Distancia_hasta_el_rojo < Respuestas[Actualizable].first){
            Respuestas[Actualizable] = {Distancia_hasta_el_rojo, 0};
        }
        Actualizable = Grafo_descompuesto[Actualizable];
    }
    /*for(auto E: Grafo_descompuesto){
        cerr<<E + 1<<" ";
    }
    cerr<<"\n";*/
    while(m--){
        int Tipo, Copia;
        cin>>Tipo>>Actualizable;
        Actualizable--;
        Copia = Actualizable;
        if(Tipo == 1){
            while(Actualizable != -2){
                int Distancia_hasta_el_rojo = Hallar_distancia(Actualizable, Copia);
                if(Respuestas[Actualizable] == make_pair(-2, -2)){
                    Respuestas[Actualizable] = {Distancia_hasta_el_rojo, Copia};
                } else if(Distancia_hasta_el_rojo < Respuestas[Actualizable].first){
                    Respuestas[Actualizable] = {Distancia_hasta_el_rojo, Copia};
                }
                Actualizable = Grafo_descompuesto[Actualizable];
            }
        } else {
            int Respuesta_a_la_consulta = 222222;
            while(Actualizable != -2){
                if(Respuestas[Actualizable] != make_pair(-2, -2)){
                    Respuesta_a_la_consulta = min(Respuesta_a_la_consulta, Hallar_distancia(Respuestas[Actualizable].second, Copia));
                }
                //cerr<<Respuesta_a_la_consulta<<" "<<Copia + 1<<" "<<Respuestas[Actualizable].second + 1<<" "<<Actualizable + 1<<"\n";
                Actualizable = Grafo_descompuesto[Actualizable];
            }
            cout<<Respuesta_a_la_consulta<<"\n";
        }
        /*for(auto E: Respuestas) cerr<<E.first<<" "<<E.second + 1<<"\n";
        cerr<<"\n";*/
    }
    return 0;
}