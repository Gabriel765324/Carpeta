#include "soccer.h"
#include "bits/stdc++.h"
using namespace std;
vector< vector<int> > Acumulada;
int Consulta(int i, int j, int k, int l){
    if(k < i) swap(k, i);
    if(l < j) swap(l, j);
    return Acumulada[k][l] - Acumulada[i - 1][l] - Acumulada[k][j - 1] + Acumulada[i - 1][j - 1];
}
int biggest_stadium(int n, vector< vector<int> > FULBO){
    int r = 0;
    Acumulada.assign(n + 2, vector<int>(n + 2, 0));
    deque< deque<int> > fulbo(n);
    for(int i = 0; i < n; i++){
        int Componentes = 0;
        for(int j = 0; j < n; j++){
            r += 1 - FULBO[i][j];
            fulbo[i].push_back(FULBO[i][j]);
            if((j == 0 and FULBO[i][j] == 0) or (j > 0 and FULBO[i][j - 1] == 1 and FULBO[i][j] == 0)) Componentes++;
        }
        if(Componentes > 1){
            //cerr<<"No conexo.\n";
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        int Componentes = 0;
        fulbo[i].push_front(1);
        fulbo[i].push_back(1);
        for(int j = 0; j < n; j++){
            if((j == 0 and FULBO[j][i] == 0) or (j > 0 and FULBO[j - 1][i] == 1 and FULBO[j][i] == 0)) Componentes++;
        }
        if(Componentes > 1){
            //cerr<<"No conexo.\n";
            return 0;
        }
    }
    fulbo.push_front(deque<int>(n + 2, 1));
    fulbo.push_back(deque<int>(n + 2, 1));
    for(int i = 0; i < n + 2; i++){
        Acumulada[0][i] = i + 1;
        Acumulada[i][0] = i + 1;
    }
    for(int i = 1; i < n + 2; i++){
        for(int j = 1; j < n + 2; j++){
            Acumulada[i][j] = fulbo[i][j] + Acumulada[i - 1][j] + Acumulada[i][j - 1] - Acumulada[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(fulbo[i][j] == 0) continue;
            //cerr<<i<<" "<<j<<"\n";
            int Izquerda = j, Derecha = n + 1, Mejor = j, Otro_mejor = i;
            while(1){
                int Promedio = (Izquerda + Derecha) / 2;
                if(Consulta(i, j, i, Promedio) <= Consulta(i, j, i, j)){
                    Mejor = Promedio;
                    Izquerda = Promedio + 1;
                } else Derecha = Promedio - 1;
                if(Izquerda >= Derecha + 1) break;
            }
            //cerr<<Mejor<<" ";
            Izquerda = i, Derecha = n + 1;
            while(1){
                int Promedio = (Izquerda + Derecha) / 2;
                if(Consulta(i, j, Promedio, Mejor) <= Consulta(i, j, i, Mejor)){
                    Otro_mejor = Promedio;
                    Izquerda = Promedio + 1;
                } else Derecha = Promedio - 1;
                if(Izquerda >= Derecha + 1) break;
            }
            //cerr<<Otro_mejor<<" ";
            int Izquerda1 = i, Derecha1 = n + 1, Mejor1 = i, Otro_mejor1 = j;
            while(1){
                int Promedio1 = (Izquerda1 + Derecha1) / 2;
                if(Consulta(i, j, Promedio1, j) <= Consulta(i, j, i, j)){
                    Otro_mejor1 = Promedio1;
                    Izquerda1 = Promedio1 + 1;
                } else Derecha1 = Promedio1 - 1;
                if(Izquerda1 >= Derecha1 + 1) break;
            }
            //cerr<<Otro_mejor1<<" ";
            Izquerda1 = j, Derecha1 = n + 1;
            while(1){
                int Promedio1 = (Izquerda1 + Derecha1) / 2;
                if(Consulta(i, j, Otro_mejor1, Promedio1) <= Consulta(i, j, Otro_mejor1, j)){
                    Mejor1 = Promedio1;
                    Izquerda1 = Promedio1 + 1;
                } else Derecha1 = Promedio1 - 1;
                if(Izquerda1 >= Derecha1 + 1) break;
            }
            //cerr<<Mejor1<<"\n";
            if(Mejor < Mejor1 and Otro_mejor > Otro_mejor1){
                //cerr<<Mejor<<" "<<Otro_mejor<<" "<<Mejor1<<" "<<Otro_mejor1<<"\n";
                return 0;
            }
            Izquerda = 0, Derecha = j, Mejor = j, Otro_mejor = i;
            while(1){
                int Promedio = (Izquerda + Derecha) / 2;
                if(Consulta(i, j, i, Promedio) <= Consulta(i, j, i, j)){
                    Mejor = Promedio;
                    Derecha = Promedio - 1;
                } else Izquerda = Promedio + 1;
                if(Izquerda >= Derecha + 1) break;
            }
            //cerr<<Mejor<<" ";
            Izquerda = i, Derecha = n + 1;
            while(1){
                int Promedio = (Izquerda + Derecha) / 2;
                if(Consulta(i, j, Promedio, Mejor) <= Consulta(i, j, i, Mejor)){
                    Otro_mejor = Promedio;
                    Izquerda = Promedio + 1;
                } else Derecha = Promedio - 1;
                if(Izquerda >= Derecha + 1) break;
            }
            //cerr<<Otro_mejor<<" ";
            Izquerda1 = i, Derecha1 = n + 1, Mejor1 = j, Otro_mejor1 = i;
            while(1){
                int Promedio1 = (Izquerda1 + Derecha1) / 2;
                if(Consulta(i, j, Promedio1, j) <= Consulta(i, j, i, j)){
                    Otro_mejor1 = Promedio1;
                    Izquerda1 = Promedio1 + 1;
                } else Derecha1 = Promedio1 - 1;
                if(Izquerda1 >= Derecha1 + 1) break;
            }
            //cerr<<Otro_mejor1<<" ";
            Izquerda1 = 0, Derecha1 = j;
            while(1){
                int Promedio1 = (Izquerda1 + Derecha1) / 2;
                if(Consulta(i, j, Otro_mejor1, Promedio1) <= Consulta(i, j, Otro_mejor1, j)){
                    Mejor1 = Promedio1;
                    Derecha1 = Promedio1 - 1;
                } else Izquerda1 = Promedio1 + 1;
                if(Izquerda1 >= Derecha1 + 1) break;
            }
            //cerr<<Mejor1<<"\n";
            if(Mejor < Mejor1 and Otro_mejor < Otro_mejor1){
                //cerr<<Mejor<<" "<<Otro_mejor<<" "<<Mejor1<<" "<<Otro_mejor1<<"\n";
                return 0;
            }
        }
    }
    return r;
}