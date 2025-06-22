#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > _rbolesM, Original, _rbolesm;
vector<bool> _rbolB;
void Crear(long long i, long long d, long long p, long long n){
    if(i == d){
        _rbolesM[n][p] = Original[n][i];
        _rbolesm[n][p] = Original[n][i];
    } else {
        long long P = (i + d) / 2;
        Crear(i, P, p * 2, n);
        Crear(P + 1, d, p * 2 + 1, n);
        _rbolesM[n][p] = max(_rbolesM[n][p * 2], _rbolesM[n][p * 2 + 1]);
        _rbolesm[n][p] = min(_rbolesm[n][p * 2], _rbolesm[n][p * 2 + 1]);
    }
}
void Actualizar(long long i, long long d, long long p, long long n, long long e, long long v){
    if(i > e or d < e) return;
    if(i == e and d == e){
        _rbolesM[n][p] = v;
        _rbolesm[n][p] = v;
        return;
    }
    long long P = (i + d) / 2;
    Actualizar(i, P, p * 2, n, e, v);
    Actualizar(P + 1, d, p * 2 + 1, n, e, v);
    _rbolesM[n][p] = max(_rbolesM[n][p * 2], _rbolesM[n][p * 2 + 1]);
    _rbolesm[n][p] = min(_rbolesm[n][p * 2], _rbolesm[n][p * 2 + 1]);
}
void CrearB(long long i, long long d, long long p){
    if(i == d){
        _rbolB[p] = (_rbolesM[i][1] == _rbolesm[i][1]);
    } else {
        long long P = (i + d) / 2;
        CrearB(i, P, p * 2);
        CrearB(P + 1, d, p * 2 + 1);
        _rbolB[p] = (_rbolB[p * 2] and _rbolB[p * 2 + 1]);
    }
}
void ActualizarB(long long i, long long d, long long p, long long e, bool v){
    if(i > e or d < e) return;
    if(i == e and d == e){
        _rbolB[p] = v;
        return;
    }
    long long P = (i + d) / 2;
    ActualizarB(i, P, p * 2, e, v);
    ActualizarB(P + 1, d, p * 2 + 1, e, v);
    _rbolB[p] = (_rbolB[p * 2] and _rbolB[p * 2 + 1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        vector< vector<long long> > a(n, vector<long long>(m));
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                cin>>a[i][j];
            }
        }
        _rbolesM.assign(n + m - 1, vector<long long>());
        _rbolesm.assign(n + m - 1, vector<long long>());
        Original.clear();
        long long N_mero_de__rbol = 0;
        for(long long i = n - 1; i > -1; i--){
            long long x = i, y = 0;
            vector<long long> Nuevo;
            while(x < n and y < m){
                Nuevo.push_back(a[x][y]);
                x++;
                y++;
                //cout<<Nuevo.back()<<" ";
            }
            //cout<<"\n";
            Original.push_back(Nuevo);
            _rbolesM[N_mero_de__rbol].assign(Nuevo.size() * 4, 0);
            _rbolesm[N_mero_de__rbol].assign(Nuevo.size() * 4, 0);
            Crear(0, Nuevo.size() - 1, 1, N_mero_de__rbol);
            N_mero_de__rbol++;
        }
        for(long long i = 1; i < m; i++){
            long long x = 0, y = i;
            vector<long long> Nuevo;
            while(x < n and y < m){
                Nuevo.push_back(a[x][y]);
                x++;
                y++;
                //cout<<Nuevo.back()<<" ";
            }
            //cout<<"\n";
            Original.push_back(Nuevo);
            _rbolesM[N_mero_de__rbol].assign(Nuevo.size() * 4, 0);
            _rbolesm[N_mero_de__rbol].assign(Nuevo.size() * 4, 0);
            Crear(0, Nuevo.size() - 1, 1, N_mero_de__rbol);
            N_mero_de__rbol++;
        }
        _rbolB.assign((n + m - 1) * 4, 0);
        CrearB(0, n + m - 2, 1);
        long long q;
        cin>>q;
        while(q--){
            long long x, y, N;
            cin>>x>>y>>N;
            x--;
            y--;
            long long p = n - 1 - x + y;
            Actualizar(0, Original[p].size() - 1, 1, p, min(x, y), N);
            ActualizarB(0, n + m - 2, 1, p, (_rbolesM[p][1] == _rbolesm[p][1]));
            if(_rbolB[1]) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}