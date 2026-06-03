#include "bits/stdc++.h"
using namespace std;
struct Arista{
    int u;
    long long p;
    Arista(int U, long long P){
        u = U;
        p = P;
    }
};
struct Valor{
    int Siguiente, Origen_del_mejor;
    long long Mejor;
    Valor(int s, int o, long long m){
        Siguiente = s;
        Origen_del_mejor = o;
        Mejor = m;
    }
};
vector<int> Padres, Llegada, Salida, Primera_aparici_n, Primero_que_lleg_;
vector<long long> Distancia_al_padre, Hijos_cercanos, Distancias_desde_el_origen, Arreglo_segmenteable, _rbol;
vector< vector<Arista> > Grafo;
vector< vector<Valor> > Levantar;
int Tiempo = 0, ta;
void Obtener_padres(int Nodo, int Padre){
    Llegada[Nodo] = Tiempo;
    Tiempo++;
    Primera_aparici_n[Nodo] = int(Arreglo_segmenteable.size());
    Arreglo_segmenteable.push_back(Distancias_desde_el_origen[Nodo]);
    for(auto E: Grafo[Nodo]){
        if(E.u == Padre) continue;
        Padres[E.u] = Nodo;
        Distancia_al_padre[E.u] = E.p;
        Distancias_desde_el_origen[E.u] = Distancias_desde_el_origen[Nodo] + E.p;
        Obtener_padres(E.u, Nodo);
        Arreglo_segmenteable.push_back(Distancias_desde_el_origen[Nodo]);
    }
    Salida[Nodo] = Tiempo;
    Tiempo++;
}
int Tama_ear(int i, int d){
    return 2 * (d - i + 1);
}
void Crear(int i, int d, int p){
    if(i == d){
        _rbol[p] = Arreglo_segmenteable[i];
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p + 1);
    Crear(P + 1, d, p + Tama_ear(i, P));
    _rbol[p] = min(_rbol[p + 1], _rbol[p + Tama_ear(i, P)]);
}
long long Consulta(int i, int d, int p, int I, int D){
    if(D < I) swap(I, D);
    if(I <= i and d <= D) return _rbol[p];
    if(D < i or d < I) return 2222222222222222;
    int P = (i + d) / 2;
    return min(Consulta(i, P, p + 1, I, D), Consulta(P + 1, d, p + Tama_ear(i, P), I, D));
}
bool Contiene(int a, int b){
    return Llegada[a] <= Llegada[b] and Salida[b] <= Salida[a];
}
long long Obtener_distancia(int a, int b){
    //cerr<<a<<" "<<b<<" Consulta.\n";
    if(a < 0 or b < 0) return 2222222222222222;
    //cerr<<"Sigo.\n";
    return Distancias_desde_el_origen[a] + Distancias_desde_el_origen[b] - 2LL * Consulta(0, ta - 1, 0, Primera_aparici_n[a], Primera_aparici_n[b]);
}
void Preprocesar(int Nodo, int Padre){
    if(Padre != -2){
        int Ancestro = Padres[Nodo], Origen_del_mejor = Primero_que_lleg_[Nodo];
        long long Respuesta = Hijos_cercanos[Nodo], Posible = Obtener_distancia(Nodo, Primero_que_lleg_[Ancestro]);
        if(Posible < Respuesta){
            Respuesta = Posible;
            Origen_del_mejor = Primero_que_lleg_[Ancestro];
        }
        Levantar[Nodo].push_back(Valor(Ancestro, Origen_del_mejor, Respuesta));
        for(int i = 0; i < int(Levantar[Ancestro].size()); i++){
            Posible = Obtener_distancia(Levantar[Ancestro][i].Origen_del_mejor, Nodo);
            if(Posible < Respuesta){
                Respuesta = Posible;
                Origen_del_mejor = Levantar[Ancestro][i].Origen_del_mejor;
            }
            Ancestro = Levantar[Ancestro][i].Siguiente;
            Levantar[Nodo].push_back(Valor(Ancestro, Origen_del_mejor, Respuesta));
        }
    }
    for(auto E: Grafo[Nodo]){
        if(E.u == Padre) continue;
        Preprocesar(E.u, Nodo);
    }
}
long long Consulta(int Nodo, int Tope){
    long long Respuesta = Hijos_cercanos[Nodo];
    int Desde = Nodo;
    if(Nodo == Tope) return Respuesta;
    while(!Contiene(Padres[Nodo], Tope)){
        //cerr<<Nodo<<"\n";
        int n = int(Levantar[Nodo].size()), i = 0, d = n - 1, m = n;
        while(i < d + 1){
            int p = (i + d) / 2, Elegido = Levantar[Nodo][p].Siguiente;
            //cerr<<p<<" ";
            if(Contiene(Elegido, Tope)){
                d = p - 1;
            } else {
                i = p + 1;
                m = p;
            }
        }
        //cerr<<"\nFin.\n";
        Respuesta = min(Respuesta, Obtener_distancia(Levantar[Nodo][m].Origen_del_mejor, Desde));
        //cerr<<"Distanciado.\n";
        Nodo = Levantar[Nodo][m].Siguiente;
        //cerr<<"Elegido.\n";
    }
    return min(Respuesta, Obtener_distancia(Levantar[Nodo][0].Origen_del_mejor, Desde));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, q, e;
    cin>>n>>s>>q>>e;
    Grafo.assign(n, {});
    Padres.assign(n, -2);
    Llegada.assign(n, 0);
    Salida.assign(n, 0);
    Hijos_cercanos.assign(n, 2222222222222222);
    Distancia_al_padre.assign(n, -2);
    Levantar.assign(n, {});
    Distancias_desde_el_origen.assign(n, 0);
    Primera_aparici_n.assign(n, 0);
    Primero_que_lleg_.assign(n, -2);
    vector< pair<int, int> > Aristas(n - 1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        long long c;
        cin>>a>>b>>c;
        a--;
        b--;
        Aristas[i] = {a, b};
        Grafo[a].push_back(Arista(b, c));
        Grafo[b].push_back(Arista(a, c));
    }
    e--;
    Obtener_padres(e, -2);
    ta = int(Arreglo_segmenteable.size());
    _rbol.assign(2 * ta + 22, 0);
    Crear(0, ta - 1, 0);
    set< pair<long long, pair<int, int> > > Cola;
    while(s--){
        int a;
        cin>>a;
        a--;
        Cola.insert(make_pair(0LL, make_pair(a, a)));
        Hijos_cercanos[a] = 0;
    }
    while(!Cola.empty()){
        int Nodo = Cola.begin()->second.first, Origen_del_camino = Cola.begin()->second.second;
        long long Distancia = Cola.begin()->first;
        Cola.erase(Cola.begin());
        if(Hijos_cercanos[Nodo] < Distancia or Nodo == e) continue;
        Primero_que_lleg_[Nodo] = Origen_del_camino;
        int Siguiente = Padres[Nodo];
        long long Nueva_distancia = Distancia_al_padre[Nodo] + Distancia;
        if(Hijos_cercanos[Siguiente] > Nueva_distancia){
            Hijos_cercanos[Siguiente] = Nueva_distancia;
            Cola.insert(make_pair(Nueva_distancia, make_pair(Siguiente, Origen_del_camino)));
        }
    }
    Preprocesar(e, -2);
    /*for(auto E: Llegada) cerr<<E<<" ";
    cerr<<"\n";
    for(auto E: Salida) cerr<<E<<" ";
    cerr<<"\n";
    for(auto E: Primero_que_lleg_) cerr<<E + 1<<" ";
    cerr<<"\n";*/
    while(q--){
        int i, Nodo, Bajo;
        cin>>i>>Nodo;
        i--;
        Nodo--;
        if(Padres[Aristas[i].first] == Aristas[i].second) Bajo = Aristas[i].first;
        else Bajo = Aristas[i].second;
        //cerr<<Bajo + 1<<" "<<Nodo + 1<<" v.\n";
        if(!Contiene(Bajo, Nodo)){
            cout<<"escaped\n";
            continue;
        }
        long long Respuesta = Consulta(Nodo, Bajo);
        if(Respuesta >= 2222222222222222) cout<<"oo\n";
        else cout<<Respuesta<<"\n";
    }
    return 0;
}