#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pf push_front
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
struct Consulta{
    int i, d, ID, bi;
    Consulta(){}
    Consulta(int I, int D, int iD){
        i = I;
        d = D;
        ID = iD;
        bi = I / 300;
    }
    bool operator<(const Consulta& a) const{
        return mp(bi, d) < mp(a.bi, a.d);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n;
    vi a(n);
    forn(i, n) cin>>a[i];
    cin>>q;
    vector<Consulta> Consultas(q);
    forn(i, q){
        cin>>Consultas[i].i>>Consultas[i].d;
        Consultas[i].i--;
        Consultas[i].d--;
        Consultas[i].ID = i;
        Consultas[i].bi = Consultas[i].i / 300;
    }
    vi Respuestas(q, 0);
    //vector<Consulta> Consultas2(q);
    sort(all(Consultas));
    int Contador_de_diferentes = 0, i = 0, d = 0, Contador_de_unos = 1;
    vector< deque<int> > Ayudante(100022);
    vi Apariciones(100022, 0), Contador_de_progresiones(100022, 0);
    Contador_de_diferentes++;
    Apariciones[a[0]]++;
    Ayudante[a[0]].pb(0);
    Contador_de_progresiones[a[0]]++;
    //int Tiempo = 0;
    for(auto E: Consultas){
        while(E.i < i){
            i--;
            if(Apariciones[a[i]] == 0) Contador_de_diferentes++;
            Apariciones[a[i]]++;
            int t = int(Ayudante[a[i]].size());
            if(t == 0){
                Ayudante[a[i]].pb(i);
                Contador_de_progresiones[a[i]]++;
                Contador_de_unos++;
            } else if(t == 1) Ayudante[a[i]].pf(i);
            else {
                Ayudante[a[i]].pf(i);
                if(Ayudante[a[i]][1] - i != Ayudante[a[i]][2] - Ayudante[a[i]][1]){
                    Contador_de_progresiones[a[i]]++;
                    if(Contador_de_progresiones[a[i]] == 2) Contador_de_unos--;
                }
            }
        }
        while(d < E.d){
            d++;
            if(Apariciones[a[d]] == 0) Contador_de_diferentes++;
            Apariciones[a[d]]++;
            int t = int(Ayudante[a[d]].size());
            if(t == 0){
                Ayudante[a[d]].pb(d);
                Contador_de_progresiones[a[d]]++;
                Contador_de_unos++;
            } else if(t == 1) Ayudante[a[d]].pb(d);
            else {
                if(Ayudante[a[d]][t - 1] - d != Ayudante[a[d]][t - 2] - Ayudante[a[d]][t - 1]){
                    Contador_de_progresiones[a[d]]++;
                    if(Contador_de_progresiones[a[d]] == 2) Contador_de_unos--;
                }
                Ayudante[a[d]].pb(d);
            }
        }
        for(; i < E.i; i++){
            if(Apariciones[a[i]] == 1) Contador_de_diferentes--;
            Apariciones[a[i]]--;
            int t = int(Ayudante[a[i]].size());
            if(t == 1){
                Ayudante[a[i]].pop_back();
                Contador_de_progresiones[a[i]]--;
                Contador_de_unos--;
            } else if(t == 2) Ayudante[a[i]].pop_front();
            else {
                if(Ayudante[a[i]][1] - i != Ayudante[a[i]][2] - Ayudante[a[i]][1]){
                    Contador_de_progresiones[a[i]]--;
                    if(Contador_de_progresiones[a[i]] == 1) Contador_de_unos++;
                }
                Ayudante[a[i]].pop_front();
            }
        }
        for(; d > E.d; d--){
            if(Apariciones[a[d]] == 1) Contador_de_diferentes--;
            Apariciones[a[d]]--;
            int t = int(Ayudante[a[d]].size());
            if(t == 1){
                Ayudante[a[d]].pop_back();
                Contador_de_progresiones[a[d]]--;
                Contador_de_unos--;
            } else if(t == 2) Ayudante[a[d]].pop_back();
            else {
                if(Ayudante[a[d]][t - 2] - d != Ayudante[a[d]][t - 3] - Ayudante[a[d]][t - 2]){
                    Contador_de_progresiones[a[d]]--;
                    if(Contador_de_progresiones[a[d]] == 1) Contador_de_unos++;
                }
                Ayudante[a[d]].pop_back();
            }
        }
        Respuestas[E.ID] = Contador_de_diferentes + (Contador_de_unos >= 1 ? 0 : 1);
        /*Consultas2[E.ID] = E;
        Consultas2[E.ID].bi = Tiempo;
        Tiempo++;*/
    }
    //i = 0;
    for(auto E: Respuestas){
        cout<<E<<el;
        //cout<<E<<" "<<Consultas2[i].i<<" "<<Consultas2[i].d<<" "<<Consultas2[i].ID<<" "<<Consultas2[i].bi<<el;
        //i++;
    }
    return 0;
}