#include "bits/stdc++.h"
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define ll long long
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
ll m = 998244353;
struct M_dulo{
    long long v;
    M_dulo(){
        v = 0;
    }
    M_dulo(ll V){
        v = (V % m + m) % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo((v % m + a.v % m) % m);
    }
    M_dulo operator-(const M_dulo& a){
        return M_dulo(((v % m - a.v % m) % m + m) % m);
    }
};
const int MAYOR = 1e6 + 22;
int Criba[MAYOR] = {};
void Cribear(){
    Criba[0] = -2;
    Criba[1] = -2;
    for(ll i = 2; i < (ll)MAYOR; i++){
        if(Criba[i] == 0){
            Criba[i] = (int)i;
            for(ll j = i * i; j < (ll)MAYOR; j += i){
                if(Criba[j] == 0) Criba[j] = (int)i;
            }
        }
    }
}
int Potencia(int b, int e){
    if(e == 0) return 1;
    if(e == 1) return b;
    int a = Potencia(b, e / 2);
    return a * a * Potencia(b, e & 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Cribear();
    int n;
    cin>>n;
    vi a(n);
    forn(i, n) cin>>a[i];
    vector<M_dulo> Mapa(1e6 + 22, M_dulo(0)), PD(n, M_dulo(0));
    PD[0] = M_dulo(1);
    vi Primos;
    while(Criba[a[0]] != -2 and a[0] > 1){
        int c = Criba[a[0]];
        while(Criba[a[0]] == c){
            a[0] /= c;
        }
        Primos.pb(c);
    }
    forsn(Tomo, 1, (1<<(int)(Primos.size()))){
        int d = 1;
        forn(j, Primos.size()){
            if(Tomo & (1<<j)){
                d *= Primos[j];
            }
        }
        Mapa[d] = Mapa[d] + PD[0];
    }
    forsn(i, 1, n){
        Primos.clear();
        while(Criba[a[i]] != -2 and a[i] > 1){
            int c = Criba[a[i]];
            while(Criba[a[i]] == c){
                a[i] /= c;
            }
            Primos.pb(c);
        }
        vi Divisores;
        forsn(Tomo, 1, (1<<(int)(Primos.size()))){
            int d = 1;
            bool Impar = 0;
            forn(j, Primos.size()){
                if(Tomo & (1<<j)){
                    d *= Primos[j];
                    Impar = !Impar;
                }
            }
            if(Impar) PD[i] = PD[i] + Mapa[d];
            else PD[i] = PD[i] - Mapa[d];
            Divisores.pb(d);
        }
        for(auto E: Divisores){
            Mapa[E] = Mapa[E] + PD[i];
        }
    }
    cout<<PD.back().v;
    return 0;
}