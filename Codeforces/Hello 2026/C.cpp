#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        int r = 1;
        for(int i = 0; i <= n; i++){
            /*int Tiempo = m - i + 1, Posible1 = 1, Posible2 = 1;
            if(Tiempo == 0) break;
            Posible1 += min(min(i, Tiempo), k - 1);
            Tiempo -= min(min(i, Tiempo), k - 1);
            Tiempo /= 2;
            Posible1 += min(Tiempo + i, n - k);
            Tiempo = m - i + 1;
            Posible2 += min(min(i, Tiempo), n - k);
            Tiempo -= min(min(i, Tiempo), n - k);
            Tiempo /= 2;
            Posible2 += min(Tiempo + i, k - 1);
            r = max(r, max(Posible1, Posible2));*/
            int Posible1 = 1, Posible2 = 1, Soldados = i + 1, Tiempo = m - i;
            if(Tiempo == 0) break;
            Posible1 += min(Soldados, min(Tiempo, k - 1));
            Tiempo -= min(Soldados, min(Tiempo, k - 1));
            if(Tiempo > 0){
                int Mejor = min(min(Tiempo, Soldados), n - k);
                Tiempo -= Soldados;
                if(Tiempo > 0){
                    Tiempo /= 2;
                    Mejor = max(Mejor, min(Soldados + Tiempo, n - k));
                }
                Posible1 += Mejor;
            }
            Tiempo = m - i;
            Posible2 += min(Soldados, min(Tiempo, n - k));
            Tiempo -= min(Soldados, min(Tiempo, n - k));
            if(Tiempo > 0){
                int Mejor = min(min(Tiempo, Soldados), k - 1);
                Tiempo -= Soldados;
                if(Tiempo > 0){
                    Tiempo /= 2;
                    Mejor = max(Mejor, min(Soldados + Tiempo, k - 1));
                }
                Posible2 += Mejor;
            }
            //cout<<Soldados<<" "<<Posible1<<" "<<Posible2<<"\n";
            r = max(r, max(Posible1, Posible2));
        }
        cout<<r<<"\n";
    }
    return 0;
}