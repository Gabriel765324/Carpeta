#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define el "\n"
typedef unsigned int ui;
using namespace std;
const ll M_dulo = 1000000007LL;
struct Modular{
    ll v;
    Modular(){
        v = 0LL;
    }
    Modular(ll a){
        v = a;
    }
    Modular operator+(const Modular& o){
        return Modular((v + o.v) % M_dulo);
    }
};
vector< vector< vector< vector< vector< pair<Modular, bitset<1> > > > > > > Memoria;
vector<string> Mapa;
int n, m;
vector<ui> Cerear;
bitset<1> Bien;
Modular Resolver(ui M_scara, int i, int j, int Vigilado, int Libre){
    if(j >= m) return Modular(1LL);
    if(i >= n) return Resolver(M_scara, 0, j + 1, 0, Libre);
    if(i == 0) M_scara &= Cerear[j];
    if(Memoria[M_scara][i][j][Vigilado][Libre].S[0]) return Memoria[M_scara][i][j][Vigilado][Libre].F;
    Modular Respuesta;
    if(Mapa[i][j] == 'x'){
        Respuesta = Resolver(M_scara, i + 1, j, 0, Libre);
        Memoria[M_scara][i][j][Vigilado][Libre] = mp(Respuesta, Bien);
        return Respuesta;
    }
    Respuesta = Resolver(M_scara | ((ui)1<<(ui)i), i + 1, j, 1, Libre);
    if(Vigilado == 1 or (M_scara & ((ui)1<<(ui)i))) Respuesta = Respuesta + Resolver(M_scara, i + 1, j, Vigilado, Libre);
    else if(Vigilado == 0 and Libre == 1 and ((M_scara & ((ui)1<<(ui)i)) == (ui)0)) Respuesta = Respuesta + Resolver(M_scara, i + 1, j, 0, 0);
    Memoria[M_scara][i][j][Vigilado][Libre] = mp(Respuesta, Bien);
    return Respuesta;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Bien[0] = 1;
    cin>>n>>m;
    Mapa.assign(n, "");
    forn(i, n) cin>>Mapa[i];
    if(m < n){
        vector<string> MapaT(m, string(n, ' '));
        forn(i, n){
            forn(j, m){
                MapaT[j][i] = Mapa[i][j];
            }
        }
        swap(MapaT, Mapa);
        swap(n, m);
    }
    Cerear.assign(m, (ui)((1<<n) - 1));
    forn(i, m){
        forn(j, n){
            Cerear[i] ^= ((ui)1<<(ui)(j)) * (Mapa[j][i] == 'x' ? (ui)1 : (ui)0);
        }
    }
    bitset<1> Nada;
    Memoria.assign(1<<n, vector< vector< vector< vector< pair<Modular, bitset<1> > > > > >(n, vector< vector< vector< pair<Modular, bitset<1> > > > >(m, vector< vector< pair<Modular, bitset<1> > > >(2, vector< pair<Modular, bitset<1> > >(2, mp(Modular(0LL), Nada))))));
    cout<<Resolver((ui)0, 0, 0, 0, 1).v % M_dulo;
    return 0;
}