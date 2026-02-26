#include "bits/stdc++.h"
using namespace std;
struct Conexi_n{
    long long Capacidad, Costo;
    bool Existe;
};
vector< vector<Conexi_n> > Matriz;
vector<long long> Ancestros, Distancias;
long long Distancia(long long Inicio, long long Final){
    long long n = Matriz.size(), Flujo = 2222222222222222;
    Ancestros.assign(n + 22, -2);
    Distancias.assign(n + 22, 2222222222222222);
    Distancias[Inicio] = 0;
    for(int j = 0; j < n - 1; j++){
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(Matriz[k][i].Capacidad != 0 and Matriz[k][i].Existe and Distancias[i] > Distancias[k] + Matriz[k][i].Costo){
                    Distancias[i] = Distancias[k] + Matriz[k][i].Costo;
                    Ancestros[i] = j;
                    Flujo = min(Flujo, Matriz[k][i].Capacidad);
                }
            }
        }
    }
    if(Ancestros[Final] == -2) return 0;
    return Flujo;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    Conexi_n Nada;
    Nada.Capacidad = 0;
    Nada.Costo = 0;
    Nada.Existe = 0;
    Matriz.assign(2 * n + 22, vector<Conexi_n>(2 * n + 22, Nada));
    vector< vector<long long> > a(n, vector<long long>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
            Matriz[i][j + n].Capacidad = 1;
            Matriz[i][j + n].Costo = a[i][j];
            Matriz[j + n][i].Costo = -a[i][j];
            Matriz[i][j + n].Existe = 1;
            Matriz[j + n][i].Existe = 1;
        }
    }
    for(int i = 0; i < n; i++){
        Matriz[2 * n][i].Capacidad = 1;
        Matriz[i + n][2 * n + 1].Capacidad = 1;
        Matriz[2 * n][i].Existe = 1;
        Matriz[i + n][2 * n + 1].Existe = 1;
    }
    long long f, Costo_m_nimo = 0;
    while(f = Distancia(2 * n, 2 * n + 1)){
        if(f == 0) break;
        for(long long Nodo = 2 * n + 1; Nodo != 2 * n; Nodo = Ancestros[Nodo]){
            long long Siguiente = Ancestros[Nodo];
            Matriz[Siguiente][Nodo].Capacidad -= f;
            Matriz[Nodo][Siguiente].Capacidad += f;
            Costo_m_nimo += f * Matriz[Siguiente][Nodo].Costo;
        }
    }
    cout<<Costo_m_nimo<<"\n";
    for(int i = 0; i < n; i++){
        for(int j = n; j < 2 * n; j++){
            if(Matriz[i][j].Capacidad == 0){
                cout<<i + 1<<" "<<j + 1 - n<<"\n";
                break;
            }
        }
    }
    return 0;
}