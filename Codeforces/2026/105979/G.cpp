#include "bits/stdc++.h"
#include "iomanip"
using namespace std;
struct Punto{
    __int128 x, y;
    Punto(__int128 X, __int128 Y){
        x = X;
        y = Y;
    }
    Punto operator-(const Punto& a){
        return Punto(x - a.x, y - a.y);
    }
    int Orientaci_n(const Punto& a, const Punto& b){
        Punto a0 = a, b0 = b;
        a0 = a0 - Punto(x, y);
        b0 = b0 - Punto(x, y);
        __int128 Producto = (a0.x * b0.y) - (a0.y * b0.x);
        if(Producto > 0) return 1;
        if(Producto == 0) return 0;
        return -1;
    }
    __int128 Distancia(const Punto& a){
        return (a.x - x) * (a.x - x) + (a.y - y) * (a.y - y);
    }
    bool operator<(const Punto& a)const{
        if(y < a.y) return 1;
        if(a.y < y) return 0;
        return x < a.x;
    }
    bool operator!=(const Punto& a){
        return x != a.x or y != a.y;
    }
};
Punto Referencia = Punto(0, 0);
bool Orden(const Punto& a, const Punto& b){
    int o = Referencia.Orientaci_n(a, b);
    if(o == 0) return Referencia.Distancia(a) < Referencia.Distancia(b);
    return o == -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    __int128 h, r;
    long double Copia;
    cin>>n>>Copia;
    h = round(Copia * (long double)100);
    r = h;
    __int128 Menor = 0;
    vector< pair<Punto, __int128> > a;
    set< pair< Punto, pair<__int128, int> > > s;
    for(int i = 0; i < n; i++){
        __int128 x, y, z;
        long double X, Y, Z;
        cin>>X>>Y>>Z;
        x = round(X * (long double)100);
        y = round(Y * (long double)100);
        z = round(Z * (long double)100);
        Menor = min(Menor, z);
        auto E = s.lower_bound(make_pair(Punto(x, y), make_pair((__int128)-2222222222222222, -2)));
        if(E == s.end() or Punto(x, y) != Punto(E->first.x, E->first.y)){
            s.insert(make_pair(Punto(x, y), make_pair(z, i)));
            a.push_back(make_pair(Punto(x, y), z));
            /*cerr<<"Extra: "<<(long long)x<<" "<<(long long)y<<" ";
            if(E != s.end()) cerr<<(long long)E->first.x<<" "<<(long long)E->first.y;
            cerr<<"\n";*/
        } else if(E != s.end()){
            /*cerr<<"No extra: "<<(long long)x<<" "<<(long long)y<<" ";
            cerr<<(long long)E->first.x<<" "<<(long long)E->first.y;
            cerr<<"\n";*/
            if(E->second.first < z){
                pair< Punto, pair<__int128, int> > Nuevo = *E;
                s.erase(E);
                Nuevo.second.first = z;
                s.insert(Nuevo);
                a[Nuevo.second.second].second = Nuevo.second.first;
            }
        }
    }
    __int128 I = 0, D = h - Menor + (__int128)22222222222222222, x0, y0;
    r = D;
    long double X0, Y0;
    cin>>X0>>Y0;
    x0 = round(X0 * (long double)100);
    y0 = round(Y0 * (long double)100);
    bool Uno_v_lido = 0;
    while(I < D + (__int128)1){
        vector<Punto> Actual;
        __int128 p = (I + D) / (__int128)2;
        //cerr<<(long long)p<<"\n";
        for(int i = 0; i < n; i++){
            if(a[i].second >= h - p){
                //cerr<<(long long)a[i].first.x<<" "<<(long long)a[i].first.y<<"\n";
                Actual.push_back(a[i].first);
            }
        }
        //cerr<<"----------\n";
        if(Actual.size() < 3){
            //cerr<<"Falta de tamaño.\n";
            I = p + (__int128)1;
            continue;
        }
        Referencia = Actual[0];
        int Posici_n = 0;
        for(int i = 0; i < int(Actual.size()); i++){
            if(Actual[i] < Referencia){
                Referencia = Actual[i];
                Posici_n = i;
            }
        }
        vector<Punto> Pol_gono = {Referencia};
        Actual.erase(Actual.begin() + Posici_n);
        sort(Actual.begin(), Actual.end(), Orden);
        int Tama_o = int(Actual.size());
        bool Seguir = 0;
        for(int i = Tama_o - 2; i > -1; i--){
            if(Referencia.Orientaci_n(Actual.back(), Actual[i]) != 0){
                Seguir = 1;
                reverse(Actual.begin() + i + 1, Actual.end());
                break;
            }
        }
        if(!Seguir){
            //cerr<<"Solo hay puntos colineales.\n";
            I = p + (__int128)1;
            continue;
        }
        for(int i = 0; i < Tama_o; i++){
            if(Pol_gono.size() < 2){
                Pol_gono.push_back(Actual[i]);
                continue;
            }
            int Tama_o_del_pol_gono = int(Pol_gono.size());
            while(Pol_gono.size() >= 2 and Pol_gono[Tama_o_del_pol_gono - 2].Orientaci_n(Pol_gono.back(), Actual[i]) == 1){
                Tama_o_del_pol_gono--;
                Pol_gono.pop_back();
            }
            Pol_gono.push_back(Actual[i]);
        }
        bool Adentro = 1;
        for(int i = 0; i < int(Pol_gono.size()); i++){
            //cerr<<(long long)Pol_gono[i].x<<" "<<(long long)Pol_gono[i].y<<"\n";
            if(Pol_gono[i].Orientaci_n(Pol_gono[(i + 1) % int(Pol_gono.size())], Punto(x0, y0)) != -1){
                Adentro = 0;
            }
        }
        //cerr<<"----------\n";
        if(!Adentro){
            //cerr<<"La galleta está afuera.\n";
            I = p + (__int128)1;
            continue;
        }
        if(int(Pol_gono.size()) == 4){
            if(Pol_gono[0].Orientaci_n(Pol_gono[2], Punto(x0, y0)) == 0 and Pol_gono[1].Orientaci_n(Pol_gono[3], Punto(x0, y0)) == 0){
                //cerr<<"La galleta está en los bordes de los triángulos. :(\n";
                I = p + (__int128)1;
                continue;
            }
        }
        D = p - (__int128)1;
        r = p;
        Uno_v_lido = 1;
    }
    if(Uno_v_lido) cout<<fixed<<setprecision(22)<<(long double)r / (long double)100;
    else cout<<-1;
    return 0;
}