#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Grafo, Ganar;
vector<int> Ronda, Contador_de_victorias;
struct Fruta{
    int Menor, Posici_n;
    Fruta(){
        Menor = 22222222;
        Posici_n = 22222222;
    }
    Fruta(int m, int p){
        Menor = m;
        Posici_n = p;
    }
    Fruta operator+(const Fruta& a){
        if(Menor < a.Menor) return Fruta(Menor, Posici_n);
        return Fruta(a.Menor, a.Posici_n);
    }
};
vector<Fruta> _rbol;
vector<int> Distancias, Llegar, Primero, Nodo_correspondiente;
int Tiempo = 0;
void Crear(int i, int d, int p){
    if(i == d){
        _rbol[p] = Fruta(Distancias[i], Nodo_correspondiente[i]);
        return;
    }
    int P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
    _rbol[p] = _rbol[p * 2] + _rbol[p * 2 + 1];
}
Fruta Consulta(int i, int d, int p, int I, int D){
    if(i >= I and d <= D) return _rbol[p];
    if(i > D or d < I) return Fruta();
    int P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) + Consulta(P + 1, d, p * 2 + 1, I, D);
}
void DFS(int Nodo){
    Distancias[Tiempo] = Llegar[Nodo];
    Nodo_correspondiente[Tiempo] = Nodo;
    //cerr<<Distancias[Tiempo]<<" ";
    Primero[Nodo] = Tiempo;
    Tiempo++;
    for(auto E: Grafo[Nodo]){
        if(Llegar[E] > Llegar[Nodo] + 1){
            Llegar[E] = Llegar[Nodo] + 1;
            //cerr<<Nodo<<">>("<<E<<", "<<Llegar[E]<<")\n";
            DFS(E);
            Distancias[Tiempo] = Llegar[Nodo];
            Nodo_correspondiente[Tiempo] = Nodo;
            //cerr<<Distancias[Tiempo]<<" ";
            Tiempo++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, N;
    cin>>n>>q;
    N = (1<<(n + 1)) - 1;
    n = (1<<n);
    Ronda.assign(N, 0);
    Grafo.assign(N, {});
    Ganar.assign(n, vector<int>(n, -1));
    Contador_de_victorias.assign(n, 0);
    for(int i = 0; i < n; i++) Ronda[i] = 0;
    map<string, int> Mapa;
    int ID = 0;
    for(int i = 0; i < n - 1; i++){
        vector<string> Dato(4);
        cin>>Dato[0]>>Dato[1]>>Dato[2]>>Dato[2]>>Dato[3];
        if(Mapa.count(Dato[0]) == 0){
            Mapa[Dato[0]] = ID;
            ID++;
        }
        if(Mapa.count(Dato.back()) == 0){
            Mapa[Dato.back()] = ID;
            ID++;
        }
        //cerr<<Dato[0]<<" "<<Dato[1]<<" "<<Dato[2]<<" "<<Dato[3]<<"\n";
        stringstream Conversor, Conversor2;
        if(Dato[1].back() != ')'){
            int p0, p1;
            Conversor<<Dato[1];
            Conversor>>p0;
            Conversor2<<Dato[2];
            Conversor2>>p1;
            //cerr<<p0<<" "<<p1<<"\n";
            if(p0 < p1) swap(Dato[0], Dato.back());
            Ganar[Mapa[Dato[0]]][Mapa[Dato.back()]] = 1;
            Ganar[Mapa[Dato.back()]][Mapa[Dato[0]]] = 0;
            Contador_de_victorias[Mapa[Dato[0]]]++;
        } else {
            string _1 = "", _2 = "", _3 = "", _4 = "";
            bool Bien = 0;
            for(auto E: Dato[1]){
                if(E == ')') break;
                if(Bien) _1 += E;
                else if(E != '(') _3 += E;
                if(E == '(') Bien = 1;
            }
            Bien = 0;
            for(auto E: Dato[2]){
                if(E == ')') break;
                if(Bien) _2 += E;
                else if(E != '(') _4 += E;
                if(E == '(') Bien = 1;
            }
            if(_3 != _4){
                swap(_1, _3);
                swap(_2, _4);
            }
            int p0, p1;
            Conversor<<_1;
            Conversor>>p0;
            Conversor2<<_2;
            Conversor2>>p1;
            //cerr<<p0<<" "<<p1<<"\n";
            if(p0 < p1) swap(Dato[0], Dato.back());
            Ganar[Mapa[Dato[0]]][Mapa[Dato.back()]] = 1;
            Ganar[Mapa[Dato.back()]][Mapa[Dato[0]]] = 0;
            Contador_de_victorias[Mapa[Dato[0]]]++;
        }
    }
    /*for(auto E: Mapa){
        cerr<<E.first<<" "<<E.second<<"\n";
    }*/
    /*for(auto E: Ganar){
        for(auto e: E){
            cerr<<e<<" ";
        }
        cerr<<"\n";
    }*/
    int cn = n / 2, Perder = 0, Inicio = n, Nodo_inicial = 0;
    vector<int> Nodo_actual(n, 0);
    for(int i = 0; i < n; i++){
        Nodo_actual[i] = i;
    }
    while(cn > 0){
        vector<int> Perdedores;
        for(int i = 0; i < n; i++){
            if(Contador_de_victorias[i] == Perder){
                Perdedores.push_back(i);
            }
        }
        /*for(auto E: Perdedores) cerr<<E<<" ";
        cerr<<"\n";*/
        int Actual = 0;
        for(int _ndice = Inicio; _ndice < Inicio + cn; _ndice++){
            Ronda[_ndice] = Ronda[Inicio - 1] + 1;
            for(int Buscar = 0; Buscar < n; Buscar++){
                if(Ganar[Perdedores[Actual]][Buscar] == 0){
                    //cerr<<_ndice<<"<->"<<Nodo_actual[Perdedores[Actual]]<<"\n";
                    //cerr<<_ndice<<"<->"<<Nodo_actual[Buscar]<<"\n";
                    Grafo[_ndice].push_back(Nodo_actual[Perdedores[Actual]]);
                    Grafo[_ndice].push_back(Nodo_actual[Buscar]);
                    Grafo[Nodo_actual[Perdedores[Actual]]].push_back(_ndice);
                    Grafo[Nodo_actual[Buscar]].push_back(_ndice);
                    Nodo_actual[Buscar] = _ndice;
                    Nodo_inicial = _ndice;
                    break;
                }
            }
            Actual++;
        }
        Perder++;
        Inicio += cn;
        cn /= 2;
    }
    _rbol.assign(8 * N + 22, Fruta());
    Distancias.assign(2 * N, 22222222);
    Nodo_correspondiente.assign(2 * N, 22222222);
    Primero.assign(N, 0);
    Llegar.assign(N, 22222222);
    Llegar[Nodo_inicial] = 0;
    DFS(Nodo_inicial);
    //cerr<<"\n";
    Crear(0, 2 * N - 1, 1);
    /*for(auto E: _rbol) cerr<<E.Menor<<" ";
    cerr<<"\n";*/
    /*for(auto E: Ronda){
        cerr<<E<<" ";
    }
    cerr<<"\n";*/
    while(q--){
        string e0, e1;
        cin>>e0>>e1;
        int n0 = Mapa[e0], n1 = Mapa[e1], Distancia_entre_ellos = Llegar[n0] + Llegar[n1], Respuesta = 0;
        if(Primero[n0] > Primero[n1]) swap(n0, n1);
        Distancia_entre_ellos -= 2 * Consulta(0, 2 * N - 1, 1, Primero[n0], Primero[n1]).Menor;
        while(Distancia_entre_ellos > 1){
            Respuesta++;
            Distancia_entre_ellos /= 2;
        }
        cout<<Ronda[Consulta(0, 2 * N - 1, 1, Primero[n0], Primero[n1]).Posici_n]<<"\n";
        //cerr<<Consulta(0, 2 * N - 1, 1, Primero[n0], Primero[n1]).Posici_n<<"\n";
    }
    return 0;
}