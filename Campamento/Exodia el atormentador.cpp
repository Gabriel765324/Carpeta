#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("Exodia.out", "w", stdout);
    long long n;
    cin>>n;
    map<long long, long long> Distancias, Padres;
    deque<long long> Cola = {n};
    Distancias[n] = 1;
    bool Continuar = 1;
    while(!Cola.empty() and Continuar){
        long long Nodo = Cola[0];
        Cola.pop_front();
        //cout<<Nodo<<" "<<Distancias[Nodo]<<"\n";
        if(Nodo == 1) break;
        long long Nuevo = 2 * Nodo;
        //cout<<Nuevo<<"\n";
        if(Distancias.count(Nuevo) == 0){
            Distancias[Nuevo] = Distancias[Nodo] + 1;
            Cola.push_back(Nuevo);
            Padres[Nuevo] = Nodo;
            if(Nuevo == 1){
                Continuar = 0;
                break;
            }
        }
        if(!Continuar) break;
        Nuevo = Nodo + 1;
        //cout<<Nuevo<<"\n";
        if(Distancias.count(Nuevo) == 0){
            Distancias[Nuevo] = Distancias[Nodo] + 1;
            Cola.push_back(Nuevo);
            Padres[Nuevo] = Nodo;
            if(Nuevo == 1){
                Continuar = 0;
                break;
            }
        }
        if(!Continuar) break;
        Nuevo = Nodo - 1;
        //cout<<Nuevo<<"\n";
        if(Distancias.count(Nuevo) == 0){
            Distancias[Nuevo] = Distancias[Nodo] + 1;
            Cola.push_back(Nuevo);
            Padres[Nuevo] = Nodo;
            if(Nuevo == 1){
                Continuar = 0;
                break;
            }
        }
        if(!Continuar) break;
        for(Nuevo = Nodo; Nuevo % 3 == 0; ){
            Nuevo /= 3;
            //cout<<Nuevo<<"\n";
            if(Distancias.count(Nuevo) == 0){
                Distancias[Nuevo] = Distancias[Nodo] + 1;
                Cola.push_back(Nuevo);
                Padres[Nuevo] = Nodo;
                if(Nuevo == 1){
                    Continuar = 0;
                    break;
                }
            }
        }
        if(!Continuar) break;
    }
    cout<<Distancias[1]<<"\n";
    /*deque<long long> a;
    for(long long p = 1; p != n; p = Padres[p]){
        a.push_front(p);
    }
    a.push_front(n);
    for(auto E: a) cout<<E<<" ";*/
    return 0;
}