#include "bits/stdc++.h"
#define ii pair<long long, long long>
#define iiii pair<ii, ii>
using namespace std;
struct Nodo{
    long long i, d, p, hi, hd, v;
};
struct Rango{
    long long a, b, c, d;
};
struct Otro_rango{
    long long a, b, c, d;
};
Otro_rango Conversor_ro(Rango a){
    Otro_rango b;
    b.a = a.a;
    b.b = a.b;
    b.c = a.c;
    b.d = a.d;
    return b;
}
Rango Conversor_or(Otro_rango a){
    Rango b;
    b.a = a.a;
    b.b = a.b;
    b.c = a.c;
    b.d = a.d;
    return b;
}
bool Contiener(Rango a, Rango b){
    return (b.a <= a.a and a.a <= b.b) or (b.a <= a.b and a.b <= b.b) or (a.a <= b.a and b.b <= a.b) or (b.a <= a.a and a.b <= b.b);
}
bool Contieneo(Otro_rango a, Otro_rango b){
    return (b.a <= a.a and a.a <= b.b) or (b.a <= a.b and a.b <= b.b) or (a.a <= b.a and b.b <= a.b) or (b.a <= a.a and a.b <= b.b);
}
bool operator<(const Rango &a, const Rango &b){
    if(a.a < b.a) return 1;
    if(a.a > b.a) return 0;
    if(a.b < b.b) return 1;
    if(a.b > b.b) return 0;
    if(a.c < b.c) return 1;
    if(a.c > b.c) return 1;
    return a.d < b.d;
}
bool operator<(const Otro_rango &a, const Otro_rango &b){
    if(a.b < b.b) return 1;
    if(a.b > b.b) return 0;
    if(a.a < b.a) return 1;
    if(a.a > b.a) return 0;
    if(a.c < b.c) return 1;
    if(a.c > b.c) return 1;
    return a.d < b.d;
}
vector<Nodo> _rbol;
Nodo Nodo_nuevo;
void Propagar(long long p){
    _rbol[p].v = min(_rbol[p].v, _rbol[p].p);
    if(_rbol[p].hi != -2){
        if(_rbol[_rbol[p].hi].p == -2) _rbol[_rbol[p].hi].p = _rbol[p].p;
        else _rbol[_rbol[p].hi].p = min(_rbol[_rbol[p].hi].p, _rbol[p].p);
    }
    if(_rbol[p].hd != -2){
        if(_rbol[_rbol[p].hd].p == -2) _rbol[_rbol[p].hd].p = _rbol[p].p;
        else _rbol[_rbol[p].hd].p = min(_rbol[_rbol[p].hd].p, _rbol[p].p);
    }
    _rbol[p].p = -2;
}
void Actualizar(long long i, long long d, long long p, long long I, long long D, long long v){
    long long P = (i + d) / 2LL;
    if(_rbol[p].hi == -2 and i != d){
        Nodo_nuevo.i = i;
        Nodo_nuevo.d = P;
        Nodo_nuevo.v = _rbol[p].v;
        _rbol[p].hi = _rbol.size();
        _rbol.push_back(Nodo_nuevo);
        Nodo_nuevo.i = P + 1;
        Nodo_nuevo.d = d;
        _rbol[p].hd = _rbol.size();
        _rbol.push_back(Nodo_nuevo);
    }
    if(_rbol[p].p != -2){
        Propagar(p);
    }
    if(i >= I and d <= D){
        _rbol[p].p = v;
        Propagar(p);
        /*cerr<<i<<" "<<d<<" "<<I<<" "<<D<<" "<<v<<"\n";
        if(_rbol[p].hi != -2){
            cerr<<_rbol[_rbol[p].hi].p<<" "<<_rbol[_rbol[p].hi].i<<" "<<_rbol[_rbol[p].hi].d<<"\n";
            cerr<<_rbol[_rbol[p].hd].p<<" "<<_rbol[_rbol[p].hd].i<<" "<<_rbol[_rbol[p].hd].d<<"\n";
            cerr<<"\n";
        }*/
        return;
    }
    if(i > D or d < I) return;
    Actualizar(i, P, _rbol[p].hi, I, D, v);
    Actualizar(P + 1, d, _rbol[p].hd, I, D, v);
    _rbol[p].v = min(_rbol[_rbol[p].hi].v, _rbol[_rbol[p].hd].v);
}
long long Consulta(long long i, long long d, long long p, long long I, long long D){
    long long P = (i + d) / 2LL;
    if(_rbol[p].hi == -2 and i != d){
        Nodo_nuevo.i = i;
        Nodo_nuevo.d = P;
        Nodo_nuevo.v = _rbol[p].v;
        _rbol[p].hi = _rbol.size();
        _rbol.push_back(Nodo_nuevo);
        Nodo_nuevo.i = P + 1;
        Nodo_nuevo.d = d;
        _rbol[p].hd = _rbol.size();
        _rbol.push_back(Nodo_nuevo);
    }
    if(_rbol[p].p != -2){
        Propagar(p);
    }
    if(i >= I and d <= D){
        //cout<<_rbol[p].v<<" "<<i<<" "<<d<<"\n";
        return _rbol[p].v;
    }
    if(i > D or d < I) return 22222222;
    return min(Consulta(i, P, _rbol[p].hi, I, D), Consulta(P + 1, d, _rbol[p].hd, I, D));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m, x, y;
        cin>>n>>m>>x>>y;
        _rbol.clear();
        Nodo_nuevo.i = 0;
        Nodo_nuevo.d = n + 22;
        Nodo_nuevo.p = -2;
        Nodo_nuevo.hi = -2;
        Nodo_nuevo.hd = -2;
        Nodo_nuevo.v = 22222222;
        _rbol.push_back(Nodo_nuevo);
        set<Rango> a;
        set<Otro_rango> oa;
        for(int i = 0; i < m; i++){
            Rango b;
            cin>>b.a>>b.b>>b.c>>b.d;
            a.insert(b);
            oa.insert(Conversor_ro(b));
        }
        deque<Rango> Cola;
        Actualizar(0, n + 22, 0, x, x, 0);
        Rango x_x__2__2;
        x_x__2__2.a = x;
        x_x__2__2.b = x;
        x_x__2__2.c = -2;
        x_x__2__2.d = -2;
        for(auto E: a){
            if(Contiener(E, x_x__2__2)){
                //Actualizar(0, n + 22, 0, E.a, E.b, 0);
                Cola.push_back(E);
            }
        }
        while(!Cola.empty()){
            Rango Actual = Cola[0];
            //cerr<<Actual.a<<" "<<Actual.b<<"\n";
            Otro_rango oActual = Conversor_ro(Actual);
            Rango cActual = Actual;
            Otro_rango coActual = oActual;
            Cola.pop_front();
            long long Distancia = Consulta(0, n + 22, 0, Actual.a, Actual.b) + 1LL;
            swap(Actual.a, Actual.b);
            Actual.a = -2;
            Actual.c = -2;
            Actual.d = -2;
            vector<Rango> Borrar;
            vector<Otro_rango> oBorrar;
            for(auto E = a.lower_bound(Actual); E != a.end(); E++){
                if(Contiener(*E, cActual)){
                    Borrar.push_back(*E);
                    Actualizar(0, n + 22, 0, (*E).c, (*E).d, Distancia);
                    Rango Nuevo_nodo_para_la_cola;
                    Nuevo_nodo_para_la_cola.a = (*E).c;
                    Nuevo_nodo_para_la_cola.b = (*E).d;
                    Nuevo_nodo_para_la_cola.c = -2;
                    Nuevo_nodo_para_la_cola.d = -2;
                    Cola.push_back(Nuevo_nodo_para_la_cola);
                    //cerr<<cActual.a<<" "<<cActual.b<<" "<<(*E).c<<" "<<(*E).d<<"\n";
                } else {
                    break;
                }
            }
            for(auto E: Borrar){
                a.erase(E);
                oa.erase(Conversor_ro(E));
            }
            Borrar.clear();
            Actual.b = -2;
            Actual.a = cActual.a;
            for(auto E = a.lower_bound(Actual); E != a.end(); E++){
                if(Contiener(*E, cActual)){
                    Borrar.push_back(*E);
                    Actualizar(0, n + 22, 0, (*E).c, (*E).d, Distancia);
                    Rango Nuevo_nodo_para_la_cola;
                    Nuevo_nodo_para_la_cola.a = (*E).c;
                    Nuevo_nodo_para_la_cola.b = (*E).d;
                    Nuevo_nodo_para_la_cola.c = -2;
                    Nuevo_nodo_para_la_cola.d = -2;
                    Cola.push_back(Nuevo_nodo_para_la_cola);
                    //cerr<<cActual.a<<" "<<cActual.b<<" "<<(*E).c<<" "<<(*E).d<<"\n";
                } else {
                    break;
                }
            }
            for(auto E: Borrar){
                a.erase(E);
                oa.erase(Conversor_ro(E));
            }
            swap(oActual.a, oActual.b);
            oActual.b = -2;
            oActual.c = -2;
            oActual.d = -2;
            auto E = oa.upper_bound(oActual);
            for(; 1; E--){
                //cerr<<Izquierda_del_rango<<" :(\n";
                //cerr<<(*E).a<<" "<<(*E).b<<" "<<Izquierda_del_rango<<" 1\n";
                if(E == oa.begin()) break;
                E--;
                //cerr<<(*E).a<<" "<<(*E).b<<" "<<Izquierda_del_rango<<" 2\n";
                if(Contieneo(*E, coActual)){
                    oBorrar.push_back(*E);
                    Actualizar(0, n + 22, 0, (*E).c, (*E).d, Distancia);
                    Rango Nuevo_nodo_para_la_cola;
                    Nuevo_nodo_para_la_cola.a = (*E).c;
                    Nuevo_nodo_para_la_cola.b = (*E).d;
                    Nuevo_nodo_para_la_cola.c = -2;
                    Nuevo_nodo_para_la_cola.d = -2;
                    Cola.push_back(Nuevo_nodo_para_la_cola);
                    //cerr<<coActual.a<<" "<<coActual.b<<" "<<(*E).c<<" "<<(*E).d<<"\n";
                } else {
                    break;
                }
            }
            for(auto e: oBorrar){
                a.erase(Conversor_or(e));
                oa.erase(e);
            }
            oActual.b = coActual.b + 1LL;
            oActual.a = -2;
            oBorrar.clear();
            E = oa.upper_bound(oActual);
            for(; 1; E--){
                //cerr<<Izquierda_del_rango<<" :(\n";
                //cerr<<(*E).a<<" "<<(*E).b<<" "<<Izquierda_del_rango<<" 1\n";
                if(E == oa.begin()) break;
                E--;
                //cerr<<(*E).a<<" "<<(*E).b<<" "<<Izquierda_del_rango<<" 2\n";
                if(Contieneo(*E, coActual)){
                    oBorrar.push_back(*E);
                    Actualizar(0, n + 22, 0, (*E).c, (*E).d, Distancia);
                    Rango Nuevo_nodo_para_la_cola;
                    Nuevo_nodo_para_la_cola.a = (*E).c;
                    Nuevo_nodo_para_la_cola.b = (*E).d;
                    Nuevo_nodo_para_la_cola.c = -2;
                    Nuevo_nodo_para_la_cola.d = -2;
                    Cola.push_back(Nuevo_nodo_para_la_cola);
                    //cerr<<coActual.a<<" "<<coActual.b<<" "<<(*E).c<<" "<<(*E).d<<"\n";
                } else {
                    break;
                }
            }
            for(auto e: oBorrar){
                a.erase(Conversor_or(e));
                oa.erase(e);
            }
        }
        long long Respuesta = Consulta(0, n + 22, 0, y, y);
        if(Respuesta != 22222222) cout<<Respuesta<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
/*
1
10 3 1 2
1 3 7 10
6 6 2 2
8 9 6 6
*/