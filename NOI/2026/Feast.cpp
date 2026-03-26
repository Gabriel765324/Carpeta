#include "bits/stdc++.h"
using namespace std;
struct Datos{
    __int128 Valor, Penitencia, Error;
};
int main(){
    int n, k;
    cin>>n>>k;
    deque<__int128> a;
    for(int i = 0; i < n; i++){
        long long v;
        cin>>v;
        if(v == 0) continue;
        if(a.empty()) a.push_back((__int128)v);
        else if((a.back() < 0 and v < 0) or (a.back() > 0 and v > 0)) a.back() += (__int128)v;
        else a.push_back((__int128)v);
    }
    while(!a.empty() and a[0] < 0) a.pop_front();
    while(!a.empty() and a.back() < 0) a.pop_back();
    n = a.size();
    if(n == 0){
        cout<<0;
        return 0;
    }
    __int128 Izquierda = 0, Derecha = 22222222222222222, Respuesta = 0;
    while(Izquierda < Derecha + 1){
        __int128 Promedio = (Izquierda + Derecha) / (__int128)2;
        //cerr<<(long long)Promedio<<"\n";
        vector<Datos> __0;
        Datos _0;
        __0.push_back(_0);
        __0.push_back(_0);
        vector< vector<Datos> > PD;
        PD.push_back(__0);
        PD.push_back(__0);
        _0.Error = 0;
        _0.Penitencia = 0;
        _0.Valor = 0;
        PD[1][0] = _0;
        _0.Valor = a.back() - Promedio;
        _0.Penitencia = 1;
        PD[1][1] = _0;
        Respuesta = max(Respuesta, a.back());
        /*deque<Datos> Tengo;
        Tengo.push_front(PD[1][0]);
        Tengo.push_front(PD[1][1]);*/
        for(int i = n - 2; i > -1; i--){
            PD[0][0].Valor = max(PD[1][0].Valor, PD[1][1].Valor);
            if(PD[1][1].Valor > PD[1][0].Valor){
                PD[0][0].Penitencia = PD[1][1].Penitencia;
                PD[0][0].Error = PD[1][1].Error;
            } else if(PD[1][1].Valor < PD[1][0].Valor){
                PD[0][0].Penitencia = PD[1][0].Penitencia;
                PD[0][0].Error = PD[1][0].Error;
            } else {
                PD[0][0].Penitencia = min(PD[1][0].Penitencia, PD[1][1].Penitencia);
                PD[0][0].Error = abs(PD[1][0].Penitencia - PD[1][1].Penitencia) + max(PD[1][0].Error, PD[1][1].Error);
            }
            PD[0][1].Valor = max(PD[1][0].Valor - Promedio, PD[1][1].Valor) + a[i];
            if(PD[1][1].Valor > PD[1][0].Valor - Promedio){
                PD[0][1].Penitencia = PD[1][1].Penitencia;
                PD[0][1].Error = PD[1][1].Error;
            } else if(PD[1][1].Valor < PD[1][0].Valor - Promedio){
                PD[0][1].Penitencia = PD[1][0].Penitencia + 1;
                PD[0][1].Error = PD[1][0].Error;
            } else {
                PD[0][1].Penitencia = min(PD[1][0].Penitencia + 1, PD[1][1].Penitencia);
                PD[0][1].Error = abs(PD[1][0].Penitencia + 1 - PD[1][1].Penitencia) + max(PD[1][0].Error, PD[1][1].Error);
            }
            if(PD[0][0].Penitencia <= k) Respuesta = max(Respuesta, PD[0][0].Valor + Promedio * min(PD[0][0].Penitencia + PD[0][0].Error, (__int128)k));
            if(PD[0][1].Penitencia <= k) Respuesta = max(Respuesta, PD[0][1].Valor + Promedio * min(PD[0][1].Penitencia + PD[0][1].Error, (__int128)k));
            /*Tengo.push_front(PD[0][0]);
            Tengo.push_front(PD[0][1]);*/
            swap(PD[0], PD[1]);
        }
        //if((int)PD[1][0].Penitencia <= k and (int)PD[1][1].Penitencia <= k) Respuesta = max(Respuesta, max(PD[1][0].Valor + Promedio * PD[1][0].Penitencia, PD[1][1].Valor + Promedio * PD[1][1].Penitencia));
        /*for(int i = 1; i < Tengo.size(); i += 2) cerr<<(long long)Tengo[i].Valor<<" ";
        cerr<<"\n";
        for(int i = 0; i < Tengo.size(); i += 2) cerr<<(long long)Tengo[i].Valor<<" ";
        cerr<<"\n";
        for(int i = 1; i < Tengo.size(); i += 2) cerr<<(long long)Tengo[i].Penitencia<<" ";
        cerr<<"\n";
        for(int i = 0; i < Tengo.size(); i += 2) cerr<<(long long)Tengo[i].Penitencia<<" ";
        cerr<<"\n\n";*/
        //cerr<<(long long)PD[1][0].Valor + (long long)PD[1][0].Penitencia * (long long)Promedio<<" "<<(long long)PD[1][1].Valor + (long long)PD[1][1].Penitencia * (long long)Promedio<<"\n";
        if((int)max(PD[1][0].Penitencia, PD[1][1].Penitencia) <= k) Derecha = Promedio - 1;
        else Izquierda = Promedio + 1;
    }
    cout<<(long long)Respuesta;
    return 0;
}