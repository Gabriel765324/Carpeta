#include "bits/stdc++.h"
using namespace std;
struct Fuente{
    long long Di_metro, Volumen;
};
struct Ancestro{
    long long Suma, Anterior;
};
vector< vector<long long> > Grafo;
vector<bool> Visitados;
vector< vector<Ancestro> > Ancestrales;
vector<Fuente> Fuentes;
Fuente Nada;
void DFS(long long Nodo){
    Visitados[Nodo] = 1;
    long long EL_DE_ANTES = -2;
    for(auto E: Grafo[Nodo]){
        EL_DE_ANTES = E;
        if(!Visitados[E]) DFS(E);
    }
    Ancestro Non;
    Nada.Di_metro = 0;
    Nada.Volumen = 0;
    if(EL_DE_ANTES == -2){
        Ancestrales[Nodo].push_back(Non);
        Ancestrales[Nodo][0].Suma = Fuentes[Nodo].Volumen;
        Ancestrales[Nodo][0].Anterior = Nodo;
    } else {
        Ancestrales[Nodo].push_back(Non);
        Ancestrales[Nodo][0].Suma = Fuentes[Nodo].Volumen;
        Ancestrales[Nodo][0].Anterior = EL_DE_ANTES;
        long long Sumando = Fuentes[Nodo].Volumen;
        long long i = EL_DE_ANTES;
        for(long long j = 0; j < Ancestrales[i].size(); j++){
            Sumando += Ancestrales[i][j].Suma;
            i = Ancestrales[i][j].Anterior;
            Ancestro Nuevo;
            Nuevo.Suma = Sumando;
            Nuevo.Anterior = i;
            Ancestrales[Nodo].push_back(Nuevo);
        }
    }
}
long long Consulta(long long f, long long v){
    bool Primero = 1;
    while(1){
        long long i;
        for(i = 0; i < Ancestrales[f].size(); i++){
            if(Ancestrales[f][i].Suma >= v) break;
        }
        if(i == 0) return f;
        i--;
        v -= Ancestrales[f][i].Suma;
        f = Ancestrales[f][i].Anterior;
    }
    return f;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Nada.Di_metro = 0;
    Nada.Volumen = 0;
    long long n, q;
    cin>>n>>q;
    Ancestrales.assign(n + 1, {});
    Grafo.assign(n + 1, {});
    Visitados.assign(n + 1, 0);
    Fuentes.assign(n + 1, Nada);
    Fuentes.back().Di_metro = 2222222222222222;
    Fuentes.back().Volumen = 2222222222222222;
    deque<long long> Cola1 = {2222222222222222};
    deque<long long> Cola2 = {n};
    for(long long i = 0; i < n; i++){
        cin>>Fuentes[i].Di_metro>>Fuentes[i].Volumen;
    }
    for(long long i = n - 1; i > -1; i--){
        long long Mejor = upper_bound(Cola1.begin(), Cola1.end(), Fuentes[i].Di_metro) - Cola1.begin();
        long long Mayor = Cola1[Mejor], Quitar = -0;
        while(Cola1[0] < Mayor){
            Cola1.pop_front();
            Quitar++;
        }
        while(Quitar--){
            Cola2.pop_front();
        }
        Grafo[i].push_back(Cola2[0]);
        //cout<<i + 1<<" "<<Cola2[0] + 1<<"\n";
        Cola1.push_front(Fuentes[i].Di_metro);
        Cola2.push_front(i);
    }
    for(long long i = 0; i <= n; i++){
        if(!Visitados[i]) DFS(i);
    }
    /*for(long long i = 0; i <= n; i++){
        cout<<i + 1<<"  ";
        for(long long j = 0; j < Ancestrales[i].size(); j++) cout<<Ancestrales[i][j].Suma<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    for(long long i = 0; i <= n; i++){
        cout<<i + 1<<"  ";
        for(long long j = 0; j < Ancestrales[i].size(); j++) cout<<Ancestrales[i][j].Anterior + 1<<" ";
        cout<<"\n";
    }
    cout<<"\n";*/
    while(q--){
        long long f, v;
        cin>>f>>v;
        long long Respuesta = Consulta(f - 1, v);
        if(Respuesta == n) cout<<"0\n";
        else cout<<Respuesta + 1<<"\n";
    }
    return 0;
}