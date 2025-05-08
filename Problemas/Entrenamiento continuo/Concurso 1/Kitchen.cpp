#include "bits/stdc++.h"
using namespace std;
vector<long long> _rbol, Propagar;
void Propagando(long long p){
    _rbol[p] += Propagar[p];
    long long v = Propagar[p];
    if(p * 2 < _rbol.size()) Propagar[p * 2] += v;
    if(p * 2 + 1 < _rbol.size()) Propagar[p * 2 + 1] += v;
    Propagar[p] = 0;
}
long long Consulta(long long i, long long d, long long p, long long v){
    Propagando(p);
    if(i > v or d < v) return 0;
    if(i == v and d == v) return _rbol[p];
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, v) + Consulta(P + 1, d, p * 2 + 1, v);
}
void Actualizar(long long i, long long d, long long p, long long I, long long D, long long v){
    Propagando(p);
    if(i > D or d < I) return;
    if(i >= I and d <= D){
        Propagar[p] += v;
        Propagando(p);
        return;
    }
    long long P = (i + d) / 2;
    Actualizar(i, P, p * 2, I, D, v);
    Actualizar(P + 1, d, p * 2 + 1, I, D, v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, k;
    cin>>n>>m>>k;
    vector<long long> a(n), b(m);
    long long Tiempo = 0;
    for(long long i = 0; i < n; i++){
        cin>>a[i];
        Tiempo += a[i];
        if(a[i] < k){
            cout<<"Impossible";
            return -0;
        }
    }
    for(long long j = 0; j < m; j++) cin>>b[j];
    if(k == 1){
        /*long long Resolver(long long i, long long t){
            if(t <= 0) return -t;
            if(i >= n) return 2222222222222222;
            if(Memorizaci_n[i][t] != -2) return Memorizaci_n[i][t];
            return min(Resolver(i + 1, t), Resolver(i + 1, t - b[i]));
        }*/
        vector< vector<long long> > Memorizaci_n(2, vector<long long>(Tiempo + 1, 222222222222222));
        Memorizaci_n[0][0] = 0;
        for(long long i = m - 1; i > -1; i--){
            swap(Memorizaci_n[0], Memorizaci_n[1]);
            for(long long j = 0; j <= Tiempo; j++){
                Memorizaci_n[0][j] = Memorizaci_n[1][j];
                if(j - b[i] > -1) Memorizaci_n[0][j] = min(Memorizaci_n[0][j], Memorizaci_n[1][j - b[i]]);
                else Memorizaci_n[0][j] = min(Memorizaci_n[0][j], b[i] - j);
                //cout<<Memorizaci_n[0][j]<<" ";
            }
            //cout<<"\n";
        }
        if(Memorizaci_n[0][Tiempo] == 222222222222222) cout<<"Impossible";
        else cout<<Memorizaci_n[0][Tiempo];
        return -0;
    }
    if(m <= 15){
        long long Mejor = -2;
        for(long long Caso = 0; Caso < (1LL<<m); Caso++){
            vector<long long> Cocineros;
            long long Suma = 0;
            long long c = 0;
            for(long long i = 0; i < m; i++){
                if((1LL<<i) & Caso){
                    Cocineros.push_back(b[i]);
                    Suma += b[i];
                    c++;
                }
            }
            /*for(auto E: Cocineros) cout<<E<<" ";
            cout<<"\n";*/
            if(Suma < Tiempo or c < k){
                //cout<<"Saltado.\n";
                continue;
            }
            //vector<long long> Diferentes(n, 0);
            bool Posible = 1;
            _rbol.assign(n * 4 + 22, 0);
            Propagar.assign(n * 4 + 22, 0);
            long long Prioridad = 0;
            for(long long i = 0; i < Cocineros.size(); i++){
                long long Avance = min(Cocineros[i], n);
                if(Avance == n) Actualizar(0, n - 1, 1, 0, n - 1, 1);
                else {
                    if(Prioridad + Avance - 1 < n){
                        Actualizar(0, n - 1, 1, Prioridad, Prioridad + Avance - 1, 1);
                        Prioridad = (Prioridad + Avance) % n;
                    } else {
                        Actualizar(0, n - 1, 1, Prioridad, n - 1, 1);
                        Prioridad = (Prioridad + Avance) % n;
                        Actualizar(0, n - 1, 1, 0, Prioridad - 1, 1);
                    }
                }
                /*for(long long i = 0; i < n; i++) cout<<Consulta(0, n - 1, 1, i)<<" ";
                cout<<"\n";*/
            }
            for(long long i = 0; i < n; i++){
                //cout<<Consulta(0, n - 1, 1, i)<<" "<<k<<"\n";
                if(Consulta(0, n - 1, 1, i) < k){
                    Posible = 0;
                    break;
                }
            }
            if(Posible){
                //cout<<"Se pudo.\n";
                if(Mejor == -2) Mejor = Suma - Tiempo;
                else Mejor = min(Mejor, Suma - Tiempo);
            }
        }
        if(Mejor == -2) cout<<"Impossible";
        else cout<<Mejor;
        return -0;
    }
    return 0;
}