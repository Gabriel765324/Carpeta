#include "bits/stdc++.h"
using namespace std;
int n, m, q;
string s, c;
//vector< vector<int> > PD;
vector<int> v, ArboleableP, ArboleableI;
struct Nodo{
    int v, p;
};
vector<Nodo> _rbolP, _rbolI;
int Distancia(string a){
    int r = 0;
    for(int i = 0; i < m; i++){
        if(a[i] < c[i]) r += min(c[i] - a[i], a[i] - 'a' + 1 + 'z' - c[i]);
        else r += min(a[i] - c[i], 'z' - a[i] + 1 + c[i] - 'a');
    }
    return r;
}
int operator+(const Nodo& a, const Nodo& b){
    return min(a.v, b.v);
}
void CrearI(int i, int d, int p){
    if(i == d){
        _rbolI[p].v = ArboleableI[i];
        return;
    }
    int P = (i + d) / 2;
    CrearI(i, P, p * 2);
    CrearI(P + 1, d, p * 2 + 1);
    _rbolI[p].v = _rbolI[p * 2] + _rbolI[p * 2 + 1];
}
void CrearP(int i, int d, int p){
    if(i == d){
        _rbolP[p].v = ArboleableP[i];
        return;
    }
    int P = (i + d) / 2;
    CrearP(i, P, p * 2);
    CrearP(P + 1, d, p * 2 + 1);
    _rbolP[p].v = _rbolP[p * 2] + _rbolP[p * 2 + 1];
}
void PropagarI(int i, int d, int p){
    if(_rbolI[p].p == 0) return;
    _rbolI[p].v += _rbolI[p].p;
    if(i == d){
        _rbolI[p].p = 0;
        return;
    }
    if(_rbolI[p * 2].p == 0) _rbolI[p * 2].p = _rbolI[p].p;
    else _rbolI[p * 2].p += _rbolI[p].p;
    if(_rbolI[p * 2 + 1].p == 0) _rbolI[p * 2 + 1].p = _rbolI[p].p;
    else _rbolI[p * 2 + 1].p += _rbolI[p].p;
    _rbolI[p].p = 0;
}
void PropagarP(int i, int d, int p){
    if(_rbolP[p].p == 0) return;
    _rbolP[p].v += _rbolP[p].p;
    if(i == d){
        _rbolP[p].p = 0;
        return;
    }
    if(_rbolP[p * 2].p == 0) _rbolP[p * 2].p = _rbolP[p].p;
    else _rbolP[p * 2].p += _rbolP[p].p;
    if(_rbolP[p * 2 + 1].p == 0) _rbolP[p * 2 + 1].p = _rbolP[p].p;
    else _rbolP[p * 2 + 1].p += _rbolP[p].p;
    _rbolP[p].p = 0;
}
int ConsultaI(int i, int d, int p, int I, int D){
    PropagarI(i, d, p);
    if(i >= I and d <= D){
        return _rbolI[p].v;
    }
    if(i > D or d < I){
        return INT_MAX;
    }
    int P = (i + d) / 2;
    return min(ConsultaI(i, P, p * 2, I, D), ConsultaI(P + 1, d, p * 2 + 1, I, D));
}
int ConsultaP(int i, int d, int p, int I, int D){
    PropagarP(i, d, p);
    if(i >= I and d <= D){
        return _rbolP[p].v;
    }
    if(i > D or d < I){
        return INT_MAX;
    }
    int P = (i + d) / 2;
    return min(ConsultaP(i, P, p * 2, I, D), ConsultaP(P + 1, d, p * 2 + 1, I, D));
}
void ActualizarI(int i, int d, int p, int I, int D, int v){
    if(I > D) return;
    PropagarI(i, d, p);
    if(i >= I and d <= D){
        _rbolI[p].p = v;
        PropagarI(i, d, p);
        return;
    }
    if(i > D or d < I){
        return;
    }
    int P = (i + d) / 2;
    ActualizarI(i, P, p * 2, I, D, v);
    ActualizarI(P + 1, d, p * 2 + 1, I, D, v);
    _rbolI[p].v = _rbolI[p * 2] + _rbolI[p * 2 + 1];
}
void ActualizarP(int i, int d, int p, int I, int D, int v){
    if(I > D) return;
    PropagarP(i, d, p);
    if(i >= I and d <= D){
        _rbolP[p].p = v;
        PropagarP(i, d, p);
        return;
    }
    if(i > D or d < I){
        return;
    }
    int P = (i + d) / 2;
    ActualizarP(i, P, p * 2, I, D, v);
    ActualizarP(P + 1, d, p * 2 + 1, I, D, v);
    _rbolP[p].v = _rbolP[p * 2] + _rbolP[p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q>>s>>c;
    if(m > n){
        while(q--) cout<<"-1\n";
        return -0;
    }
    int t = n - m + 1;
    for(int i = 0; i < t; i++){
        v.push_back(Distancia(s.substr(i, m)));
    }
    vector<int> SumaP(t, 0), SumaI(t, 0), iSumaP(t, 0), iSumaI(t, 0);
    for(int i = 0; i < t; i++){
        if(i % 2 == 0) SumaP[i] = v[i];
        else SumaI[i] = v[i];
        if(i > 0){
            SumaP[i] += SumaP[i - 1];
            SumaI[i] += SumaI[i - 1];
        }
    }
    for(int i = t - 1; i > -1; i--){
        if(i % 2 == 0) iSumaP[i] = v[i];
        else iSumaI[i] = v[i];
        if(i < t - 1){
            iSumaP[i] += SumaP[i + 1];
            iSumaI[i] += SumaI[i + 1];
        }
    }
    for(int i = 0; i < t; i++){
        ArboleableP.push_back(SumaP[i]);
        ArboleableI.push_back(SumaI[i]);
        if(i % 2 == 0){
            if(i + 2 < t) ArboleableP.back() += iSumaI[i + 2];
            else ArboleableP.back() = INT_MAX;
        } else {
            if(i + 2 < t) ArboleableI.back() += iSumaP[i + 2];
            else ArboleableI.back() = INT_MAX;
        }
    }
    Nodo Nada;
    Nada.p = 0;
    _rbolI.assign(t * 4 + 22, Nada);
    _rbolP.assign(t * 4 + 22, Nada);
    CrearI(0, t - 1, 1);
    CrearP(0, t - 1, 1);
    while(q--){
        int i, d;
        cin>>i>>d;
        if(d - i + 1 < m){
            cout<<"-1\n";
            continue;
        }
        int Quitari = 0, Quitard = 0;
        if(i % 2 == 0){
            if(i > 0) Quitari = SumaP[i - 1];
            if(d + 3 <= t - 1) Quitard = iSumaI[d + 3];
            ActualizarP(0, t - 1, 1, i, d, -Quitari);
            ActualizarP(0, t - 1, 1, i, d, -Quitard);
            int Posible = SumaP[d];
            if(i > 0) Posible -= SumaP[i - 1];
            cout<<min(ConsultaP(0, t - 1, 1, i, d), Posible)<<"\n";
            ActualizarP(0, t - 1, 1, i, d, Quitari);
            ActualizarP(0, t - 1, 1, i, d, Quitard);
        } else {
            if(i > 0) Quitari = SumaI[i - 1];
            if(d + 3 <= t - 1) Quitard = iSumaP[d + 3];
            ActualizarI(0, t - 1, 1, i, d, -Quitari);
            ActualizarI(0, t - 1, 1, i, d, -Quitard);
            int Posible = SumaI[d];
            if(i > 0) Posible -= SumaI[i - 1];
            cout<<min(ConsultaI(0, t - 1, 1, i, d), Posible)<<"\n";
            ActualizarI(0, t - 1, 1, i, d, Quitari);
            ActualizarI(0, t - 1, 1, i, d, Quitard);
        }
    }
    return 0;
}