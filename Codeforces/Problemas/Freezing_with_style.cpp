#include "iostream"
#include "vector"
#include "bitset"
#include "algorithm"
#include "deque"
#include "queue"
using namespace std;
int n, l, r, MejorU, MejorV;
struct Arista{
    int v, p;
    Arista(int V, int P){
        v = V;
        p = P;
    }
};
struct Opci_n{
    int Nodo, Capa, Valor;
    Opci_n(){}
    Opci_n(int N, int C, int V){
        Nodo = N;
        Capa = C;
        Valor = V;
    }
};
struct Nodo_siguiente{
    int Nodo, Padre;
    Nodo_siguiente(){}
    Nodo_siguiente(int N, int P){
        Nodo = N;
        Padre = P;
    }
};
struct Mejorcito{
    int Costo, Nodo;
    Mejorcito(){}
    Mejorcito(int C, int N){
        Costo = C;
        Nodo = N;
    }
    bool operator<(const Mejorcito& o) const{
        return make_pair(Costo, Nodo) < make_pair(o.Costo, o.Nodo);
    }
};
const int MAYOR = 100000;
vector<Arista> Grafo[MAYOR] = {}, Grafo_alterno[MAYOR] = {};
int Profundidades[MAYOR] = {}, Costos[MAYOR] = {}, Tama_os[MAYOR] = {};
bitset<100000> Visitados;
void BFS(int Nodo){
    queue<Nodo_siguiente> Cola;
    Cola.push(Nodo_siguiente(Nodo, Nodo));
    vector<int> Nodos, Padres;
    while(!Cola.empty()){
        Nodo_siguiente Actual = Cola.front();
        Nodos.push_back(Actual.Nodo);
        Padres.push_back(Actual.Padre);
        Tama_os[Actual.Nodo] = 1;
        Cola.pop();
        for(auto E: Grafo_alterno[Actual.Nodo]){
            if(Visitados[E.v] or E.v == Actual.Padre) continue;
            Cola.push(Nodo_siguiente(E.v, Actual.Nodo));
        }
    }
    for(int i = int(Nodos.size()) - 1; i > -1; i--){
        int Nodito = Nodos[i];
        for(auto E: Grafo_alterno[Nodito]){
            if(E.v == Padres[i] or Visitados[E.v]) continue;
            Tama_os[Nodito] += Tama_os[E.v];
        }
    }
}
int Centroide(int Nodo, int Padre, int Tama_o){
    while(1){
        bool Encontrado = 1;
        for(auto E: Grafo_alterno[Nodo]){
            if(E.v == Padre or Visitados[E.v]) continue;
            if((Tama_os[E.v]<<1) > Tama_o){
                Encontrado = 0;
                Padre = Nodo;
                Nodo = E.v;
                break;
            }
        }
        if(Encontrado) return Nodo;
    }
}
bool Bien = 0;
void Descomposici_n(int Nodo){
    Tama_os[Nodo] = 0;
    BFS(Nodo);
    if(Tama_os[Nodo] == 1){
        Visitados[Nodo] = 1;
        return;
    }
    int Centroide_del_nodo = Centroide(Nodo, Nodo, Tama_os[Nodo]);
    Visitados[Centroide_del_nodo] = 1;
    deque<Opci_n> Obtener_mejor;
    vector<Mejorcito> Mejores(1, Mejorcito(0, Centroide_del_nodo));
    Profundidades[Centroide_del_nodo] = 0;
    Costos[Centroide_del_nodo] = 0;
    //int Puntero = 0;
    //cerr<<"\n"<<Centroide_del_nodo + 1<<"....\n";
    for(auto E: Grafo_alterno[Centroide_del_nodo]){
        if(Visitados[E.v]) continue;
        vector<Mejorcito> Mejores_actual;
        vector<int> Lista_de_nodos;
        queue<Nodo_siguiente> Cola;
        Costos[E.v] = E.p;
        Profundidades[E.v] = 1;
        Cola.push(Nodo_siguiente(E.v, Centroide_del_nodo));
        Lista_de_nodos.push_back(E.v);
        while(!Cola.empty()){
            Nodo_siguiente Actual = Cola.front();
            Cola.pop();
            while(Profundidades[Actual.Nodo] >= int(Mejores_actual.size())) Mejores_actual.push_back(Mejorcito(INT_MIN + 222222, INT_MIN + 222222));
            Mejores_actual[Profundidades[Actual.Nodo]] = max(Mejores_actual[Profundidades[Actual.Nodo]], Mejorcito(Costos[Actual.Nodo], Actual.Nodo));
            for(auto e: Grafo_alterno[Actual.Nodo]){
                if(e.v == Actual.Padre or Visitados[e.v]) continue;
                Lista_de_nodos.push_back(e.v);
                //cerr<<e.v + 1<<".\n";
                Profundidades[e.v] = Profundidades[Actual.Nodo] + 1;
                //Puntero = max(Puntero, Profundidades[e.v]);
                Costos[e.v] = Costos[Actual.Nodo] + e.p;
                Cola.push(Nodo_siguiente(e.v, Actual.Nodo));
            }
            //cerr<<Actual.Nodo + 1<<" "<<Profundidades[Actual.Nodo]<<".\n";
            /*for(auto e: Obtener_mejor){
                cerr<<e.Valor<<" ";
            }*/
            //cerr<<"\n";
            /*for(auto e: Obtener_mejor){
                cerr<<e.Capa<<" ";
            }*/
            //cerr<<"\n\n";
        }
        int Puntero_mejores = 0;
        for(int Puntero = int(Mejores_actual.size()) - 1; Puntero > 0; Puntero--){
            for(; Puntero_mejores <= r - Puntero and Puntero_mejores < int(Mejores.size()); Puntero_mejores++){
                while(!Obtener_mejor.empty() and Mejores[Puntero_mejores].Costo >= Obtener_mejor[0].Valor) Obtener_mejor.pop_front();
                Obtener_mejor.push_front(Opci_n(Mejores[Puntero_mejores].Nodo, Puntero_mejores, Mejores[Puntero_mejores].Costo));
                while(!Obtener_mejor.empty() and Obtener_mejor.back().Capa < l - Puntero) Obtener_mejor.pop_back();
            }
            while(!Obtener_mejor.empty() and Obtener_mejor.back().Capa < l - Puntero) Obtener_mejor.pop_back();
            /*cerr<<Mejores_actual[Puntero].Nodo + 1<<" "<<Mejores_actual[Puntero].Costo<<" "<<Puntero<<"..\n";
            for(auto E: Obtener_mejor) cerr<<E.Nodo + 1<<" ";
            cerr<<"\n";
            for(auto E: Obtener_mejor) cerr<<E.Capa<<" ";
            cerr<<"\n";
            for(auto E: Obtener_mejor) cerr<<E.Valor<<" ";
            cerr<<"\n";*/
            if(!Obtener_mejor.empty() and Obtener_mejor.back().Valor + Mejores_actual[Puntero].Costo >= 0){
                Bien = 1;
                MejorU = Mejores_actual[Puntero].Nodo;
                MejorV = Obtener_mejor.back().Nodo;
                return;
            }
        }
        for(int i = 0; i < int(Mejores_actual.size()); i++){
            if(i >= int(Mejores.size())){
                Mejores.push_back(Mejores_actual[i]);
                continue;
            }
            Mejores[i] = max(Mejores[i], Mejores_actual[i]);
        }
        //cerr<<"---------------\n";
    }
    for(auto E: Grafo_alterno[Centroide_del_nodo]){
        if(Visitados[E.v]) continue;
        Descomposici_n(E.v);
        if(Bien) return;
    }
}
bool Resolver(){
    Bien = 0;
    Descomposici_n(0);
    //cerr<<"\n";
    return Bien;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>l>>r;
    int m = n - 1, a, b, c;
    vector<int> Valores(n);
    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        a--;
        b--;
        Grafo[a].push_back(Arista(b, c));
        Grafo[b].push_back(Arista(a, c));
        Grafo_alterno[a].push_back(Arista(b, 0));
        Grafo_alterno[b].push_back(Arista(a, 0));
        Valores.push_back(c);
    }
    sort(Valores.begin(), Valores.end());
    Valores.erase(unique(Valores.begin(), Valores.end()), Valores.end());
    m = int(Valores.size());
    int i = 0, d = m - 1;
    while(i < d + 1){
        Visitados ^= Visitados;
        int p = (i + d)>>1;
        //cerr<<"Valor: "<<Valores[p]<<".\n";
        for(int I = 0; I < n; I++){
            for(int J = 0; J < int(Grafo[I].size()); J++){
                Grafo_alterno[I][J].p = (Grafo[I][J].p >= Valores[p]) ? 1 : -1;
            }
        }
        if(Resolver()){
            //cerr<<"Bien.\n";
            i = p + 1;
        } else {
            //cerr<<"Mal.\n";
            d = p - 1;
        }
    }
    cout<<MejorU + 1<<" "<<MejorV + 1;
    return 0;
}