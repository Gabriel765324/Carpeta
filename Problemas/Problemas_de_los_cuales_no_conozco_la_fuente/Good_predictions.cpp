#include "bits/stdc++.h"
#define ll long long
#define pb push_back
using namespace std;
const ll m = 1000000007;
struct M_dulo{
    ll v;
    M_dulo(){}
    M_dulo(ll a){
        v = a % m;
    }
    M_dulo operator*(const M_dulo& o){
        return M_dulo(v % m * o.v % m);
    }
    M_dulo Potencia(int e){
        if(e == 0) return M_dulo(1LL);
        if(e == 1) return *this;
        M_dulo a = Potencia(e >> 1);
        a = a * a * Potencia(e & 1);
        return a;
    }
    M_dulo operator/(const M_dulo& o){
        M_dulo Copia = o;
        return M_dulo(v % m * Copia.Potencia((int)m - 2).v % m);
    }
};
vector<M_dulo> Factoriales;
M_dulo Factorial(int i){
    while(i >= int(Factoriales.size())){
        if(Factoriales.empty()) Factoriales.pb(M_dulo(1LL));
        else Factoriales.pb(M_dulo((ll)Factoriales.size()) * Factoriales.back());
    }
    return Factoriales[i];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<<(Factorial(a) / (Factorial(b) * Factorial(c) * Factorial(d))).v<<"\n";
    return 0;
}