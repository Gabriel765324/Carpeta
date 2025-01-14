#include "bits/stdc++.h"
using namespace std;
vector< vector<bool> > _rbol, Propagar;
bool Consulta(long long i, long long d, long long p, long long c1, long long c2, long long Cero_uno){
    if(Propagar[Cero_uno][p]){
        _rbol[Cero_uno][p] = 1;
        if(p * 2 < _rbol[0].size()){
            Propagar[Cero_uno][p * 2] = 1;
        }
        if(p * 2 + 1 < _rbol[0].size()){
            Propagar[Cero_uno][p * 2 + 1] = 1;
        }
    }
    //cout<<i<<" "<<d<<" "<<p<<" "<<c<<" "<<Cero_uno<<"\n";
    if(i >= c1 and d <= c2){
        //cout<<_rbol[Cero_uno][p]<<" "<<Cero_uno<<" "<<p<<"\n";
        //cout<<_rbol[Cero_uno][p]<<"\n";
        return _rbol[Cero_uno][p];
    }
    if(i > c2 or d < c1){
        //cout<<"0\n";
        return 0;
    }
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, c1, c2, Cero_uno) or Consulta(P + 1, d, p * 2 + 1, c1, c2, Cero_uno);
}
void Actualizar(long long i, long long d, long long p, long long c1, long long c2, long long Cero_uno){
    if(Propagar[Cero_uno][p]){
        _rbol[Cero_uno][p] = 1;
        if(p * 2 < _rbol[0].size()){
            Propagar[Cero_uno][p * 2] = 1;
        }
        if(p * 2 + 1 < _rbol[0].size()){
            Propagar[Cero_uno][p * 2 + 1] = 1;
        }
    }
    //cout<<i<<" "<<d<<" "<<p<<" "<<c1<<" "<<c2<<" "<<Cero_uno<<"\n";
    if(i >= c1 and d <= c2){
        Propagar[Cero_uno][p] = 1;
        _rbol[Cero_uno][p] = 1;
        //cout<<"Actualicé.\n";
        return;
    }
    if(i > c2 or d < c1) return;
    long long P = (i + d) / 2;
    Actualizar(i, P, p * 2, c1, c2, Cero_uno);
    Actualizar(P + 1, d, p * 2 + 1, c1, c2, Cero_uno);
    _rbol[Cero_uno][p] = _rbol[Cero_uno][p * 2] or _rbol[Cero_uno][p * 2 + 1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, Menor = -0;
    cin>>n;
    vector< vector<long long> > Pesas(2, vector<long long>(n));
    map<long long, vector< pair<long long, long long> > > Ubicaciones;
    set<long long> Existe;
    for(long long i = 0; i < n; i++){
        cin>>Pesas[0][i];
        Ubicaciones[Pesas[0][i]].push_back({0, i});
        Existe.insert(Pesas[0][i]);
    }
    for(auto E: Existe){
        if(Ubicaciones[E].size() == 1) Menor = max(Menor, E);
    }
    for(long long i = 0; i < n; i++){
        cin>>Pesas[1][i];
        Ubicaciones[Pesas[1][i]].push_back({1, i});
        Existe.insert(Pesas[1][i]);
    }
    deque<long long> Cola;
    for(auto E: Existe) Cola.push_front(E);
    /*for(auto E: Existe){
        cout<<E<<" "<<Ubicaciones[E][0].first<<" "<<Ubicaciones[E][0].second<<" "<<Ubicaciones[E][1].first<<" "<<Ubicaciones[E][1].second<<"\n";
    }*/
    _rbol.assign(2, vector<bool>((n + 22) * 4, 0));
    Propagar = _rbol;
    for(long long i = 0; i < n; i++){
        pair<long long, long long> p1 = Ubicaciones[Cola[i]][0], p2 = Ubicaciones[Cola[i]][1];
        if(p1.first != p2.first){
            Menor = max(Menor, Cola[i]);
            break;
        }
        /*for(auto E: _rbol){
            for(auto e: E) cout<<e<<" ";
            cout<<"\n";
        }*/
        if(Consulta(0, n - 1, 1, p1.second, p2.second, p1.first)){
            Menor = max(Menor, Cola[i]);
            break;
        }
        //cout<<Cola[i]<<" "<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<"\n";
        Actualizar(0, n - 1, 1, p1.second, p2.second, p2.first);
        /*for(long long j = 0; j < n; j++) cout<<Consulta(0, n - 1, 1, j, 0)<<" ";
        cout<<"\n";
        for(long long j = 0; j < n; j++) cout<<Consulta(0, n - 1, 1, j, 1)<<" ";
        cout<<"\n";*/
        //cout<<"\n";
    }
    cout<<Menor;
    return 0;
}