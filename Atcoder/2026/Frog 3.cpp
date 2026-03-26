#include "bits/stdc++.h"
using namespace std;
struct Recta{
    long long Pendiente, Inicio;
};
long long Evaluar(long long x, Recta r){
    return r.Pendiente * x + r.Inicio;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long c;
    cin>>n>>c;
    vector<long long> a(n), PD(n, 4e12);
    for(int i = 0; i < n; i++) cin>>a[i];
    deque<Recta> Rectas;
    PD[0] = 0;
    Recta Inicio;
    Inicio.Inicio = a[0] * a[0];
    Inicio.Pendiente = -2 * a[0];
    Rectas.push_back(Inicio);
    for(int i = 1; i < n; i++){
        while(Rectas.size() > 1){
            if(Evaluar(a[i], Rectas[0]) > Evaluar(a[i], Rectas[1])){
                Rectas.pop_front();
            } else {
                break;
            }
        }
        PD[i] = Evaluar(a[i], Rectas[0]) + c + a[i] * a[i];
        Recta Nuevo;
        Nuevo.Pendiente = -2 * a[i];
        Nuevo.Inicio = PD[i] + a[i] * a[i];
        Rectas.push_back(Nuevo);
        //for(auto E: Rectas) cerr<<E<<" ";
        //cerr<<PD[i]<<" ";
    }
    //cerr<<"\n";
    cout<<PD.back();
    return 0;
}