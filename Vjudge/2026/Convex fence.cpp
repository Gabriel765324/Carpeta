#include "bits/stdc++.h"
using namespace std;
struct Punto{
    long long x, y;
};
double Pi = atan(1) * (double)4;
double Distancia(Punto a, Punto b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool Ordenador(Punto &a, Punto &b){
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
int Orientaci_n(Punto a, Punto b, Punto c){
    long long o = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if(o == 0) return 0;
    return (long long)abs(o) / o;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, Caso = 0;
    cin>>t;
    while(t--){
        Caso++;
        long long n, d;
        cin>>n>>d;
        vector<Punto> Lista(n);
        for(int i = 0; i < n; i++){
            cin>>Lista[i].x>>Lista[i].y;
        }
        if(n == 1){
            cout<<setprecision(22)<<"Case "<<Caso<<": "<<Pi * (double)d * (double)2<<"\n";
            continue;
        }
        if(n == 2){
            cout<<setprecision(22)<<"Case "<<Caso<<": "<<Pi * (double)d * (double)2 + Distancia(Lista[0], Lista[1]) * (double)2<<"\n";
            continue;
        }
        sort(Lista.begin(), Lista.end(), Ordenador);
        vector<Punto> Arriba = {Lista[0]}, Abajo = Arriba;
        for(int i = 1; i < n; i++){
            if(i == n - 1 or Orientaci_n(Lista[0], Lista[i], Lista.back()) <= 0){
                while(Arriba.size() > 1 and Orientaci_n(Arriba[Arriba.size() - 2], Arriba.back(), Lista[i]) > 0){
                    Arriba.pop_back();
                }
                Arriba.push_back(Lista[i]);
            }
            if(i == n - 1 or Orientaci_n(Lista[0], Lista[i], Lista.back()) > 0){
                while(Abajo.size() > 1 and Orientaci_n(Abajo[Abajo.size() - 2], Abajo.back(), Lista[i]) < 0){
                    Abajo.pop_back();
                }
                Abajo.push_back(Lista[i]);
            }
        }
        double Suma = Pi * (double)d * (double)2;
        vector<Punto> Tomar;
        for(int i = 0; i < Arriba.size(); i++){
            Tomar.push_back(Arriba[i]);
            //cerr<<Arriba[i].x<<" "<<Arriba[i].y<<"\n";
        }
        for(int i = Abajo.size() - 2; i > 0; i--){
            Tomar.push_back(Abajo[i]);
            //cerr<<Abajo[i].x<<" "<<Abajo[i].y<<"\n";
        }
        for(int i = 0; i < Tomar.size(); i++) Suma += Distancia(Tomar[i], Tomar[(i + 1) % Tomar.size()]);
        cout<<setprecision(22)<<"Case "<<Caso<<": "<<Suma<<"\n";
    }
    return 0;
}