#include "bits/stdc++.h"
#define forn(i, n) for(int i=0; i<int(n); i++)
#define forsn(i, s, n) for(int i=int(s); i<int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
struct Punto{
    long double x, y;
};
Punto a, b, c;
long double r;
long double Circunferencia1(long double x){
    return sqrt(r * r - (x - c.x) * (x - c.x)) + c.y;
}
long double Circunferencia2(long double x){
    return - sqrt(r * r - (x - c.x) * (x - c.x)) + c.y;
}
long double Distancia(Punto _1, Punto _2){
    return sqrt((_1.x - _2.x) * (_1.x - _2.x) + (_1.y - _2.y) * (_1.y - _2.y));
}
void G(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>r;
        long double dx = b.x - a.x, dy = b.y - a.y;
        long double Distancia_ = abs((- dy * c.x + dx * c.y + dy * a.x) / sqrt(dx * dx + dy * dy));
        if(Distancia_ <= r){
            cout<<setprecision(22)<<sqrt(dx * dx + dy * dy)<<"\n";
            continue;
        }
        long double Inicio = c.x - r, Final = c.x + r, Respuesta = 2222222222222222;
        int Contador = 2222;
        while(Contador--){
            vector<long double> Arriba;
            long double Menor = 2222222222222222;
            int p = -2;
            for(int i = 0; i <= 2222; i++){
                Punto Actual;
                Actual.x = Inicio + (Final - Inicio) * (long double)i / (long double)100;
                Arriba.push_back(Circunferencia1(Actual.x));
                Actual.y = Arriba.back();
                long double Posible = Distancia(Actual, a) + Distancia(Actual, b);
                Arriba.back() = Posible;
                Respuesta = min(Respuesta, Posible);
                if(i > 0 and Posible < Menor){
                    Menor = Posible;
                    p = i;
                }
            }
            if(p == 0) p++;
            if(p == 100) p--;
            Inicio = Arriba[p - 1];
            Final = Arriba[p + 1];
        }
        Inicio = c.x - r;
        Final = c.x + r;
        Contador = 2222;
        while(Contador--){
            vector<long double> Arriba;
            long double Menor = 2222222222222222;
            int p = -2;
            for(int i = 0; i <= 2222; i++){
                Punto Actual;
                Actual.x = Inicio + (Final - Inicio) * (long double)i / (long double)100;
                Arriba.push_back(Circunferencia2(Actual.x));
                Actual.y = Arriba.back();
                long double Posible = Distancia(Actual, a) + Distancia(Actual, b);
                Arriba.back() = Posible;
                Respuesta = min(Respuesta, Posible);
                if(i > 0 and Posible < Menor){
                    Menor = Posible;
                    p = i;
                }
            }
            if(p == 0) p++;
            if(p == 100) p--;
            Inicio = Arriba[p - 1];
            Final = Arriba[p + 1];
        }
        cout<<setprecision(22)<<Respuesta<<el;
    }
}
/*
1
0 0 2 0 -1 2 1
*/
int main(){
    G();
    return 0;
}