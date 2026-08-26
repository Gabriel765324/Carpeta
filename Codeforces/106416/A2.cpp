#include "bits/stdc++.h"
using namespace std;
long long Distanciar(long long a, long long b, long long l, bool Sentido){
    if(Sentido) return ((b - a) % l + l) % l;
    else return ((a - b) % l + l) % l;;
}
struct Rango{
    long long i, f, l;
    bool Sentido;
    Rango(long long I, long long F, long long L, bool S){
        i = I;
        f = F;
        l = L;
        Sentido = S;
        if(Sentido and i > f){
            i -= l;
        }
        if(!Sentido){
            if(i < f){
                i += l;
            }
        }
    }
    bool Contiene(const Rango& a){
        if(Sentido == a.Sentido){
            if(Sentido){
                return (i <= a.i and a.f <= f) or (a.i <= i and f <= a.f);
            } else {
                return (i >= a.i and a.f >= f) or (a.i >= i and f >= a.f);
            }
        } else {
            long long ni = (i % l + l) % l, nf = (f % l + l) % l, nai = (a.i % l + l) % l, naf = (a.f % l + l) % l;
            if(a.Sentido){
                for(auto E: {ni, nf}){
                    if(E == -2LL) continue;
                    if(nai <= E and E <= naf) return 1;
                }
            } else {
                for(auto E: {ni, nf}){
                    if(E == -2LL) continue;
                    if(nai >= E and E >= naf) return 1;
                }
            }
            if(Sentido){
                for(auto E: {nai, naf}){
                    if(E == -2LL) continue;
                    if(ni <= E and E <= nf) return 1;
                }
            } else {
                for(auto E: {nai, naf}){
                    if(E == -2LL) continue;
                    if(ni >= E and E >= nf) return 1;
                }
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