#include "bits/stdc++.h"
using namespace std;
const int MAYOR = 1e5 + 22;
int Salto[MAYOR] = {};
int Siguiente[MAYOR] = {};
int Contador[MAYOR] = {};
int _ltimo[MAYOR] = {};
int Divisiones[MAYOR] = {};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin>>n>>m;
    k = sqrt(n);
    for(int i = 0; i < n; i++) cin>>Salto[i];
    for(int i = n - 1; i > -1; i--){
        Divisiones[i] = i / k;
        if(i + Salto[i] >= n){
            Siguiente[i] = n;
            Contador[i] = 1;
            _ltimo[i] = i;
            continue;
        }
        if(Divisiones[i] == Divisiones[i + Salto[i]]){
            Siguiente[i] = Siguiente[i + Salto[i]];
            Contador[i] = Contador[i + Salto[i]] + 1;
            _ltimo[i] = _ltimo[i + Salto[i]];
            continue;
        }
        Siguiente[i] = i + Salto[i];
        Contador[i] = 1;
        _ltimo[i] = i;
    }
    while(m--){
        int t;
        cin>>t;
        if(t == 1){
            int a;
            cin>>a;
            int Pasos = 0, Final, Hoyo = a - 1;
            while(Hoyo < n){
                Pasos += Contador[Hoyo];
                Final = _ltimo[Hoyo];
                Hoyo = Siguiente[Hoyo];
            }
            cout<<Final + 1<<" "<<Pasos<<"\n";
        } else {
            int i, b, ci;
            cin>>i>>b;
            i--;
            Salto[i] = b;
            ci = (i / k) * k;
            for(; i >= ci; i--){
                if(i + Salto[i] >= n){
                    Siguiente[i] = n;
                    Contador[i] = 1;
                    _ltimo[i] = i;
                } else if(Divisiones[i] == (i + Salto[i]) / k){
                    Siguiente[i] = Siguiente[i + Salto[i]];
                    Contador[i] = Contador[i + Salto[i]] + 1;
                    _ltimo[i] = _ltimo[i + Salto[i]];
                } else {
                    Siguiente[i] = i + Salto[i];
                    Contador[i] = 1;
                    _ltimo[i] = i;
                }
            }
        }
    }
    return 0;
}//