#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define el "\n"
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
using namespace std;
/*int Tama_o(int i, int d){
    return 2 * (d - i + 1);
}
vi operator+(const vi& a, const vi& b){
    return {max(a[0], b[0]), min(a[1], b[1])};
}
vi Neutro = {INT_MIN, INT_MAX};
struct _rbol_de_segmentos{
    vector< vi > _rbol;
    int n;
    _rbol_de_segmentos(int N, vi& a, vi& b){
        n = N;
        _rbol.assign(n * 2 + 22, Neutro);
    }
    void Actualizar(int i, int d, int p, int u, int v){
        if(i == d and d == u){
            _rbol[p] = {v, v};
            return;
        }
        if(i > u or d < u) return;
        int P = (i + d) / 2;
        Actualizar(i, P, p + 1, u, v);
        Actualizar(P + 1, d, p + Tama_o(i, P), u, v);
        _rbol[p] = _rbol[p + 1] + _rbol[p + Tama_o(i, P)];
    }
    int Consulta(int i, int d, int p, int I, int D, int t){
        if(I <= i and d <= D) return _rbol[p][t];
        if(d < I or D < i) return Neutro[t];
        int P = (i + d) / 2;
        if(t == 0) return max(Consulta(i, P, p + 1, I, D, t), Consulta(P + 1, d, p + Tama_o(i, P), I, D, t));
        return min(Consulta(i, P, p + 1, I, D, t), Consulta(P + 1, d, p + Tama_o(i, P), I, D, t));
    }
};*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    n++;
    vi a(n, 0), b(n, 0);
    forsn(i, 1, n) cin>>a[i];
    forsn(i, 1, n) cin>>b[i];
    int Mejor = a.back(), Menor = INT_MAX;
    for(int i = n - 1; i > 0; i--){
        Menor = min(Menor, b[i]);
        Mejor = max(Mejor, min(Menor, a[i - 1]));
    }
    cout<<Mejor<<el;
    //_rbol_de_segmentos _rbol = _rbol_de_segmentos(n, a, b);
    /*vector< vector< vi > > PD(n, vector< vi >(2, vi(2, -2)));
    PD[n - 1][0][0] = b[n - 1];
    PD[n - 1][0][1] = a[n - 1];
    PD[n - 1][1][0] = a[n - 1];
    PD[n - 1][1][1] = b[n - 1];
    _rbol_de_segmentos Turno_0_Pasado_0;
    _rbol_de_segmentos Turno_0_Pasado_1;
    _rbol_de_segmentos Turno_1_Pasado_0;
    _rbol_de_segmentos Turno_1_Pasado_1;
    Turno_0_Pasado_0.Crear(n);
    Turno_0_Pasado_1.Crear(n);
    Turno_1_Pasado_0.Crear(n);
    Turno_1_Pasado_1.Crear(n);
    Turno_0_Pasado_0.Actualizar(0, n - 1, 0, n - 1, PD[n - 1][0][0]);
    Turno_0_Pasado_1.Actualizar(0, n - 1, 0, n - 1, PD[n - 1][0][1]);
    Turno_1_Pasado_0.Actualizar(0, n - 1, 0, n - 1, PD[n - 1][1][0]);
    Turno_1_Pasado_1.Actualizar(0, n - 1, 0, n - 1, PD[n - 1][1][1]);
    for(int i = n - 2; i > -1; i--){
        PD[i][0][1] = max(a[i], Turno_1_Pasado_0.Consulta(0, n - 1, 0, i + 1, n - 1, 0));
        PD[i][1][1] = min(b[i], Turno_0_Pasado_0.Consulta(0, n - 1, 0, i + 1, n - 1, 1));
        Turno_0_Pasado_1.Actualizar(0, n - 1, 0, i, PD[i][0][1]);
        Turno_1_Pasado_1.Actualizar(0, n - 1, 0, i, PD[i][1][1]);
        PD[i][0][0] = max(Turno_1_Pasado_0.Consulta(0, n - 1, 0, i + 1, n - 1, 0), Turno_1_Pasado_1.Consulta(0, n - 1, 0, i, n - 1, 0));
        PD[i][1][0] = min(Turno_0_Pasado_0.Consulta(0, n - 1, 0, i + 1, n - 1, 1), Turno_0_Pasado_1.Consulta(0, n - 1, 0, i, n - 1, 1));
        Turno_0_Pasado_0.Actualizar(0, n - 1, 0, i, PD[i][0][0]);
        Turno_1_Pasado_0.Actualizar(0, n - 1, 0, i, PD[i][1][0]);
    }
    cout<<PD[0][0][0]<<el;*/
    return 0;
}