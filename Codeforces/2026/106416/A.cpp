#include "bits/stdc++.h"
using namespace std;
long long Distanciar(long long a, long long b, long long l, bool Sentido){
    if(a == b) return 0;
    if(a < b){
        if(Sentido) return b - a;
        else return l - b + a;
    } else {
        if(Sentido) return l - b + a;
        else return b - a;
    }
}
struct Rango{
    long long i, f, l, i0, f0;
    bool Sentido;
    Rango(long long I, long long F, long long L, bool S){
        i = I;
        f = F;
        l = L;
        Sentido = S;
        i0 = -2LL;
        f0 = -2LL;
        if(Sentido and i > f){
            f0 = f;
            f = l - 1LL;
            i0 = 0LL;
        }
        if(!Sentido){
            if(i < f){
                i0 = 0LL;
                f0 = i;
                i = f;
                f = l - 1LL;
            }
        }
    }
    bool Contiene(const Rango& a){
        if(Sentido == a.Sentido){
            if(Distanciar(i, (f0 == -2LL ? f : f0), l, Sentido) == Distanciar(a.i, (a.f0 == -2LL ? a.f : a.f0), a.l, a.Sentido)) return 0;
            if(Distanciar(i, (f0 == -2LL ? f : f0), l, Sentido) < Distanciar(a.i, (a.f0 == -2LL ? a.f : a.f0), a.l, a.Sentido)){
                long long Inicio = i, Final = (f0 == -2LL ? f : f0);
                if((a.i <= Inicio and Inicio <= a.f) or (a.i0 <= Inicio and Inicio <= a.f0)){
                    if((a.i <= Final and Final <= a.f) or (a.i0 <= Final and Final <= a.f0)){
                        return 1;
                    } else {
                        return 0;
                    }
                }
                return 0;
            } else if(Distanciar(i, (f0 == -2LL ? f : f0), l, Sentido) > Distanciar(a.i, (a.f0 == -2LL ? a.f : a.f0), a.l, a.Sentido)){
                long long Inicio = a.i, Final = (a.f0 == -2LL ? a.f : a.f0);
                if((i <= Inicio and Inicio <= f) or (i0 <= Inicio and Inicio <= f0)){
                    if((i <= Final and Final <= f) or (i0 <= Final and Final <= f0)){
                        return 1;
                    } else {
                        return 0;
                    }
                }
                return 0;
            }
        } else {
            for(auto E: {i, f, i0, f0}){
                if(E == -2LL) continue;
                if(a.i <= E and E <= a.f) return 1;
                if(a.i0 <= E and E <= a.f0 and a.i0 != -2LL) return 1;
            }
            for(auto E: {a.i, a.f, a.i0, a.f0}){
                if(E == -2LL) continue;
                if(i <= E and E <= f) return 1;
                if(i0 <= E and E <= f0 and i0 != -2LL) return 1;
            }
            return 0;
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long Respuesta = LLONG_MAX, Posible = 0, l;
    cin>>n>>l;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]--;
    }
    for(int i = 0; i < n; i++){
        cin>>b[i];
        b[i]--;
    }
    Posible = Distanciar(a[0], b[0], l, 1);
    vector<Rango> Rangos;
    Rangos.push_back(Rango(a[0], b[0], l, 1));
    bool Seguir = 1;
    /*for(auto E: a) cerr<<E<<" ";
    cerr<<"\n";
    for(auto E: b) cerr<<E<<" ";
    cerr<<"\n";*/
    //cerr<<Rangos[0].i<<" "<<Rangos[0].f<<" "<<Rangos[0].i0<<" "<<Rangos[0].f0<<" "<<Rangos[0].Sentido<<"\n";
    for(int i = 1; i < n and Seguir; i++){
        Rango Actual = Rango(a[i], b[i], l, 1);
        if(Actual.Contiene(Rangos[0]) or Rangos[0].Contiene(Actual)){
            Actual = Rango(a[i], b[i], l, 0);
            Posible = max(Posible, Distanciar(a[i], b[i], l, 0));
        } else {
            Posible = max(Posible, Distanciar(a[i], b[i], l, 1));
        }
        //cerr<<Actual.i<<" "<<Actual.f<<" "<<Actual.i0<<" "<<Actual.f0<<" "<<Actual.Sentido<<" Actual.\n";
        Rangos.push_back(Actual);
        if(Actual.Contiene(Rangos[0]) or Rangos[0].Contiene(Actual)){
            Posible = LLONG_MAX;
            //cerr<<"Mal.\n";
            break;
        }
        for(int j = 1; j < i; j++){
            if(Actual.Contiene(Rangos[j]) or Rangos[j].Contiene(Actual)){
                Posible = LLONG_MAX;
                Seguir = 0;
                //cerr<<"Mal.\n";
                break;
            }
        }
    }
    Rangos.clear();
    Respuesta = min(Respuesta, Posible);
    Posible = Distanciar(a[0], b[0], l, 0);
    Seguir = 1;
    Rangos.push_back(Rango(a[0], b[0], l, 0));
    //cerr<<Rangos[0].i<<" "<<Rangos[0].f<<" "<<Rangos[0].i0<<" "<<Rangos[0].f0<<" "<<Rangos[0].Sentido<<"\n";
    for(int i = 1; i < n and Seguir; i++){
        Rango Actual = Rango(a[i], b[i], l, 1);
        if(Actual.Contiene(Rangos[0]) or Rangos[0].Contiene(Actual)){
            Actual = Rango(a[i], b[i], l, 0);
            Posible = max(Posible, Distanciar(a[i], b[i], l, 0));
        } else {
            Posible = max(Posible, Distanciar(a[i], b[i], l, 1));
        }
        //cerr<<Actual.i<<" "<<Actual.f<<" "<<Actual.i0<<" "<<Actual.f0<<" "<<Actual.Sentido<<" Actual.\n";
        Rangos.push_back(Actual);
        if(Actual.Contiene(Rangos[0]) or Rangos[0].Contiene(Actual)){
            Posible = LLONG_MAX;
            //cerr<<"Mal.\n";
            break;
        }
        for(int j = 1; j < i; j++){
            if(Actual.Contiene(Rangos[j]) or Rangos[j].Contiene(Actual)){
                Posible = LLONG_MAX;
                Seguir = 0;
                //cerr<<"Mal.\n";
                break;
            }
        }
    }
    Respuesta = min(Respuesta, Posible);
    if(Respuesta == LLONG_MAX) cout<<"*\n";
    else cout<<Respuesta<<"\n";
    return 0;
}