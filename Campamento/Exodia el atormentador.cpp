#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    map<long long, long long> Distancias;
    deque<long long> Cola = {n};
    Distancias[n] = -0;
    while(!Cola.empty()){
        long long Nodo = Cola[0];
        Cola.pop_front();
        if(Nodo == 1) break;
        for(long long Nuevo = 2 * Nodo; Nuevo <= 4000000; Nuevo *= 2){
            if(Distancias.count(Nuevo) == 0){
                Distancias[Nuevo] = Distancias[Nodo] + 1;
                Cola.push_back(Nuevo);
            }
        }
        long long Nuevo = Nodo + 1;
        if(Distancias.count(Nuevo) == 0){
            Distancias[Nuevo] = Distancias[Nodo] + 1;
            Cola.push_back(Nuevo);
        }
        Nuevo = Nodo - 1;
        if(Distancias.count(Nuevo) == 0){
            Distancias[Nuevo] = Distancias[Nodo] + 1;
            Cola.push_back(Nuevo);
        }
        for(Nuevo = Nodo; Nuevo % 3 == 0;){
            Nuevo /= 3;
            if(Distancias.count(Nuevo) == 0){
                Distancias[Nuevo] = Distancias[Nodo] + 1;
                Cola.push_back(Nuevo);
            }
        }
    }
    cout<<Distancias[1] + 1;
    return 0;
}