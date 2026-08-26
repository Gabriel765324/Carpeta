#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n), ca;
    for(int i = 0; i < n; i++) cin>>a[i];
    vector<bool> M_scara(n);
    bool Cambio = 0;
    for(int i = 0; i < n; i++) M_scara[i] = i & 1;
    int Hasta = round(log2(n)), Menor = 0;
    swap(a, ca);
    for(int i = 0; i < n; i++){
        Posiciones[a[i]] = i;
    }
    for(int i = 0; i < n; i++){
        if(a[i] != i){
            Posible++;
            int Anterior = Posiciones[i];
            a[Anterior] = a[i];
            a[i] = i;
            Posiciones[i] = i;
            Posiciones[a[Anterior]] = Anterior;
        }
    }
    for(int i = round(log2(n)) - 1; i > -1; i--){
        /*cerr<<i<<"\n";
        for(auto E: M_scara) cerr<<E<<" ";
        cerr<<"\n";*/
        vector<bool> Usar(n), No_usar(n);
        for(int j = 0; j < n; j++){
            Usar[j] = (a[j] & (1<<i)) ? 0 : 1;
            No_usar[j] = !Usar[j];
        }
        int c1 = 0, c0 = 0;
        for(int j = 0; j < n; j++){
            c1 += Usar[j] != M_scara[j] ? 1 : 0;
            c0 += No_usar[j] != M_scara[j] ? 1 : 0;
        }
        if(c1 < c0){
            for(int j = 0; j < n; j++){
                a[j] ^= (1<<i);
            }
            Cambio = 1;
        } else swap(Usar, No_usar);
        if(i == 0) break;
        int t0 = 1<<(i - 1), t1 = 1<<(i - 1);
        bool v0 = 0, v1 = 0;
        for(int j = 0; j < n; j++){
            if(Usar[j] == 0){
                M_scara[j] = v0;
                t0--;
                if(t0 == 0){
                    t0 = 1<<(i - 1);
                    v0 = !v0;
                }
            } else {
                M_scara[j] = v1;
                t1--;
                if(t1 == 0){
                    t1 = 1<<(i - 1);
                    v1 = !v1;
                }
            }
        }
    }
    return 0;
}