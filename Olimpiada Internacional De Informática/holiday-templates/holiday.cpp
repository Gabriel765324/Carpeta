#include "holiday.h"
#include "bits/stdc++.h"
using namespace std;
long long n, Inicio, Tiempo;
vector< vector< vector<long long> > > Memorizaci_n;
vector<long long> Atracciones;
vector<long long> _rbol, Propagar;
long long Consulta(long long i, long long d, long long p, long long c){
    if(c < 0) return 0;
    if(i != d and Propagar[p] != -2){
        _rbol[p] = max(Propagar[p], _rbol[p]);
        Propagar[p * 2] = max(Propagar[p], Propagar[p * 2]);
        Propagar[p * 2 + 1] = max(Propagar[p], Propagar[p * 2 + 1]);
        Propagar[p] = -2;
    }
    if(i == c and d == i) return _rbol[p];
    if(i > c or d < c) return 0;
    long long P = (i + d) / 2;
    return max(Consulta(i, P, p * 2, c), Consulta(P + 1, d, p * 2 + 1, c));
}
void Actualizar(long long i, long long d, long long p, long long I, long long D, long long v){
    if(i != d and Propagar[p] != -2){
        _rbol[p] = max(Propagar[p], _rbol[p]);
        Propagar[p * 2] = max(Propagar[p], Propagar[p * 2]);
        Propagar[p * 2 + 1] = max(Propagar[p], Propagar[p * 2 + 1]);
        Propagar[p] = -2;
    }
    if(i >= I and d <= D){
        _rbol[p] = max(_rbol[p], v);
        Propagar[p] = max(Propagar[p], v);
        return;
    }
    if(i > D or d < I) return;
    long long P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D, v);
    Actualizar(P + 1, d, p * 2 + 1, I, D, v);
    _rbol[p] = max(_rbol[p * 2], _rbol[p * 2 + 1]);
}
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
    if(Tiempo == 0) return 0;
    if(n == 1) return Atracciones[0];
    if(Inicio == 0 or Inicio == n - 1){
        if(Inicio == n - 1){
            for(long long i = 0; i < n / 2; i++) swap(Atracciones[i], Atracciones[n - i - 1]);
            Inicio = 0;
        }
        multiset<long long> Mejores;
        long long Suma = 0, Mejor = 0;
        for(long long i = 0; i < n and i < Tiempo; i++){
            Mejores.insert(Atracciones[i]);
            Suma += Atracciones[i];
            long long Precio = Mejores.size() + i;
            while(Precio > Tiempo){
                Suma -= *Mejores.begin();
                Mejores.erase(Mejores.begin());
                Precio = Mejores.size() + i;
            }
            Mejor = max(Suma, Mejor);
        }
        return Mejor;
    }
    if(n * Tiempo <= 2000000){
        Memorizaci_n.assign(n, vector< vector<long long> >(Tiempo + 1, vector<long long>(2, -2)));
        return Resolver(Inicio, Tiempo, 0);
    }
    if(n <= 3022 and Tiempo <= 3022 * 2 + 3022 / 2 + 22){
        deque< vector<long long> > Inicio_m_s_1(2, vector<long long>(Tiempo + 1, 0)), Inicio_menos_1 = Inicio_m_s_1, Izquierda = Inicio_m_s_1, Derecha = Inicio_m_s_1;
        for(long long i = 1; i <= Tiempo; i++){
            Inicio_m_s_1[0][i] = max(Inicio_m_s_1[0][i], Atracciones.back());
        }
        for(long long i = n - 2; i > Inicio; i--){
            swap(Inicio_m_s_1[0], Inicio_m_s_1[1]);
            Inicio_m_s_1[0][0] = 0;
            for(long long j = 1; j <= Tiempo; j++){
                long long m = Atracciones[i];
                m = max(m, Inicio_m_s_1[1][j - 1]);
                if(j > 1) m = max(m, Inicio_m_s_1[1][j - 2] + Atracciones[i]);
                Inicio_m_s_1[0][j] = m;
            }
        }
        for(long long i = 1; i <= Tiempo; i++){
            Inicio_menos_1[0][i] = max(Atracciones[0], Inicio_menos_1[0][i]);
        }
        for(long long i = 1; i < Inicio; i++){
            swap(Inicio_menos_1[0], Inicio_menos_1[1]);
            Inicio_menos_1[0][0] = 0;
            for(long long j = 1; j <= Tiempo; j++){
                long long m = Atracciones[i];
                m = max(m, Inicio_menos_1[1][j - 1]);
                if(j > 1) m = max(m, Inicio_menos_1[1][j - 2] + Atracciones[i]);
                Inicio_menos_1[0][j] = m;
            }
        }
        for(long long i = 1; i <= Tiempo; i++){
            Izquierda[0][i] = max(Izquierda[0][i], Atracciones[0]);
        }
        for(long long i = 1; i < Inicio; i++){
            swap(Izquierda[0], Izquierda[1]);
            Izquierda[0][0] = 0;
            for(long long j = 1; j <= Tiempo; j++){
                long long m = Atracciones[i];
                m = max(m, Izquierda[1][j - 1]);
                if(j > 1) m = max(m, Izquierda[1][j - 2] + Atracciones[i]);
                if(Inicio + 1 < n and j - (Inicio - i) - 1 > 0) m = max(m, Inicio_m_s_1[0][j - (Inicio - i) - 1]);
                if(Inicio + 1 < n and j - (Inicio - i) - 2 > 0) m = max(m, Inicio_m_s_1[0][j - (Inicio - i) - 2] + Atracciones[i]);
                Izquierda[0][j] = m;
            }
        }
        for(long long i = 1; i <= Tiempo; i++){
            Derecha[0][i] = max(Atracciones.back(), Derecha[0][i]);
        }
        for(long long i = n - 2; i > Inicio; i--){
            swap(Derecha[0], Derecha[1]);
            Derecha[0][0] = 0;
            for(long long j = 1; j <= Tiempo; j++){
                long long m = Atracciones[i];
                m = max(m, Derecha[1][j - 1]);
                if(j > 1) m = max(m, Derecha[1][j - 2] + Atracciones[i]);
                if(Inicio > 0 and j - (i - Inicio) - 1 > 0) m = max(m, Inicio_menos_1[0][j - (i - Inicio) - 1]);
                if(Inicio > 0 and j - (i - Inicio) - 2 > 0) m = max(m, Inicio_menos_1[0][j - (i - Inicio) - 2] + Atracciones[i]);
                Derecha[0][j] = m;
            }
        }
        long long m = Atracciones[Inicio];
        if(Inicio + 1 < n) m = max(m, Derecha[0][Tiempo - 1]);
        if(Inicio + 1 < n and Tiempo > 1) m = max(m, Derecha[0][Tiempo - 2] + Atracciones[Inicio]);
        if(Inicio > 0) m = max(m, Izquierda[0][Tiempo - 1]);
        if(Inicio > 0 and Tiempo > 1) m = max(m, Izquierda[0][Tiempo - 2] + Atracciones[Inicio]);
        return m;
    } else {
        _rbol.assign((Tiempo + 22) * 4, 0);
        Propagar.assign((Tiempo + 22) * 4, -2);
        multiset<long long> Mejores;
        long long Suma = 0, Mejor = 0, Ganador = 0;
        for(long long i = Inicio + 1; i < n and i - Inicio < Tiempo; i++){
            Mejores.insert(Atracciones[i]);
            Suma += Atracciones[i];
            long long Precio = Mejores.size() + i - Inicio;
            if(Precio <= Tiempo) Ganador = max(Ganador, Suma);
            Actualizar(0, Tiempo + 2, 1, Precio, Tiempo + 2, Suma);
            while(Precio > Tiempo){
                Suma -= *Mejores.begin();
                Mejores.erase(Mejores.begin());
                Precio = Mejores.size() + i;
            }
            Mejor = max(Suma, Mejor);
            if(Precio <= Tiempo) Ganador = max(Ganador, Mejor);
            Actualizar(0, Tiempo + 2, 1, Precio, Tiempo + 2, Mejor);
        }
        Suma = 0;
        Mejor = 0;
        Mejores.clear();
        for(long long i = Inicio; i > -1 and Inicio - i <= Tiempo; i++){
            Mejores.insert(Atracciones[i]);
            Suma += Atracciones[i];
            long long Precio = Mejores.size() + Inicio - i;
            if(Precio <= Tiempo) Ganador = max(Ganador, Suma);
            long long Extra = Precio + Inicio - i, Mejor_extra = Consulta(0, Tiempo + 2, 1, Tiempo - Extra);
            Ganador = max(Ganador, Suma + Mejor_extra);
            while(Precio > Tiempo){
                Suma -= *Mejores.begin();
                Mejores.erase(Mejores.begin());
                Precio = Mejores.size() + i;
            }
            Mejor = max(Suma, Mejor);
            Ganador = max(Ganador, Mejor);
            Extra = Precio + Inicio - i, Mejor_extra = Consulta(0, Tiempo + 2, 1, Tiempo - Extra);
            Ganador = max(Ganador, Mejor + Mejor_extra);
        }
        return Ganador;
    }
}
/*
Caso fallido.


Salida: 
Debería ser .
*/