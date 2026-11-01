#include "bits/stdc++.h"
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define mp make_pair
#define ii piar<int, int>
#define F first
#define S second
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
struct Consulta{
    int t, n;
    Consulta(){}
    Consulta(int T, int N){
        t = T;
        n = N;
    }
};
struct Nodo2{
    int Propagar, Nodo_verdadero;
    bool Limpiar, Color;
    Nodo2(){}
    Nodo2(int p, int n, bool l){
        Propagar = p;
        Nodo_verdadero = n;
        Limpiar = l;
        Color = 0;
    }
};
struct Arista2{
    int v, p, Lleno;
    Arista2(){}
    Arista2(int V, int P){
        v = V;
        p = P;
        Lleno = 0;
    }
};
struct Nodo_normal{
    int Propagar;
    bool Limpiar;
    Nodo_normal(){
        Propagar = 0;
        Limpiar = 0;
    }
    Nodo_normal(int p, bool l){
        Propagar = p;
        Limpiar = l;
    }
};
vector< vi > Grafo;
vector< vector<Arista2> > Grafo2;
vi Distancias, /*Asignados, */Transformar;
bitset<100002> Nodos, Nada, Lista_normal;
vector<Nodo2> Lista;
vector<Nodo_normal> Cambios;
void Distanciar(int Nodo){
    for(auto E: Grafo[Nodo]){
        if(Distancias[E] <= Distancias[Nodo]) continue;
        Distancias[E] = Distancias[Nodo] + 1;
        Distanciar(E);
    }
}
void Crear(int Nodo, int Padre, int Contador){
    if(Nodos[Nodo] and Padre != -2){
        Grafo2[Transformar[Padre]].pb(Arista2(Transformar[Nodo], Contador));
        Contador = 0;
    }
    if(!Nodos[Nodo] and !Lista_normal[Nodo] and Padre != -2) Contador++;
    if(Nodos[Nodo] and Lista_normal[Nodo]) Lista[Transformar[Nodo]].Propagar = 1;
    if(Nodos[Nodo] and !Lista_normal[Nodo]) Lista[Transformar[Nodo]].Propagar = 0;
    if(Nodos[Nodo]) Lista[Transformar[Nodo]].Limpiar = 0;
    for(auto E: Grafo[Nodo]){
        if(Distancias[E] <= Distancias[Nodo]) continue;
        Crear(E, Nodos[Nodo] ? Nodo : Padre, Contador);
    }
}
void Ahora_s_(int Nodo, int Llevo, bool Cerear){
    if(Cerear){
        Lista[Nodo].Color = 0;
        Lista[Nodo].Propagar = 0;
        Lista[Nodo].Limpiar = 0;
        for(auto& E: Grafo2[Nodo]){
            E.Lleno = 0;
            Ahora_s_(E.v, 0, 1);
        }
        return;
    }
    Llevo += Lista[Nodo].Propagar + (int)Lista[Nodo].Color;
    if(Llevo > 0) Lista[Nodo].Color = 1;
    Llevo = max(0, Llevo - 1);
    Cerear = Cerear or Lista[Nodo].Limpiar;
    Lista[Nodo].Propagar = 0;
    Lista[Nodo].Limpiar = 0;
    for(auto& E: Grafo2[Nodo]){
        if(Llevo <= E.p - E.Lleno){
            E.Lleno += Llevo;
            if(Cerear) E.Lleno = 0;
            Ahora_s_(E.v, 0, Cerear);
            continue;
        }
        int Perdido = E.p - E.Lleno;
        E.Lleno = E.p;
        if(Cerear) E.Lleno = 0;
        Ahora_s_(E.v, Llevo - Perdido, Cerear);
    }
}
void Recuperar(int Nodo, int Llevo, bool Cerear){
    if(Cerear){
        Lista_normal[Nodo] = 0;
        Cambios[Nodo] = Nodo_normal();
        for(auto E: Grafo[Nodo]){
            if(Distancias[E] <= Distancias[Nodo]) continue;
            Recuperar(E, 0, 1);
        }
        return;
    }
    Llevo += Cambios[Nodo].Propagar + (int)Lista_normal[Nodo];
    if(Llevo > 0) Lista_normal[Nodo] = 1;
    Llevo = max(0, Llevo - 1);
    Cerear = Cerear or Cambios[Nodo].Limpiar;
    Cambios[Nodo] = Nodo_normal();
    for(auto E: Grafo[Nodo]){
        if(Distancias[E] <= Distancias[Nodo]) continue;
        Recuperar(E, Llevo, Cerear);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    Grafo.assign(n, {});
    Distancias.assign(n, 222222);
    Cambios.assign(n, Nodo_normal());
    //Lista_normal.assign(n, );
    forn(i, n - 1){
        int a;
        cin>>a;
        a--;
        Grafo[i + 1].pb(a);
        Grafo[a].pb(i + 1);
    }
    Distancias[0] = 0;
    Distanciar(0);
    int Ra_z = max((int)floor(sqrt(n)), 1);
    vector<Consulta> Consultas;
    Transformar.assign(n, -2);
    forn(i, q){
        int t, N;
        cin>>t>>N;
        N--;
        Consultas.pb(Consulta(t, N));
        if(!Nodos[N]) Grafo2.push_back({});
        Nodos[N] = 1;
        if((i + Ra_z - 1) % Ra_z != 0 and i < q - 1) continue;
        int c = 0;
        forn(i, n){
            if(Nodos[i]){
                Lista.pb(Nodo2(0, i, 0));
                Transformar[i] = c;
                c++;
            }
        }
        Crear(0, -2, 0);
        for(auto E: Consultas){
            if(E.t == 1){
                if(Lista[Transformar[E.n]].Limpiar){
                    for(auto& e: Grafo2[Transformar[E.n]]){
                        Lista[e.v].Limpiar = 1;
                        Lista[e.v].Propagar = 0;
                        e.Lleno = 0;
                    }
                    Lista[Transformar[E.n]].Propagar = 1;
                    Lista[Transformar[E.n]].Limpiar = 0;
                    //Ahora_s_(0, 0, 0);
                    Cambios[E.n].Propagar++;
                    continue;
                }
                Lista[Transformar[E.n]].Propagar++;
                Cambios[E.n].Propagar++;
                //Ahora_s_(0, 0, 0);
                continue;
            } else if(E.t == 2){
                Lista[Transformar[E.n]].Propagar = 0;
                Lista[Transformar[E.n]].Limpiar = 1;
                Cambios[E.n] = Nodo_normal(0, 1);
                //Ahora_s_(0, 0, 0);
                continue;
            }
            Ahora_s_(0, 0, 0);
            cout<<(Lista[Transformar[E.n]].Color ? "black" : "white")<<el;
        }
        //Ahora_s_(0, 0, 0);
        Recuperar(0, 0, 0);
        Nodos &= Nada;
        Consultas.clear();
        Grafo2.clear();
        Lista.clear();
    }
    return 0;
}