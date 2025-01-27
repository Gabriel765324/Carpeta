#include "bits/stdc++.h"
using namespace std;
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cerr<<"Inicio.\n";
    long long n;
    cin>>n;
    cerr<<"Bien.\n";
    vector<long long> a(n), b(n);
    map<long long, vector< pair<long long, long long> > > Cuenta, Suma;
    for(long long i = 0; i < n; i++) cin>>a[i];
    cerr<<"Bien.\n";
    for(long long i = 0; i < n; i++){
        cin>>b[i];
        Cuenta[b[i]].push_back({i, n - i - 1});
    }
    cerr<<"Bien.\n";
    for(long long i = 1; i <= n; i++){
        for(long long j = 0; j < Cuenta[i].size(); j++){
            Suma[i][j].second = Cuenta[i][j].second;
            if(j > 0) Suma[i][j].second += Suma[i][j - 1].second;
        }
        for(long long j = Cuenta[i].size() - 1; j > -1; j--){
            Suma[i][j].first = Cuenta[i][j].first;
            if(j < Cuenta[i].size() - 1) Suma[i][j].first += Suma[i][j + 1].first;
        }
    }
    long long s = 0;
    for(long long i = 0; i < n; i++){
        if(Cuenta[a[i]].size() == 0) continue;
        long long d = min(i, n - i - 1);
        if(a[i] == b[i]) s += d + 1 + (i * (i + 1) + (n - i - 1) * (n - i)) / 2;
        long long Izquierda = 0, Derecha = Cuenta[a[i]].size() - 1, Mejor = Izquierda, p = Izquierda;
        //long long p = lower_bound(Cuenta[a[i]].begin(), Cuenta[a[i]].end(), make_pair(i, -0)) - Cuenta[a[i]].begin();
        while(Izquierda >= Derecha){
            long long Promedio = (Izquierda + Derecha) / 2;
            if(Cuenta[a[i]][Promedio].first <= i){
                if(Izquierda == Derecha and Izquierda == Cuenta[a[i]].size() - 1){
                    p++;
                    break;
                }
                Izquierda = Promedio + 1;
                p = Promedio;
            } else {
                Derecha = Promedio - 1;
            }
        }
        /*if(p < Cuenta[a[i]].size()){
            if(Cuenta[a[i]][p].first == i) p--;
        }
        bool Existe = 1;
        Izquierda = 0, Derecha = p, Mejor = p + 1;
        while(Izquierda <= Derecha){
            long long Promedio = (Izquierda + Derecha) / 2;
            if(Cuenta[a[i]][Promedio].first >= n - i - 1){
                Derecha = Promedio - 1;
                Mejor = Promedio;
            } else {
                if(Izquierda == Derecha and Derecha == p) Existe = 0;
                Izquierda = Promedio + 1;
            }
        }
        if(Existe){
            s += Mejor * (n - i - 1) + Suma[a[i]][0].first;
            if(Mejor < Suma[a[i]].size() and Mejor > -1) s -= Suma[a[i]][Mejor].first;
        } else s += p * (n - i - 1);
        p++;
        if(p < Cuenta[a[i]].size()){
            if(Cuenta[a[i]][p].first == i) p++;
        }
        Existe = 1;
        Izquierda = p, Derecha = Cuenta[a[i]].size() - 1, Mejor = p - 1;
        while(Izquierda <= Derecha){
            long long Promedio = (Izquierda + Derecha) / 2;
            if(Cuenta[a[i]][Promedio].second >= i){
                Izquierda = Promedio + 1;
                Mejor = Promedio;
            } else {
                if(Izquierda == Derecha and Derecha == p) Existe = 0;
                Derecha = Promedio - 1;
            }
        }
        if(Existe){
            s += Mejor * i + Suma[a[i]].back().second;
            if(Mejor < Suma[a[i]].size() and Mejor > -1) s -= Suma[a[i]][Mejor].second;
        } else s += (Suma[a[i]].size() - p - 1) * i; //Quitar el -1 si falla.*/
    }
    cout<<s;
    return 0;
}