#include "bits/stdc++.h"
using namespace std;
struct Punto{
    long long x, y;
    bool Vara;
    Punto(long long X, long long Y, bool V){
        x = X;
        y = Y;
        Vara = V;
    }
    long long Suma(const Punto& a){
        return (a.x - x) * (a.x - x) + (a.y - y) * (a.y - y);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long h, k, H, K;
    cin>>n>>h>>k;
    H = h * h;
    K = k * k;
    vector<int> Distancias(n, 22222);
    vector<Punto> a(n, Punto(0LL, 0LL, false));
    for(int i = 0; i < n; i++){
        long long x, y, v;
        cin>>x>>y>>v;
        a[i] = Punto(x, y, v == 1LL);
    }
    long long x, y;
    cin>>x>>y;
    queue<int> Cola;
    for(int i = 0; i < n; i++){
        if(a[i].x == x and a[i].y == y){
            Distancias[i] = 0;
            Cola.push(i);
        }
    }
    while(!Cola.empty()){
        int Nodo = Cola.front(), Distancia = Distancias[Nodo] + 1;
        Cola.pop();
        //cerr<<a[Nodo].x<<" "<<a[Nodo].y<<"\n";
        if(a[Nodo].y == 0){
            cout<<Distancia - 1;
            return 0;
        }
        if(a[Nodo].Vara){
            if(-a[Nodo].y <= h){
                cout<<Distancia;
                return 0;
            }
            for(int i = 0; i < n; i++){
                if(Distancias[i] <= Distancia + 1) continue;
                //cerr<<a[i].x<<" "<<a[i].y<<" "<<a[Nodo].Suma(a[i])<<" "<<a[i<<"\n";
                if(a[Nodo].Suma(a[i]) <= H){
                    Distancias[i] = Distancia;
                    Cola.push(i);
                } else if(a[i].Vara and a[Nodo].Suma(a[i]) <= K){
                    Distancias[i] = Distancia;
                    Cola.push(i);
                }
            }
        } else {
            for(int i = 0; i < n; i++){
                if(Distancias[i] <= Distancia + 1) continue;
                //cerr<<a[i].x<<" "<<a[i].y<<" "<<a[Nodo].Suma(a[i])<<"\n";
                if(a[i].Vara and a[Nodo].Suma(a[i]) <= K){
                    Distancias[i] = Distancia;
                    Cola.push(i);
                }
            }
        }
    }
    cout<<-1;
    return 0;
}