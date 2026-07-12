#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector< bitset<2222> > a(2222);
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        vector<string> Matriz(n);
        for(int i = 0; i < n; i++){
            cin>>Matriz[i];
            for(int j = 0; j < m; j++){
                a[i][j] = Matriz[i][j] == '#';
            }
        }
        bool Seguir = 1;
        for(int i = 0; i < n and Seguir; i++){
            for(int j = 0; j < m and Seguir; j++){
                if(!a[i][j]) continue;
                int Izquierda = 1, Derecha = 1, Arriba = 1, Abajo = 1;
                for(int p = 0; p < k; p++){
                    if(!a[i + p][j]) Izquierda = 0;
                    if(!a[i + k - 1][j + p]) Abajo = 0;
                    if(!a[i + p][j + k - 1]) Derecha = 0;
                    if(!a[i][j + p]) Arriba = 0;
                }
                if(Izquierda + Derecha + Arriba + Abajo != 3){
                    Seguir = 0;
                    break;
                }
                for(int p = 0; p < k; p++){
                    if(Izquierda != 0) a[i + p][j] = 0;
                    if(Abajo != 0) a[i + k - 1][j + p] = 0;
                    if(Derecha != 0) a[i + p][j + k - 1] = 0;
                    if(Arriba != 0) a[i][j + p] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = 0;
            }
        }
        if(Seguir) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}