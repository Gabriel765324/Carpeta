#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long 
#define vi vector<int>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
string a;
ll b;
int n;
vi Ciclos = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
vector< vi > Valores = {
    {0},
    {1},
    {2, 4, 8, 6},
    {3, 9, 7, 1},
    {4, 6},
    {5},
    {6},
    {7, 9, 3, 1},
    {8, 4, 2, 6},
    {9, 1}
};
vector<ll> Potencias_de_diez(1, 1);
vector< vector<ll> > Potencias_previas(10);
bool Fin = 0;
vector<int> Resultado;
bool Resolver(vi Exponentes, int i, ll v){
    /*reverse(Exponentes.begin(), Exponentes.end());
    for(auto E: Exponentes) cerr<<E<<" ";
    cerr<<el;
    reverse(Exponentes.begin(), Exponentes.end());*/
    if(Fin) return 1;
    if(v > b) return 0;
    if(i >= n and b == v){
        //cerr<<"Fin.\n";
        Fin = 1;
        reverse(all(Exponentes));
        for(auto E: Exponentes) cout<<E<<" ";
        cout<<el;
        Resultado = Exponentes;
        return 1;
    }
    if(n <= i) return 0;
    int Falta = int((b - v) / Potencias_de_diez[i]) % 10, d = a[i] - '0', Posici_n_del_ciclo;
    //cerr<<Falta<<" "<<d<<" "<<b - v<<el;
    if(Falta == 1){
        if(Falta == 1 or Falta == 3 or Falta == 7 or Falta == 9){
            for(Exponentes[i] = 0; Exponentes[i] < int(Potencias_previas[d].size()) and !Fin; Exponentes[i] += Ciclos[d]){
                //cerr<<v<<" "<<v + Potencias_previas[d][Exponentes[i]] * Potencias_de_diez[i]<<" "<<b<<el;
                if(Fin) return 1;
                if(v + Potencias_previas[d][Exponentes[i]] * Potencias_de_diez[i] > b) return 0;
                //cerr<<"¿Llego?\n";
                if(Resolver(Exponentes, i + 1, v + Potencias_previas[d][Exponentes[i]] * Potencias_de_diez[i])) return 1;
            }
        } else {
            Exponentes[i] = 0;
            if(Fin) return 1;
            if(v + Potencias_previas[d][Exponentes[i]] * Potencias_de_diez[i] > b) return 0;
            //cerr<<"¿Llego?\n";
            if(Resolver(Exponentes, i + 1, v + Potencias_previas[d][Exponentes[i]] * Potencias_de_diez[i])) return 1;
        }
    } else {
        for(Posici_n_del_ciclo = 0; Posici_n_del_ciclo < Ciclos[d]; Posici_n_del_ciclo++){
            if(Valores[d][Posici_n_del_ciclo] == Falta){
                break;
            }
        }
        //cerr<<Posici_n_del_ciclo<<el;
        if(Posici_n_del_ciclo == Ciclos[d]){
            return 0;
        }
        for(Exponentes[i] = Posici_n_del_ciclo + 1; Exponentes[i] < int(Potencias_previas[d].size()) and !Fin; Exponentes[i] += Ciclos[d]){
            //cerr<<v<<" "<<v + Potencias_previas[d][Exponentes[i]] * Potencias_de_diez[i]<<" "<<b<<el;
            if(Fin) return 1;
            if(v + Potencias_previas[d][Exponentes[i]] * Potencias_de_diez[i] > b) return 0;
            //cerr<<"¿Llego?\n";
            if(Resolver(Exponentes, i + 1, v + Potencias_previas[d][Exponentes[i]] * Potencias_de_diez[i])) return 1;
        }
    }
    if(Fin) return 1;
    return 0;
}
ll Potenciar(ll b, int e){
    if(e == 0) return 1LL;
    if(e == 1) return b;
    ll a = Potenciar(b, e>>1);
    a = a * a * Potenciar(b, e & 1);
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    cerr<<a<<" "<<b<<el;
    if(a == "0"){
        cout<<"1 \n";
        return 0;
    }
    n = int(a.size());
    forn(i, 10){
        if(i == 0){
            Potencias_previas[i].pb(0LL);
            Potencias_previas[i].pb(0LL);
        }
        if(i == 1){
            Potencias_previas[i].pb(1LL);
            Potencias_previas[i].pb(1LL);
        }
        if(i <= 1) continue;
        Potencias_previas[i].push_back(1LL);
        while(Potencias_previas[i].back() <= b){
            Potencias_previas[i].pb(Potencias_previas[i].back() * (ll)i);
        }
    }
    /*for(auto E: Potencias_previas){
        for(auto e: E) cerr<<e<<" ";
        cerr<<"\n";
    }*/
    forsn(i, 1, n + 2) Potencias_de_diez.pb(Potencias_de_diez[i - 1] * 10LL);
    reverse(all(a));
    bool aaaa = Resolver(vi(n, 1), 0, 0LL);
    return 0;
    ll Contador = 0;
    reverse(all(Resultado));
    forn(i, n){
        Contador += Potencias_de_diez[i] * Potenciar((ll)(a[i] - '0'), Resultado[i]);
    }
    //cerr<<"Terminé.\n"<<a;
    //cin>>n;
    bool Bien = Contador == b;
    /*vi Verdadero;
    forn(i, n){
        int vvvv;
        cin>>vvvv;
        Verdadero.pb(vvvv);
        //cerr<<vvvv<<" "<<Resultado[i]<<el;
        if(vvvv != Resultado[i]) Bien = 0;
    }*/
    cout<<(Bien ? "Bien." : "Mal.")<<"\n";
    if(!Bien){
        cerr<<"------------------------------------------\nMAL.\n------------------------------------------\n";
        reverse(all(a));
        reverse(all(Resultado));
        cout<<a<<" "<<b<<el;
        for(auto E: Resultado) cout<<E<<" ";
        cout<<el;
    }
    return 0;
}