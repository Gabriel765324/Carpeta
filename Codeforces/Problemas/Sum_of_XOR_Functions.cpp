#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define di deque<int>
#define pb push_back
#define pf push_front
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define el "\n"
using namespace std;
const ll m = 998244353;
struct Modular{
    ll v;
    Modular(){
        v = 0LL;
    }
    Modular(ll a){
        v = (a + m) % m;
    }
    Modular operator+(const Modular& a) const{
        return Modular(v % m + a.v % m);
    }
    Modular operator-(const Modular& a) const{
        return Modular(v % m - a.v % m);
    }
    Modular operator*(const Modular& a) const{
        return Modular(v % m * a.v % m);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n), XORi(n, 0LL), XORd(n + 1, 0LL);
    forn(i, n){
        cin>>a[i];
        XORi[i] ^= a[i];
        if(i > 0) XORi[i] ^= XORi[i - 1];
    }
    for(int i = n - 1; i > -1; i--){
        XORd[i] ^= a[i] ^ XORd[i + 1];
    }
    Modular v = Modular();
    for(ll b = 0LL; b <= 34LL; b++){
        vector< vector<Modular> > Acumular_i(2, vector<Modular>(n, Modular())), Acumular_d(2, vector<Modular>(n, Modular()));
        forn(i, n){
            Acumular_i[(a[i] & (1LL<<b)) ? 1 : 0][i] = Modular(1LL);
            Acumular_d[(a[i] & (1LL<<b)) ? 1 : 0][i] = Modular(1LL);
        }
        Modular Contador = Modular(), Valor = Modular();
        int Capa = 0;
        forn(i, n){
            if(a[i] & (1LL<<b)){
                Capa = 1 - Capa;
            }
            if(Acumular_i[Capa][i].v >= 1LL){
                Contador = Contador + Modular(1LL);
            }
            Valor = Valor + Contador;
            Acumular_i[Capa][i] = Valor;
        }
        Contador = Modular(), Valor = Modular();
        Capa = 1;
        forn(i, n){
            if(a[i] & (1LL<<b)){
                Capa = 1 - Capa;
            }
            if(Acumular_i[Capa][i].v >= 1LL){
                Contador = Contador + Modular(1LL);
            }
            Valor = Valor + Contador;
            Acumular_i[Capa][i] = Valor;
        }
        Contador = Modular(), Valor = Modular();
        Capa = 0;
        for(int i = n - 1; i > -1; i--){
            if(a[i] & (1LL<<b)){
                Capa = 1 - Capa;
            }
            if(Acumular_d[Capa][i].v >= 1LL){
                Contador = Contador + Modular(1LL);
            }
            Valor = Valor + Contador;
            Acumular_d[Capa][i] = Valor;
        }
        Contador = Modular(), Valor = Modular();
        Capa = 1;
        for(int i = n - 1; i > -1; i--){
            if(a[i] & (1LL<<b)){
                Capa = 1 - Capa;
            }
            if(Acumular_d[Capa][i].v >= 1LL){
                Contador = Contador + Modular(1LL);
            }
            Valor = Valor + Contador;
            Acumular_d[Capa][i] = Valor;
        }
        forn(i, n){
            /*Capa = (a[i] & (1LL<<b)) ? 1 : 0;
            cerr<<Acumular_i[Capa][i].v<<" "<<Acumular_d[Capa][i].v<<el;
            v = v + Acumular_i[Capa][i] * Acumular_d[Capa][i] * Modular(1LL<<b);*/
            if(a[i] & (1LL<<b)){
                v = v + Acumular_i[1][i] * Acumular_d[1][i] * Modular(1LL<<b);
            }
        }
        //cerr<<el;
        /*Modular ci0 = Modular(), ci1 = Modular(), cd0 = Modular(), cd1 = Modular();
        Modular vpi0 = Modular(), vpi1 = Modular(), vpd0 = Modular(), vpd1 = Modular();
        //deque<Modular> Posiciones;
        //vector<Modular> Acumular_0_i(n, Modular()), Acumular_0_d(n, Modular()), Acumular_1_i(n, Modular()), Acumular_1_d(n, Modular());
        forn(i, n){
            if(((1LL<<b) & XORi[i]) > 0LL){
                cd1 = cd1 + Modular(1LL);
                vpd1 = vpd1 + Modular((ll)(i + 1));
                //cerr<<i + 1<<el;
            } else {
                cd0 = cd0 + Modular(1LL);
                vpd0 = vpd0 + Modular((ll)(i + 1));
            }
        }
        //Modular ct1 = cd1, ct0 = cd0;
        forn(i, n){
            if((XORi[i] & (1LL<<b)) == 0LL){
                v = v + (vpi1 + vpd1) * Modular(1LL<<b);
                vpi1 = vpi1 + ci1;
                ci1 = ci1 + Modular(1LL);
                vpd1 = vpd1 - cd1;
                cd1 = cd1 - Modular(1LL);
            } else {
                v = v + (vpi0 + vpd0) * Modular(1LL<<b);
                vpi0 = vpi0 + ci0;
                ci0 = ci0 + Modular(1LL);
                vpd0 = vpd0 - cd0;
                cd0 = cd0 - Modular(1LL);
            }
            v = v + Modular(1LL);*/
            /*if(a[i] & (1LL<<b)){
                swap(ci0, ci1);
                swap(vpi0, vpi1);
            }
            ci1 = ci1 + Modular(1LL);
            vpi1 = vpi1 + ci1;
            v = v + vpi1 * vpd1 * Modular(1LL<<b);*/
            /*cerr<<"--------\n"<<vpi1.v<<" "<<vpd1.v<<el;
            cerr<<vpi0.v<<" "<<vpd0.v<<el;*/
            //cerr<<(vpi1 * vpd1 * Modular(1LL<<b)).v<<el<<"--------\n";
            /*if(a[i] & (1LL<<b)){
                swap(cd0, cd1);
                swap(vpd0, vpd1);
            }
            vpd1 = vpd1 - cd1;
            cd1 = cd1 - Modular(1LL);*/
        //}
    }
    cout<<v.v;
    return 0;
}