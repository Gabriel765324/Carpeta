#include "iostream"
#include "vector"
#include "deque"
#include "map"
using namespace std;
const int MayorN = 1e5 + 2;
const int MayorN4 = 4e5 + 22;
vector< pair<int, long long> > Grafo[MayorN] = {};
long long Pendiente[MayorN4] = {}, Arreglo[MayorN] = {}, _rbol[MayorN4] = {};
int ID[MayorN] = {}, Tama_o[MayorN] = {}, Mapeo[MayorN] = {}, Anteriores[MayorN] = {};
pair<int, int> Orden[MayorN] = {};
vector< deque<int> > Filas;
long long M_dulo = 1000000007;
int Identificar = 0, Tiempo = 0, n;
void Crear(int Nodo, int Anterior){
    Anteriores[Nodo] = Anterior;
    Orden[Nodo].first = Tiempo;
    Tiempo++;
    if(Grafo[Nodo].size() == 1 and Nodo != 0){
        Tama_o[Nodo] = 1;
        ID[Nodo] = Identificar;
        Filas.push_back({Nodo});
        Identificar++;
        Orden[Nodo].second = Tiempo;
        Tiempo++;
        return;
    }
    int m = 0, p = -2;
    for(auto E: Grafo[Nodo]){
        if(E.first != Anterior){
            Crear(E.first, Nodo);
            if(Tama_o[E.first] > m){
                m = Tama_o[E.first];
                p = E.first;
            }
        }
    }
    Orden[Nodo].second = Tiempo;
    Tiempo++;
    Tama_o[Nodo] = m + 1;
    ID[Nodo] = ID[p];
    Filas[ID[Nodo]].push_front(Nodo);
}
void Crear_(int i, int d, int p){
    if(i == d){
        _rbol[p] = Arreglo[i];
        return;
    }
    int P = (i + d) / 2;
    Crear_(i, P, p * 2);
    Crear_(P + 1, d, p * 2 + 1);
    _rbol[p] = (_rbol[p * 2] + _rbol[p * 2 + 1]) % M_dulo;
}
void Propagar(bool Seguir, int p){
    _rbol[p] = (_rbol[p] * Pendiente[p]) % M_dulo;
    if(Seguir){
        Pendiente[p * 2] = (Pendiente[p * 2] * Pendiente[p]) % M_dulo;
        Pendiente[p * 2 + 1] = (Pendiente[p * 2 + 1] * Pendiente[p]) % M_dulo;
    }
    Pendiente[p] = 1LL;
}
void Actualizar(int i, int d, int p, int I, int D, long long v){
    if(I > D) return;
    Propagar(i != d, p);
    if(i >= I and d <= D){
        Pendiente[p] = (Pendiente[p] * v) % M_dulo;
        Propagar(i != d, p);
        return;
    }
    if(i > D or d < I){
        return;
    }
    int P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D, v);
    Actualizar(P + 1, d, p * 2 + 1, I, D, v);
    _rbol[p] = (_rbol[p * 2] + _rbol[p * 2 + 1]) % M_dulo;
}
long long Consulta(int i, int d, int p, int I, int D){
    if(I > D) return 0LL;
    Propagar(i != d, p);
    if(i >= I and d <= D){
        return _rbol[p];
    }
    if(i > D or d < I){
        return 0LL;
    }
    int P = (i + d) / 2;
    return (Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D)) % M_dulo;
}
int main(){
    for(int i = 0; i < MayorN4; i++) Pendiente[i] = 1LL;
    int q;
    scanf("%d %d", &n, &q);
    int nn = n - 1;
    map< pair<int, int> , long long> Pesos;
    while(nn--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        Grafo[a].push_back({b, c});
        Grafo[b].push_back({a, c});
        Pesos[{a, b}] = c;
        Pesos[{b, a}] = c;
    }
    Crear(0, 0);
    int i = 0;
    for(auto E: Filas){
        Arreglo[i] = Pesos[{E[0], Anteriores[E[0]]}];
        Mapeo[E[0]] = i;
        i++;
        for(int j = 1; j < E.size(); j++){
            Arreglo[i] = Pesos[{E[j - 1], E[j]}];
            Mapeo[E[j]] = i;
            i++;
        }
    }
    Crear_(0, n - 1, 1);
    while(q--){
        int a, b;
        long long c;
        scanf("%d %d %lld", &a, &b, &c);
        a--;
        b--;
        long long Respuesta = 0LL;
        while(!(Orden[Filas[ID[a]][0]].first <= Orden[b].first and Orden[b].second <= Orden[Filas[ID[a]][0]].second)){
            Actualizar(0, n - 1, 1, Mapeo[Filas[ID[a]][0]], Mapeo[a], c);
            Respuesta = (Consulta(0, n - 1, 1, Mapeo[Filas[ID[a]][0]], Mapeo[a]) + Respuesta) % M_dulo;
            a = Anteriores[Filas[ID[a]][0]];
        }
        while(ID[b] != ID[a]){
            Actualizar(0, n - 1, 1, Mapeo[Filas[ID[b]][0]], Mapeo[b], c);
            Respuesta = (Consulta(0, n - 1, 1, Mapeo[Filas[ID[b]][0]], Mapeo[b]) + Respuesta) % M_dulo;;
            b = Anteriores[Filas[ID[b]][0]];
        }
        if(Mapeo[a] > Mapeo[b]) swap(a, b);
        Actualizar(0, n - 1, 1, Mapeo[a] + 1, Mapeo[b], c);
        Respuesta = (Respuesta + Consulta(0, n - 1, 1, Mapeo[a] + 1, Mapeo[b])) % M_dulo;
        printf("%lld\n", Respuesta);
    }
    return 0;
}