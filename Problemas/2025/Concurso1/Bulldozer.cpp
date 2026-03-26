#include "bits/stdc++.h"
using namespace std;
struct Punto{
    double x, y, d;
    long long v;
};
bool operator<(const Punto& a, const Punto& b){
    return a.d < b.d;
}
struct Ecuaci_n{
    double A, B, C;
};
double Mucho = DBL_MAX;
bool Igual(double a, double b){
    return abs(a - b) <= 1e-10;
}
Ecuaci_n Punto_y_punto(Punto a, Punto b){
    Ecuaci_n Respuesta;
    if(Igual(a.x, b.x)){
        Respuesta.A = 1;
        Respuesta.B = 0;
        Respuesta.C = -a.x;
        return Respuesta;
    }
    if(Igual(a.y, b.y)){
        Respuesta.A = 0;
        Respuesta.B = 1;
        Respuesta.C = -a.y;
        return Respuesta;
    }
    Respuesta.A = -(b.y - a.y) / (b.x - a.x);
    Respuesta.B = 1;
    Respuesta.C = -a.y + (b.y - a.y) / (b.x - a.x) * a.x;
    return Respuesta;
}
Ecuaci_n Punto_y_pendiente(double m, Punto a){
    Ecuaci_n Respuesta;
    if(Igual(m, Mucho)){
        Respuesta.A = 1;
        Respuesta.B = 0;
        Respuesta.C = -a.x;
        return Respuesta;
    }
    Respuesta.A = -m;
    Respuesta.B = 1;
    Respuesta.C = -a.y + m * a.x;
    return Respuesta;
}
double Distancia_entre_un_punto_y_una_recta(Ecuaci_n a, Punto b){
    double Distancia = abs((a.A * b.x + a.B * b.y + a.C) / (sqrt(a.A * a.A + a.B * a.B)));
    if(Igual(a.B, 0)){
        if(b.x < -a.C) return -Distancia;
        return Distancia;
    }
    double v = -a.A / a.B * b.x - a.C / a.B;
    if(v > b.y) return -Distancia;
    return Distancia;
}
bool o(Punto &a, Punto &b){
    return a.x < b.x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector<Punto> a(n);
    bool Cero = 1;
    for(long long i = 0; i < n; i++){
        cin>>a[i].x>>a[i].y>>a[i].v;
        if(a[i].y != 0) Cero = 0;
    }
    if(n == 1){
        cout<<max(0LL, a[0].v);
        return 0;
    }
    if(Cero){
        long long Mejor = 0, Actual = 0;
        sort(a.begin(), a.end(), o);
        for(long long i = 0; i < n; i++){
            Actual += a[i].v;
            Mejor = max(Mejor, Actual);
            Actual = max(Actual, 0LL);
        }
        cout<<Mejor;
        return 0;
    }
    long long Mejor = -0;
    for(long long i = 0; i < n - 1; i++){
        for(long long j = i + 1; j < n; j++){
            vector<Punto> Auxiliar;
            Ecuaci_n Actual = Punto_y_punto(a[i], a[j]);
            //cout<<Actual.A<<"x + "<<Actual.B<<"y + "<<Actual.C<<" = 0\n"<<a[i].x<<" "<<a[i].y<<"\n"<<a[j].x<<" "<<a[j].y<<"\n";
            for(long long k = 0; k < n; k++){
                if(k != i and k != j){
                    Auxiliar.push_back(a[k]);
                    Auxiliar.back().d = Distancia_entre_un_punto_y_una_recta(Actual, Auxiliar.back());
                    //cout<<Auxiliar.back().x<<" "<<Auxiliar.back().y<<" d = "<<Auxiliar.back().d<<"\n";
                }
            }
            sort(Auxiliar.begin(), Auxiliar.end());
            long long Izquierda;
            for(Izquierda = 0; Izquierda < n - 2; Izquierda++){
                if(Auxiliar[Izquierda].d >= 0) break;
            }
            long long Posible = 0, Suma = 0;
            long long Derecha = Izquierda;
            for(Izquierda--; Izquierda > -1; Izquierda--){
                Suma += Auxiliar[Izquierda].v;
                Posible = max(Posible, Suma);
            }
            for(Suma = 0; Derecha < n - 2; Derecha++){
                Suma += Auxiliar[Derecha].v;
                Posible = max(Posible, Suma);
            }
            Posible = max(max(Posible, a[i].v + Posible), max(a[j].v + Posible, a[i].v + a[j].v + Posible));
            Mejor = max(Mejor, Posible);
        }
    }
    cout<<Mejor;
    return 0;
}
/*
4
2 4 1
2 3 3
3 1 -6
4 2 4
*/