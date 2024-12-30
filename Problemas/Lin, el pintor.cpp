#include "bits/stdc++.h"
using namespace std;
struct Consulta{
    long long t, i, c;
};
vector<long long> h, v, _rbolh, _rbolv, Jajah, Jajav;
void Crearh(long long i, long long d, long long p){
    if(i == d){
        _rbolh[p] = h[i];
        Jajah[i] = p;
        return;
    }
    long long P = (i + d) / 2;
    Crearh(i, P, p * 2);
    Crearh(P + 1, d, p * 2 + 1);
    _rbolh[p] = _rbolh[p * 2] + _rbolh[p * 2 + 1];
}
long long Consultah(long long i, long long d, long long p, long long I, long long D){
    if(i >= I and d <= D) return _rbolh[p];
    if(i > D or d < I) return 0;
    long long P = (i + d) / 2;
    return Consultah(i, P, p * 2, I, D) + Consultah(P + 1, d, p * 2 + 1, I, D);
}
void Actualizarh(long long p, long long o){
    //cout<<p<<" h\n";
    if(p == 0) return;
    if(p == o) _rbolh[p] = 0;
    else _rbolh[p] = _rbolh[p * 2] + _rbolh[p * 2 + 1];
    Actualizarh(p / 2, o);
}
void Crearv(long long i, long long d, long long p){
    if(i == d){
        _rbolv[p] = v[i];
        Jajav[i] = p;
        return;
    }
    long long P = (i + d) / 2;
    Crearv(i, P, p * 2);
    Crearv(P + 1, d, p * 2 + 1);
    _rbolv[p] = _rbolv[p * 2] + _rbolv[p * 2 + 1];
}
long long Consultav(long long i, long long d, long long p, long long I, long long D){
    if(i >= I and d <= D) return _rbolv[p];
    if(i > D or d < I) return 0;
    long long P = (i + d) / 2;
    return Consultav(i, P, p * 2, I, D) + Consultav(P + 1, d, p * 2 + 1, I, D);
}
void Actualizarv(long long p, long long o){
    //cout<<p<<" v\n";
    if(p == 0) return;
    if(p == o) _rbolv[p] = 0;
    else _rbolv[p] = _rbolv[p * 2] + _rbolv[p * 2 + 1];
    Actualizarv(p / 2, o);
}
int main(){
    //freopen("01.in", "r", stdin);
    //freopen("01.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long f, c, q;
    cin>>f>>c>>q;
    vector<Consulta> Consultas(q);
    h.assign(f, 1);
    Jajah.assign(f, -2);
    _rbolh.assign(f * 4 + 22, 0);
    v.assign(c, 1);
    Jajav.assign(c, -2);
    _rbolv.assign(c * 4 + 22, 0);
    for(long long i = 0; i < q; i++){
        cin>>Consultas[q - i - 1].t>>Consultas[q - i - 1].i>>Consultas[q - i - 1].c;
        Consultas[q - i - 1].i--;
    }
    f--;
    c--;
    Crearh(0, f, 1);
    Crearv(0, c, 1);
    map<long long, long long> Colores;
    set<long long> Colores_que_tenemos;
    for(long long i = 0; i < q; i++){
        Consulta a = Consultas[i];
        //cout<<a.t<<" "<<a.i<<" "<<a.c<<"\n";
        if(a.t == 1 and h[a.i] == 1){
            h[a.i] = 0;
            Actualizarh(Jajah[a.i], Jajah[a.i]);
            Colores_que_tenemos.insert(a.c);
            Colores[a.c] += Consultav(0, c, 1, 0, c);
            if(Consultav(0, c, 1, 0, c) == 0) break;
            //cout<<Consultav(0, c, 1, 0, c);
        } else if(a.t == 2 and v[a.i] == 1){
            v[a.i] = 0;
            Actualizarv(Jajav[a.i], Jajav[a.i]);
            Colores_que_tenemos.insert(a.c);
            Colores[a.c] += Consultah(0, f, 1, 0, f);
            if(Consultah(0, f, 1, 0, f) == 0) break;
            //cout<<Consultah(0, f, 1, 0, f);
        }
        //cout<<"\n";
        /*for(auto E: _rbolh) cout<<E<<" ";
        cout<<"\n";
        for(auto E: _rbolv) cout<<E<<" ";
        cout<<"\n";*/
    }
    long long Suma = 0;
    f++;
    c++;
    for(auto E: Colores_que_tenemos){
        Suma += Colores[E];
    }
    Colores[0] += f * c - Suma;
    Colores_que_tenemos.insert(0);
    long long Cantidad_de_colores = 0;
    for(auto E: Colores_que_tenemos){
        if(Colores[E] > 0){
            Cantidad_de_colores++;
        }
    }
    cout<<Cantidad_de_colores<<"\n";
    for(auto E: Colores_que_tenemos){
        if(Colores[E] > 0){
            cout<<E<<" "<<Colores[E]<<"\n";
        }
    }
    /////////
    /*vector< vector<long long> > Tablero(f, vector<long long>(c, 0));
    map<long long, long long> Colorcitos;
    set<long long> Tenemos;
    Colorcitos[0] = f * c;
    Tenemos.insert(0);
    for(long long aaa = q - 1; aaa > -1; aaa--){
        long long t, i, co;
        t = Consultas[aaa].t;
        i = Consultas[aaa].i;
        co = Consultas[aaa].c;
        if(t == 1){
            for(long long j = 0; j < c; j++){
                Colorcitos[Tablero[i][j]]--;
                if(Colorcitos[Tablero[i][j]] == 0) Tenemos.erase(Tablero[i][j]);
                Tablero[i][j] = co;
                Colorcitos[co]++;
                Tenemos.insert(co);
                //cout<<j<<" ";
            }
        } else {
            for(long long j = 0; j < f; j++){
                Colorcitos[Tablero[j][i]]--;
                if(Colorcitos[Tablero[j][i]] == 0) Tenemos.erase(Tablero[j][i]);
                Tablero[j][i] = co;
                Colorcitos[co]++;
                Tenemos.insert(co);
                //cout<<j<<" ";
            }
        }
    }
    for(auto E: Tenemos){
        cout<<E<<" "<<Colorcitos[E]<<"\n";
    }*/
    return 0;
}