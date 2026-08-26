#include "bits/stdc++.h"
using namespace std;
int n, Tiempo = 0, Color = 0, Posici_n_para_el_arreglo = 0;
vector<int> Valores, a, _rbol, Posiciones, Cabezas, Color_de_la_cadena, Padres, Distancia, Jaja;
vector< pair<int, int> > Ordenar;
vector< vector<int> > Grafo;
void DFS(int Nodo, int Anterior){
    Padres[Nodo] = Anterior;
    Distancia[Nodo] = Distancia[Anterior] + 1;
    Ordenar[Nodo].first = Tiempo;
    Tiempo++;
    for(auto E: Grafo[Nodo]){
        if(E != Anterior) DFS(E, Nodo);
    }
    Ordenar[Nodo].second = Tiempo;
    Tiempo++;
}
int Sub_rbol(int Nodo){
    return (Ordenar[Nodo].second - Ordenar[Nodo].first) / 2 + 1;
}
void Descomposici_n_pesado_liviano(int Nodo, int Anterior){
    if(Cabezas[Color] == -2) Cabezas[Color] = Nodo;
    Color_de_la_cadena[Nodo] = Color;
    a[Posici_n_para_el_arreglo] = Valores[Nodo];
    //cout<<a[Posici_n_para_el_arreglo]<<"\n";
    Posiciones[Nodo] = Posici_n_para_el_arreglo;
    Posici_n_para_el_arreglo++;
    if(Sub_rbol(Nodo) == 1) return;
    int Peso = -2, Hijo = -2;
    for(auto E: Grafo[Nodo]){
        if(E != Anterior and Sub_rbol(E) > Peso){
            Peso = Sub_rbol(E);
            Hijo = E;
        }
    }
    Descomposici_n_pesado_liviano(Hijo, Nodo);
    for(auto E: Grafo[Nodo]){
        if(E != Anterior and E != Hijo){
            Color++;
            Descomposici_n_pesado_liviano(E, Nodo);
        }
    }
}
void Crear(int i, int d, int p){
    if(i == d){
        _rbol[p] = a[i];
        Jaja[i] = p;
        //cout<<_rbol[p]<<" "<<p<<" "<<a[i]<<"\n";
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol[p] = max(_rbol[p * 2], _rbol[p * 2 + 1]);
}
int Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return -2222222;
    int P = (i + d) / 2;
    return max(Consulta(i, P, p * 2, I, D), Consulta(P + 1, d, p * 2 + 1, I, D));
}
void Actualizar(int p, int o, int v){
    if(p == -0) return;
    if(p == o) _rbol[p] = v;
    else _rbol[p] = max(_rbol[p * 2], _rbol[p * 2 + 1]);
    Actualizar(p / 2, o, v);
}
int Cabeza(int Nodo){
    return Cabezas[Color_de_la_cadena[Nodo]];
}
int Consultar(int aa, int b){
    int Respuesta = -2222222;
    while(Cabeza(aa) != Cabeza(b)){
        //cout<<a<<" "<<b<<"\n";
        if(Distancia[Cabeza(aa)] < Distancia[Cabeza(b)]) swap(aa, b);
        Respuesta = max(Respuesta, Consulta(0, n - 1, 1, Posiciones[Cabeza(aa)], Posiciones[aa]));
        //cout<<Posiciones[aa]<<" "<<Posiciones[Cabeza(aa)]<<" "<<aa<<"\n";
        aa = Padres[Cabeza(aa)];
    }
    if(Distancia[aa] > Distancia[b]) swap(aa, b);
    Respuesta = max(Respuesta, Consulta(0, n - 1, 1, Posiciones[aa], Posiciones[b]));
    //cout<<Posiciones[aa]<<" "<<Posiciones[b]<<" "<<aa<<" "<<b<<"\n";
    return Respuesta;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>n>>q;
    Valores.assign(n, 0);
    a.assign(n, 0);
    _rbol.assign(n * 4 + 22, 0);
    Posiciones.assign(n, 0);
    Cabezas.assign(n, -2);
    Color_de_la_cadena.assign(n, 0);
    Padres.assign(n, 0);
    Distancia.assign(n, -1);
    Ordenar.assign(n, {-2, -2});
    Jaja.assign(n, -0);
    Grafo.assign(n, {});
    for(int i = 0; i < n; i++) cin>>Valores[i];
    int cn = n - 1;
    while(cn--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    DFS(0, 0);
    Descomposici_n_pesado_liviano(0, 0);
    Crear(0, n - 1, 1);
    /*for(auto E: Color_de_la_cadena) cout<<E<<" ";
    cout<<"\n";
    for(auto E: a) cout<<E<<" ";
    cout<<"\n";
    //cout<<Posiciones[Cabeza(5)] <<"   aaa\n";
    for(int i = 0; i < n; i++) cout<<Consulta(0, n - 1, 1, i, i)<<" ";
    cout<<"\n";
    */
    while(q--){
        int t, a, b;
        cin>>t>>a>>b;
        a--;
        b--;
        if(t == 2) cout<<Consultar(a, b)<<" ";
        else {
            Actualizar(Jaja[Posiciones[a]], Jaja[Posiciones[a]], b + 1);
            /*for(int i = 0; i < n; i++) cout<<Consulta(0, n - 1, 1, i, i)<<" ";
            cout<<"\n";*/
        }
    }
    return 0;
}
/*
12 222
1 2 3 4 5 6 7 8 9 10 11 12
1 3    
1 2
1 10
3 5
4 3
8 3
2 6
2 7
9 2
10 11
12 10
*/