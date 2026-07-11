#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
int n, q;
vi a;
struct Consulta{
    int i, d, k, ID;
    Consulta(){}
    Consulta(int I, int D, int K, int IID){
        i = I;
        d = D;
        k = K;
        ID = IID;
    }
};
struct Frecuente{
    int v, f;
    Frecuente(int V, int F){
        v = V;
        f = F;
    }
};
bool operator<(const Frecuente& a, const Frecuente& b){
    return mp(-a.f, a.v) < mp(-b.f, b.v);
}
vi Respuestas;
vector< deque<int> > Apariciones_i;
vector< vi > Apariciones_d;
vector< set<Frecuente> > Comunes_i, Comunes_d;
void Dividir(int i, int d, vector<Consulta>& q){
    if(d == i){
        for(auto E: q){
            Respuestas[E.ID] = a[i];
        }
        return;
    }
    bitset<300002> Tiene_i, Tiene_d;
    int p = (i + d) >> 1;
    vector<Consulta> Izquierdo, Derecho;
    set<Frecuente> Frecuentado;
    for(int j = p; j >= i; j--){
        if(Tiene_i[a[j]]) Apariciones_i[a[j]].push_front(j);
        else {
            Tiene_i[a[j]] = 1;
            Apariciones_i[a[j]] = {j};
        }
        int Apariciones = int(Apariciones_i[a[j]].size());
        Frecuentado.erase(Frecuente(a[j], Apariciones - 1));
        Frecuentado.insert(Frecuente(a[j], Apariciones));
        if(int(Frecuentado.size()) > 5){
            auto E = Frecuentado.end();
            E--;
            Frecuentado.erase(E);
        }
        Comunes_i[j] = Frecuentado;
    }
    Frecuentado.clear();
    for(int j = p + 1; j <= d; j++){
        if(Tiene_d[a[j]]) Apariciones_d[a[j]].push_back(j);
        else {
            Tiene_d[a[j]] = 1;
            Apariciones_d[a[j]] = {j};
        }
        int Apariciones = int(Apariciones_d[a[j]].size());
        Frecuentado.erase(Frecuente(a[j], Apariciones - 1));
        Frecuentado.insert(Frecuente(a[j], Apariciones));
        if(int(Frecuentado.size()) > 5){
            auto E = Frecuentado.end();
            E--;
            Frecuentado.erase(E);
        }
        Comunes_d[j] = Frecuentado;
    }
    for(auto E: q){
        if(E.d <= p){
            Izquierdo.push_back(E);
            continue;
        }
        if(E.i > p){
            Derecho.push_back(E);
            continue;
        }
        for(auto e: Comunes_i[E.i]){
            int Aparecido = (Tiene_d[e.v] ? (upper_bound(all(Apariciones_d[e.v]), E.d) - Apariciones_d[e.v].begin()) : 0) + e.f;
            if(Aparecido > ((E.d - E.i + 1) / E.k)){
                Respuestas[E.ID] = Respuestas[E.ID] == -1 ? e.v : min(e.v, Respuestas[E.ID]);
            }
        }
        for(auto e: Comunes_d[E.d]){
            int Aparecido = (Tiene_i[e.v] ? (int(Apariciones_i[e.v].size()) - (lower_bound(all(Apariciones_i[e.v]), E.i) - Apariciones_i[e.v].begin())) : 0) + e.f;
            if(Aparecido > ((E.d - E.i + 1) / E.k)){
                Respuestas[E.ID] = Respuestas[E.ID] == -1 ? e.v : min(e.v, Respuestas[E.ID]);
            }
        }
    }
    q.clear();
    if(!Izquierdo.empty()) Dividir(i, p, Izquierdo);
    if(!Derecho.empty()) Dividir(p + 1, d, Derecho);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    Respuestas.assign(q, -1);
    a.assign(n, 0);
    set<Frecuente> Nada;
    Comunes_i.assign(n + 22, Nada);
    Comunes_d.assign(n + 22, Nada);
    Apariciones_i.assign(n + 22, {});
    Apariciones_d.assign(n + 22, {});
    forn(i, n) cin>>a[i];
    vector<Consulta> Consultas(q);
    forn(I, q){
        int i, d, k;
        cin>>i>>d>>k;
        i--;
        d--;
        Consultas[I] = Consulta(i, d, k, I);
    }
    Dividir(0, n - 1, Consultas);
    for(auto E: Respuestas) cout<<E<<el;
    return 0;
}