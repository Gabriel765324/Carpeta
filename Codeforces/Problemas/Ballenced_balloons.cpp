#include "bits/stdc++.h"
using namespace std;
long long m = 998244353;
struct Menta{
    long long v;
    Menta(long long a){
        v = a % m;
    }
    Menta operator+(Menta a){
        return Menta(v % m + a.v % m);
    }
    Menta operator-(Menta a){
        return Menta(Menta(v % m - a.v % m).v + m);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    Menta r = Menta(0);
    vector< pair<int, Menta> > Valores = {{-222222, Menta(0)}, {0, Menta(1)}};
    for(int i = 0; i < k; i++){
        vector< pair<int, Menta> > Nuevo = {{-222222, Menta(0)}};
        for(int j = i + 1; j <= (i + 1) * k; j += i + 1){
            int Izquierda = 0, Derecha = Valores.size() - 1, m1, m2;
            while(1){
                int Promedio = (Izquierda + Derecha) / 2;
                if(Valores[Promedio].first < j){
                    m2 = Promedio;
                    Izquierda = Promedio + 1;
                } else Derecha = Promedio - 1;
                if(Izquierda >= Derecha + 1) break;
            }
            Izquierda = 0, Derecha = m2 - 1;
            while(1){
                int Promedio = (Izquierda + Derecha) / 2;
                if(Valores[Promedio].first < j - k){
                    m1 = Promedio;
                    Izquierda = Promedio + 1;
                } else Derecha = Promedio - 1;
                if(Izquierda >= Derecha + 1) break;
            }
            //cerr<<Valores[m2 + 1].first<<" "<<Valores[m1].first<<" "<<j<<"\n";
            Nuevo.push_back({j, Valores[m2].second - Valores[m1].second});
        }
        for(int j = 1; j < Nuevo.size(); j++){
            Nuevo[j].second = Nuevo[j].second + Nuevo[j - 1].second;
        }
        if(i + 1 == n or i == k - 1){
            cout<<Nuevo.back().second.v;
            return 0;
        }
        Valores = Nuevo;
    }
    return 0;
}