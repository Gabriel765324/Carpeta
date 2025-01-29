#include "holiday.h"
#include "bits/stdc++.h"
using namespace std;
long long n, Inicio, Tiempo;
vector< vector< vector<long long> > > Memorizaci_n;
vector<long long> Atracciones;
long long Resolver(long long i, long long Restante, long long Giro){
    if(Restante < 0) return -2222222222222222;
    if(i < 0 or i >= n) return -2222222222222222;
    if(Restante == 0) return 0;
    if(Restante == 1) return Memorizaci_n[i][Restante][Giro] = Atracciones[i];
    if(Memorizaci_n[i][Restante][Giro] != -2) return Memorizaci_n[i][Restante][Giro];
    long long m = 0;
    if(i == Inicio and Restante == Tiempo and Giro == 0){
        if(i + 1 < n) m = max(m, Resolver(i + 1, Restante - 1, 0));
        if(i + 1 < n) m = max(m, Resolver(i + 1, Restante - 2, 0) + Atracciones[i]);
        if(i > 0) m = max(m, Resolver(i - 1, Restante - 1, 0));
        if(i > 0) m = max(m, Resolver(i - 1, Restante - 2, 0) + Atracciones[i]);
    } else {
        if(i < Inicio){
            if(i > 0) m = max(m, Resolver(i - 1, Restante - 1, Giro));
            if(i > 0) m = max(m, Resolver(i - 1, Restante - 2, Giro) + Atracciones[i]);
            if(Giro == 0){
                if(Inicio + 1 < n) m = max(m, Resolver(Inicio + 1, Restante - (Inicio - i) - 1, 1));
                if(Inicio + 1 < n) m = max(m, Resolver(Inicio + 1, Restante - (Inicio - i) - 2, 1) + Atracciones[i]);
            }
        } else {
            if(i + 1 < n) m = max(m, Resolver(i + 1, Restante - 1, Giro));
            if(i + 1 < n) m = max(m, Resolver(i + 1, Restante - 2, Giro) + Atracciones[i]);
            if(Giro == 0){
                if(Inicio > 0) m = max(m, Resolver(Inicio - 1, Restante - (i - Inicio) - 1, 1));
                if(Inicio > 0) m = max(m, Resolver(Inicio - 1, Restante - (i - Inicio) - 2, 1) + Atracciones[i]);
            }
        }
    }
    m = max(m, Atracciones[i]);
    return Memorizaci_n[i][Restante][Giro] = m;
}
long long int findMaxAttraction(int N, int start, int d, int attraction[]){
    n = N;
    Inicio = start;
    Tiempo = d;
    for(long long i = 0; i < n; i++) Atracciones.push_back(attraction[i]);
    if(n == 1){
        if(Tiempo > 0) return Atracciones[0];
        else return 0;
    }
    Memorizaci_n.assign(n, vector< vector<long long> >(Tiempo + 1, vector<long long>(2, -2)));
    return Resolver(Inicio, Tiempo, 0);
}
/*
Caso fallido.
3 0 7
0 1 2
Salida: 1
Debería ser 3.
*/