#include "bits/stdc++.h"
using namespace std;
vector<int> Valores, _rbol, a, Profundidad, Posici_n, Anterior, Cabeza_de_la_cadena, Cadena_a_la_que_corresponde, Tiempo_de_llegada, Tiempo_de_salida;
vector< vector<int> > Grafo;
int Tiempo = 0, Color_de_cadena = 0, Lugar_en_el_arreglo = 0, n;
void DFS(int Nodo, int Padre){
    Anterior[Nodo] = Padre;
    Profundidad[Nodo] = Profundidad[Padre] + 1;
    Tiempo_de_llegada[Nodo] = Tiempo;
    Tiempo++;
    for(auto E: Grafo[Nodo]) if(E != Padre) DFS(E, Nodo);
    Tiempo_de_salida[Nodo] = Tiempo;
    Tiempo++;
}
int Tama_no_de_sub_rbol(int Nodo){
    return (Tiempo_de_salida[Nodo] - Tiempo_de_llegada[Nodo]) / 2 + 1;
}
void HLD(int Nodo, int Anterior){
    Posici_n[Nodo] = Lugar_en_el_arreglo;
    a[Lugar_en_el_arreglo] = Valores[Nodo];
    Lugar_en_el_arreglo++;
    if(Cabeza_de_la_cadena[Color_de_cadena] == -2) Cabeza_de_la_cadena[Color_de_cadena] = Nodo;
    Cadena_a_la_que_corresponde[Nodo] = Color_de_cadena;
    if(Tama_no_de_sub_rbol(Nodo) == 1) return;
    int Hijo_pesado = -2, Peso = -2;
    for(auto E: Grafo[Nodo]){
        if(Tama_no_de_sub_rbol(E) > Peso and E != Anterior){
            Peso = Tama_no_de_sub_rbol(E);
            Hijo_pesado = E;
        }
    }
    //cout<<Hijo_pesado<<" "<<Nodo<<"\n";
    HLD(Hijo_pesado, Nodo);
    for(auto E: Grafo[Nodo]){
        if(E != Anterior and E != Hijo_pesado){
            Color_de_cadena++;
            HLD(E, Nodo);
        }
    }
}
void Crear(int i, int d, int p){
    if(i == d){
        _rbol[p] = a[i];
        return;
    }
    int P = ((i + d)>>1);
    Crear(i, P, (p<<1));
    Crear(P + 1, d, (p<<1) + 1);
    _rbol[p] = max(_rbol[(p<<1)], _rbol[(p<<1) + 1]);
}
int Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return -2222;
    int P = ((i + d)>>1);
    return max(Consulta(i, P, (p<<1), I, D), Consulta(P + 1, d, (p<<1) + 1, I, D));
}
void Actualizar(int i, int d, int p, int v, int I){
    if(i > I or d < I) return;
    if(i == I and d == I){
        _rbol[p] = v;
        //cout<<v<<" "<<I<<" A\n";
        return;
    }
    int P = ((i + d)>>1);
    Actualizar(i, P, (p<<1), v, I);
    Actualizar(P + 1, d, (p<<1) + 1, v, I);
    _rbol[p] = max(_rbol[(p<<1)], _rbol[(p<<1) + 1]);
}
int Cabeza(int Nodo){
    return Cabeza_de_la_cadena[Cadena_a_la_que_corresponde[Nodo]];
}
int Consultar(int a, int b){
    //cout<<a<<" "<<b<<" c\n";
    int Respuesta = -2222;
    while(Cabeza(a) != Cabeza(b)){
        if(Profundidad[Cabeza(a)] < Profundidad[Cabeza(b)]) swap(a, b);
        Respuesta = max(Respuesta, Consulta(0, n - 1, 1, Posici_n[Cabeza(a)], Posici_n[a]));
        a = Anterior[Cabeza(a)];
    }
    if(Profundidad[a] < Profundidad[b]) swap(a, b);
    Respuesta = max(Consulta(0, n - 1, 1, Posici_n[b], Posici_n[a]), Respuesta);
    return Respuesta;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>n>>q;
    _rbol.assign(n * 4, -2);
    a.assign(n, 0);
    Valores.assign(n, 0);
    Profundidad.assign(n, -1);
    Posici_n.assign(n, 0);
    Anterior.assign(n, -2);
    Cabeza_de_la_cadena.assign(n, -2);
    Cadena_a_la_que_corresponde.assign(n, -2);
    Grafo.assign(n, {});
    Tiempo_de_llegada.assign(n, 0);
    Tiempo_de_salida.assign(n, 0);
    int cn = n - 1;
    for(int i = 0; i < n; i++) cin>>Valores[i];
    while(cn--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    DFS(0, 0);
    HLD(0, -2);
    Crear(0, n - 1, 1);
    /*for(auto E: Cadena_a_la_que_corresponde) cout<<E<<" ";
    cout<<"\n";
    for(auto E: a) cout<<E<<" ";
    cout<<"\n";
    for(auto E: Posici_n) cout<<E<<" ";
    cout<<"\n";
    for(int i = 0; i < n; i++){
        cout<<Consulta(0, n - 1, 1, i, i)<<" ";
    }
    cout<<"\n";*/
    while(q--){
        int t, a, b;
        cin>>t>>a>>b;
        a--;
        b--;
        //cout<<t<<" "<<a<<" "<<b<<" Hola.\n";
        if(t == 2) cout<<Consultar(a, b)<<" ";
        else Actualizar(0, n - 1, 1, b + 1, Posici_n[a]);
    }
    return 0;
}