#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo, Mesa;
vector<int> Tama_os, Respuestas, Capa, Mayor_componente;
struct A_adir{
    int Inicio, Final, Valor;
    bool Ahora;
};
vector< vector<A_adir> > Opciones;
bool V_lido(int Sub_rbol, int Candidato){
    int Mayor = max(Mayor_componente[Candidato], Tama_os[Sub_rbol] - Tama_os[Candidato]);
    return Mayor * 2 <= Tama_os[Sub_rbol];
}
int DFS0(int Nodo, int Anterior){
    if(Nodo != 0){
        Mesa[Nodo].push_back(Anterior);
        for(int i = 1; i < Mesa[Anterior].size(); i++){
            Mesa[Nodo].push_back(Mesa[Anterior][i]);
            Anterior = Mesa[Anterior][i];
        }
    }
    for(auto E: Grafo[Nodo]){
        Capa[E] = Capa[Nodo] + 1;
        Tama_os[Nodo] += DFS0(E, Nodo);
        Mayor_componente[Nodo] = max(Mayor_componente[Nodo], Tama_os[E]);
    }
    return Tama_os[Nodo];
}
void DFS1(int Nodo){
    for(auto E: Grafo[Nodo]) DFS1(E);
    A_adir Nuevo;
    int Tama_o_inicial = 2 * Mayor_componente[Nodo], Tama_n_final = 2 * Tama_os[Nodo];
    if(Tama_n_final < Tama_o_inicial) swap(Tama_o_inicial, Tama_o_inicial);
    Nuevo.Valor = Nodo + 1;
    Nuevo.Inicio = Nodo;
    Nuevo.Final = Nodo;
    Nuevo.Ahora = 0;
    bool Mal = 1;
    if(V_lido(Nodo, Nodo)){
        Nuevo.Ahora = 1;
        Mal = 0;
    } else {
        int Actual = Nodo;
        while(1){
            int i = 0, d = Mesa[Actual].size() - 1, m = Mesa[Actual].size();
            while(i < d + 1){
                int p = (i + d) / 2, Posible = Mesa[Actual][p];
                if(Tama_os[Posible] < Tama_o_inicial){
                    i = p + 1;
                    m = p;
                } else d = p - 1;
            }
            if(m == Mesa[Actual].size() or Mesa[Actual][m] == Actual) break;
            Actual = Mesa[Actual][m];
        }
        Nuevo.Inicio = Actual;
    }
    if(Nuevo.Inicio == 0){
        if(V_lido(0, Nodo)){
            Nuevo.Ahora = 1;
            Nuevo.Final = 0;
            Opciones[0].push_back(Nuevo);
        }
        return;
    }
    Nuevo.Final = Nuevo.Inicio;
    if(!Nuevo.Ahora) Nuevo.Final = Mesa[Nuevo.Inicio][1];
    int Actual = Nuevo.Final;
    while(1){
        int i = 0, d = Mesa[Actual].size() - 1, m = Mesa[Actual].size();
        while(i < d + 1){
            int p = (i + d) / 2, Posible = Mesa[Actual][p];
            if(V_lido(Posible, Nodo)){
                i = p + 1;
                m = p;
                Mal = 0;
            } else d = p - 1;
        }
        if(m == Mesa[Actual].size() or Mesa[Actual][m] == Actual) break;
        Actual = Mesa[Actual][m];
    }
    Nuevo.Final = Actual;
    if(Mal) return;
    Opciones[Nuevo.Inicio].push_back(Nuevo);
}
void DFS2(int Nodo, int Anterior){
    for(auto E: Grafo[Nodo]) DFS2(E, Nodo);
    A_adir Mejor;
    Mejor.Ahora = 1;
    Mejor.Inicio = -2;
    Mejor.Final = -2;
    Mejor.Valor = -2;
    for(auto E: Opciones[Nodo]){
        if(Mejor.Inicio == -2) Mejor = E;
        else if(Capa[E.Final] < Capa[Mejor.Final]) Mejor = E;
        if(E.Ahora or E.Inicio != Nodo) Respuestas[Nodo] = E.Valor;
    }
    Mejor.Inicio = Anterior;
    Mejor.Ahora = 1;
    if(Nodo != 0 and Mejor.Final != Nodo) Opciones[Anterior].push_back(Mejor);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Grafo.assign(n + 1, {});
    Mesa.assign(n + 1, {});
    Opciones.assign(n + 1, {});
    Tama_os.assign(n + 1, 1);
    Capa.assign(n + 1, 0);
    Respuestas.assign(n + 1, -2);
    Mayor_componente.assign(n + 1, 0);
    for(int i = 0; i < n; i++){
        Mesa[i].push_back(i);
        if(i == n - 1) break;
        int a;
        cin>>a;
        Grafo[a - 1].push_back(i + 1);
    }
    DFS0(0, -2);
    DFS1(0);
    DFS2(0, -2);
    while(m--){
        int a;
        cin>>a;
        cout<<Respuestas[a - 1]<<"\n";
    }
    return 0;
}