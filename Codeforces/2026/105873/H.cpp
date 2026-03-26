#include "bits/stdc++.h"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i< int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define el "\n"
#define pb push_back
#define mp make_pair
using namespace std;
int n;
struct Encargo{
    long long L_mite, Tiempo;
    double Recompensa, Bono_esperado, Inicio, Final;
    Encargo(long long l, double r, long long t, double ib, double fb, double i, double f){
        L_mite = l;
        Recompensa = r;
        Tiempo = t;
        Bono_esperado = (ib + fb) / (double)2;
        Inicio = i;
        Final = f;
    }
};
vector<Encargo> a;
vector<double> PD;
double Resolver(unsigned int M_scara, long long Tiempo){
    if(__popcount(M_scara) == n) return 0;
    if(PD[M_scara] >= (double)0) return PD[M_scara];
    vector<unsigned int> Posibles;
    forn(i, n){
        if((M_scara & (1<<i)) == 0){
            Posibles.pb(i);
        }
    }
    for(auto E: Posibles){
        double Extra = 0;
        if(Tiempo + a[E].Tiempo <= a[E].L_mite) Extra += a[E].Recompensa;
        else continue;
        if(Tiempo + a[E].Tiempo <= round(a[E].Inicio)) Extra += a[E].Bono_esperado;
        else if(Tiempo + a[E].Tiempo > a[E].Inicio and Tiempo + a[E].Tiempo <= a[E].Final){
            Extra += a[E].Bono_esperado * ((double)1 - ((double)(Tiempo + a[E].Tiempo - a[E].Inicio) / (a[E].Final - a[E].Inicio)));
        }
        PD[M_scara] = max(PD[M_scara], Resolver(M_scara + (1<<E), Tiempo + a[E].Tiempo) + Extra);
    }
    if(PD[M_scara] < 0) PD[M_scara] = 0;
    return PD[M_scara];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    PD.assign(1<<n, -22);
    forn(i, n){
        long long l, t;
        double r, ib, fb, I, f;
        cin>>l>>r>>t>>ib>>fb>>I>>f;
        a.pb(Encargo(l, r, t, ib, fb, I, f));
    }
    cout<<setprecision(22)<<Resolver((unsigned int)0, 0);
    return 0;
}