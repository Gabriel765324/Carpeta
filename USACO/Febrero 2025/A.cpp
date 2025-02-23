#include "bits/stdc++.h"
using namespace std;
mt19937_64 Aleatorio(0);
bool o(pair<long long, long long> &a, pair<long long, long long> &b){
    if(a.first > b.first) return 1;
    if(b.first > a.first) return 0;
    return a.second < b.second;
}
vector<bool> _rbol;
vector<long long> Jaja;
void Crear(long long i, long long d, long long p){
    if(i == d){
        Jaja[i] = p;
        return;
    }
    long long P = (i + d) / 2;
    Crear(i, P, p * 2);
    Crear(P + 1, d, p * 2 + 1);
}
bool Consulta(long long i, long long d, long long p, long long I, long long D){
    if(i > D or d < I or d < i) return 0;
    if(I <= i and d <= D) return _rbol[p];
    long long P = (i + d) / 2;
    return Consulta(i, P, p * 2, I, D) or Consulta(P + 1, d, p * 2 + 1, I, D);
}
void Actualizar(long long p, long long o){
    if(p == 0) return;
    if(p == o) _rbol[p] = 1;
    if(p != o) _rbol[p] = _rbol[p * 2] or _rbol[p * 2 + 1];
    Actualizar(p / 2, o);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    //cin>>t;
    //while(t--){
    uniform_int_distribution<long long> Valor(1, 12), Valores(1, 222);
    while(1){
        long long n;
        //cin>>n;
        n = Valor(Aleatorio);
        _rbol.assign(n * 4 + 22, 0);
        Jaja.assign(n * 4 + 22, 0);
        vector<long long> a(n);
        vector< pair<long long, long long> > b(n);
        for(long long i = 0; i < n; i++){
            //cin>>a[i];
            a[i] = Valores(Aleatorio);
            b[i] = {a[i], i};
        }
        /*bool Completo = 1;
        for(long long i = 1; i < n and Completo; i++){
            if(a[i] > a[i - 1]) Completo = 0;
        }
        if(Completo){
            for(auto E: a) cout<<E<<" ";
            cout<<"\n";
            continue;
        }*/
        sort(b.begin(), b.end(), o);
        Crear(0, n - 1, 1);
        vector<long long> Secuencia;
        long long i = 0, Mayor_posici_n = -2;
        /*for(auto E: b) cout<<E.first<<" ";
        cout<<"\n";
        for(auto E: b) cout<<E.second<<" ";
        cout<<"\n";*/
        bool Roto = 0;
        for(i = 0; i < n - 1; i++){
            if(Mayor_posici_n <= b[i].second) Secuencia.push_back(b[i].first);
            //cout<<i<<" ";
            Mayor_posici_n = max(Mayor_posici_n, b[i].second);
            //Ver si moverlo va a lograr que se pueda usar.
            //for(long long j = 0; j < n; j++) cout<<Consulta(0, n - 1, 1, j, j)<<" ";
            //cout<<"\n"<<!Consulta(0, n - 1, 1, b[i + 1].second, Mayor_posici_n)<<" "<<b[i + 1].second<<" "<<Mayor_posici_n<<"\n";
            if(Mayor_posici_n > b[i + 1].second and !Consulta(0, n - 1, 1, b[i + 1].second, Mayor_posici_n)){
                Mayor_posici_n = b[i + 1].second - 1;
                Roto = 1;
            }
            Actualizar(Jaja[b[i].second], Jaja[b[i].second]);
            if(Roto) break;
        }
        if(!Roto) i--;
        for(i++; i < n; i++){
            //cout<<i<<" ";
            /*cout<<b[i].second<<"\n";
            for(long long j = 0; j < n; j++) cout<<Consulta(0, n - 1, 1, j, j)<<" ";
            cout<<"\n";*/
            if(b[i].second > Mayor_posici_n and !Consulta(0, n - 1, 1, b[i].second, b[i].second)){
                Mayor_posici_n = b[i].second;
                Actualizar(Jaja[b[i].second], Jaja[b[i].second]);
                Secuencia.push_back(b[i].first);
            }
        }
        vector< vector<long long> > Posibles;
        vector<long long> ca = a;
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < i; j++){
                ca = a;
                long long aaaa = ca[i];
                ca.erase(ca.begin() + i);
                ca.insert(ca.begin() + j, aaaa);
                vector< pair<long long, long long> > b2(n);
                for(long long k = 0; k < n; k++){
                    b2[k] = {ca[k], k};
                }
                sort(b2.begin(), b2.end(), o);
                vector<long long> Insertar;
                long long Mayor_usado_hasta_ahora = -2;
                for(long long k = 0; k < n; k++){
                    if(Mayor_usado_hasta_ahora < b2[k].second){
                        Insertar.push_back(b2[k].first);
                        Mayor_usado_hasta_ahora = b2[k].second;
                    }
                }
                Posibles.push_back(Insertar);
            }
        }
        sort(Posibles.rbegin(), Posibles.rend());
        //for(long long i = 0; i < Posibles[0].size(); i++) cout<<Posibles[0][i]<<((i < Posibles[0].size() - 1) ? " " : "");
        if(Posibles[0] > Secuencia){
            cout<<"Fallo.\n";
            for(auto E: a) cout<<E<<" ";
            cout<<"\n";
            for(auto E: Secuencia) cout<<E<<" ";
            cout<<"\n";
            for(auto E: Posibles[0]) cout<<E<<" ";
            cout<<"\n";
            break;
        } else {
            cout<<"Bien.\n";
            for(auto E: a) cout<<E<<" ";
            cout<<"\n";
            for(auto E: Secuencia) cout<<E<<" ";
            cout<<"\n";
            for(auto E: Posibles[0]) cout<<E<<" ";
            cout<<"\n";
        }
        /*for(i = 0; i < Secuencia.size(); i++) cout<<Secuencia[i]<<((i != Secuencia.size() - 1) ? " " : "");
        if(t > 0) cout<<"\n";*/
    //}
    }
    return 0;
}
/*
Caso fallido:
1
5
5 5 4 5 5
Da: 5 5 5 5 4
Debería dar: 5 5 5 5 5
*/