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
int n, q, rn;
struct Consulta{
    int i, d, k, bi, ID;
    Consulta(){}
    Consulta(int I, int D, int K, int IID){
        i = I;
        d = D;
        k = K;
        ID = IID;
        bi = i / rn;
    }
    bool operator<(const Consulta& a){
        return mp(bi, d) < mp(a.bi, a.d);
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    rn = sqrt(n);
    vi a(n);
    forn(i, n) cin>>a[i];
    vector<Consulta> Consultas(q);
    forn(I, q){
        int i, d, k;
        cin>>i>>d>>k;
        i--;
        d--;
        Consultas[I] = Consulta(i, d, k, I);
    }
    sort(Consultas.begin(), Consultas.end());
    vi Frecuencias(n + 1, 0);
    set<Frecuente> Mejores;
    vi Respuestas(q);
    int i = 0, d = 0;
    Frecuencias[a[0]]++;
    Mejores.insert(Frecuente(a[0], 1));
    for(auto E: Consultas){
        if(d < E.d){
            while(1){
                d++;
                Mejores.erase(Frecuente(a[d], Frecuencias[a[d]]));
                Frecuencias[a[d]]++;
                Mejores.insert(Frecuente(a[d], Frecuencias[a[d]]));
                if(d == E.d) break;
            }
        } else if(d > E.d){
            while(1){
                Mejores.erase(Frecuente(a[d], Frecuencias[a[d]]));
                Frecuencias[a[d]]--;
                Mejores.insert(Frecuente(a[d], Frecuencias[a[d]]));
                d--;
                if(d == E.d) break;
            }
        }
        if(i < E.i){
            while(1){
                Mejores.erase(Frecuente(a[i], Frecuencias[a[i]]));
                Frecuencias[a[i]]--;
                Mejores.insert(Frecuente(a[i], Frecuencias[a[i]]));
                i++;
                if(i == E.i) break;
            }
        } else if(i > E.i){
            while(1){
                i--;
                Mejores.erase(Frecuente(a[i], Frecuencias[a[i]]));
                Frecuencias[a[i]]++;
                Mejores.insert(Frecuente(a[i], Frecuencias[a[i]]));
                if(i == E.i) break;
            }
        }
        int Mejor = INT_MAX, c = 0, Superar = (E.d - E.i + 1) / E.k;
        /*for(auto e: Frecuencias) cerr<<e<<" ";
        cerr<<el;*/
        for(auto e: Mejores){
            if(e.f > Superar) Mejor = min(Mejor, e.v);
            else break;
            c++;
            if(c == 6) break;
        }
        Respuestas[E.ID] = Mejor == INT_MAX ? -1 : Mejor;
    }
    for(auto E: Respuestas) cout<<E<<el;
    return 0;
}
/*
1 2 3 3 3 4 4 4 4 2 2 1 1 1 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/