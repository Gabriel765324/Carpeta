#include "bits/stdc++.h"
using namespace std;
struct Valor{
    int Mayor_distancia_sin_m_, Respuesta_sin_m_, Profundidad, Mayor_distancia_conmigo, Respuesta_conmigo;
    vector<int> Mesa;
};
vector< vector<int> > Grafo;
vector<Valor> PD;
void Resolver(int Nodo){
    PD[Nodo].Profundidad = 0;
    PD[Nodo].Mayor_distancia_sin_m_ = 0;
    if(Grafo[Nodo].empty()){
        PD[Nodo].Mayor_distancia_conmigo = 1;
        PD[Nodo].Mayor_distancia_sin_m_ = 0;
        PD[Nodo].Profundidad = 1;
        PD[Nodo].Respuesta_conmigo = Nodo;
        PD[Nodo].Respuesta_sin_m_ = -2;
        return;
    }
    int Profundo = -2;
    pair<int, int> M_s_profundos = {-2, -2}, Profundidades_de_los_m_s_profundos = {-2, -2};
    for(auto E: Grafo[Nodo]){
        Resolver(E);
        if(PD[E].Profundidad + 1 > PD[Nodo].Profundidad){
            PD[Nodo].Profundidad = PD[E].Profundidad + 1;
            Profundo = E;
        }
        if(PD[E].Profundidad > Profundidades_de_los_m_s_profundos.second){
            Profundidades_de_los_m_s_profundos.second = PD[E].Profundidad;
            M_s_profundos.second = E;
            if(Profundidades_de_los_m_s_profundos.first < Profundidades_de_los_m_s_profundos.second){
                swap(Profundidades_de_los_m_s_profundos.first, Profundidades_de_los_m_s_profundos.second);
                swap(M_s_profundos.first, M_s_profundos.second);
            }
        }
        if(PD[E].Mayor_distancia_conmigo > PD[Nodo].Mayor_distancia_sin_m_){
            PD[Nodo].Mayor_distancia_sin_m_ = PD[E].Mayor_distancia_conmigo;
            PD[Nodo].Respuesta_sin_m_ = PD[E].Respuesta_conmigo;
        }
        if(PD[E].Mayor_distancia_sin_m_ > PD[Nodo].Mayor_distancia_sin_m_){
            PD[Nodo].Mayor_distancia_sin_m_ = PD[E].Mayor_distancia_sin_m_;
            PD[Nodo].Respuesta_sin_m_ = PD[E].Respuesta_sin_m_;
        }
    }
    int Anterior = Profundo;
    PD[Nodo].Mesa.push_back(Anterior);
    for(int i = 0; i < PD[Anterior].Mesa.size(); i++){
        PD[Nodo].Mesa.push_back(PD[Anterior].Mesa[i]);
        Anterior = PD[Anterior].Mesa[i];
    }
    PD[Nodo].Mesa = PD[Nodo].Mesa;
    if(Grafo[Nodo].size() == 1){
        int Consulta = PD[Nodo].Profundidad / 2, Actual = Nodo;
        while(Consulta > 0){
            int i = 0, d = 30, m = i;
            while(1){
                int p = (i + d) / 2;
                if(Consulta - (1<<(p + 1)) >= 0){
                    m = p;
                    i = p + 1;
                } else d = p - 1;
                if(i >= d) break;
            }
            m = min((int)PD[Actual].Mesa.size() - 1, m);
            Actual = PD[Actual].Mesa[m];
            Consulta -= (1<<m);
        }
        PD[Nodo].Respuesta_conmigo = Actual;
        PD[Nodo].Mayor_distancia_conmigo = PD[Nodo].Profundidad;
        return;
    }
    if(Profundidades_de_los_m_s_profundos.first == Profundidades_de_los_m_s_profundos.second){
        PD[Nodo].Respuesta_conmigo = Nodo;
        PD[Nodo].Mayor_distancia_conmigo = Profundidades_de_los_m_s_profundos.first + Profundidades_de_los_m_s_profundos.second + 1;
        return;
    }
    int Consulta = (Profundidades_de_los_m_s_profundos.first + Profundidades_de_los_m_s_profundos.second + 1) / 2 - Profundidades_de_los_m_s_profundos.second, Actual = Nodo;
    if((Profundidades_de_los_m_s_profundos.first + Profundidades_de_los_m_s_profundos.second) % 2 == 1) Consulta--;
    while(Consulta > 0){
        int i = 0, d = 30, m = i;
        while(1){
            int p = (i + d) / 2;
            if(Consulta - (1<<(p + 1)) >= 0){
                m = p;
                i = p + 1;
            } else d = p - 1;
            if(i >= d) break;
        }
        m = min((int)PD[Actual].Mesa.size() - 1, m);
        Actual = PD[Actual].Mesa[m];
        Consulta -= (1<<m);
    }
    PD[Nodo].Respuesta_conmigo = Actual;
    PD[Nodo].Mayor_distancia_conmigo = Profundidades_de_los_m_s_profundos.first + Profundidades_de_los_m_s_profundos.second + 1;
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    Grafo.assign(n, {});
    PD.assign(n, {});
    for(int i = 0; i < n - 1; ){
        int a;
        cin>>a;
        a--;
        i++;
        Grafo[a].push_back(i);
    }
    Resolver(0);
    while(m--){
        int a;
        cin>>a;
        a--;
        if(PD[a].Mayor_distancia_conmigo > PD[a].Mayor_distancia_sin_m_) cout<<PD[a].Respuesta_conmigo + 1<<"\n";
        else cout<<PD[a].Respuesta_sin_m_ + 1<<"\n";
    }
    return 0;
}