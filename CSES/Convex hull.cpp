#include "bits/stdc++.h"
using namespace std;
struct Punto{
    long long x, y;
};
Punto Inicio;
long long Orientaci_n(Punto a, Punto b, Punto c){
    long long o = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if(o == 0) return 0;
    if(o < 0) return -1;
    return 1;
}
bool Ordenador(Punto &a, Punto &b){
    if(Orientaci_n(Inicio, a, b) == 0) return (a.x - Inicio.x) * (a.x - Inicio.x) + (a.y - Inicio.y) * (a.y - Inicio.y) < (Inicio.x - b.x) * (Inicio.x - b.x) + (Inicio.y - b.y) * (Inicio.y - b.y);
    return Orientaci_n(Inicio, a, b) < 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector<Punto> Puntos(n);
    long long Menor = 0;
    for(long long i = 0; i < n; i++){
        cin>>Puntos[i].x>>Puntos[i].y;
        if(make_pair(Puntos[Menor].y, Puntos[Menor].x) > make_pair(Puntos[i].y, Puntos[i].x)) Menor = i;
    }
    Inicio = Puntos[Menor];
    Puntos.erase(Puntos.begin() + Menor);
    sort(Puntos.begin(), Puntos.end(), Ordenador);
    for(long long i = n - 2; i > -1; i--){
        if(Orientaci_n(Inicio, Puntos[i], Puntos.back()) != 0){
            long long j = n - 2;
            for(i++; i < j; i++){
                swap(Puntos[i], Puntos[j]);
                j--;
            }
            break;
        }
    }
    Puntos.push_back(Inicio);
    vector<Punto> Respuesta = {Inicio, Puntos[0]};
    for(long long i = 1; i < n; i++){
        while(Respuesta.size() > 2 and Orientaci_n(Respuesta[Respuesta.size() - 2], Respuesta.back(), Puntos[i]) > 0) Respuesta.pop_back();
        Respuesta.push_back(Puntos[i]);
    }
    Respuesta.pop_back();
    cout<<Respuesta.size()<<"\n";
    for(auto E: Respuesta) cout<<E.x<<" "<<E.y<<"\n";
    return 0;
}