#include "bits/stdc++.h"
#define ii pair<int, int>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define el "\n"
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
string n;
vector< vector< vector< vector<ll> > > > PD;
string Cadena(ll a){
    stringstream c;
    string r;
    c<<a;
    c>>r;
    return r;
}
ll Resolver(int i, int Libre, int Usado, int Usar_cero){
    //cerr<<i<<" "<<Libre<<" "<<Usado<<" "<<Usar_cero<<" "<<n<<el;
    if(Usado > 3) return 0LL;
    if(i == int(n.size())) return (ll)Usar_cero;
    if(PD[i][Libre][Usado][Usar_cero] != -2LL) return PD[i][Libre][Usado][Usar_cero];
    ll Retorno = 0;
    if(Libre == 0){
        forn(j, n[i] - '0' + 1){
            Retorno += Resolver(i + 1, (j < (n[i] - '0')) ? 1 : 0, Usado + ((j > 0) ? 1 : 0), (Usar_cero == 1 or j > 0) ? 1 : 0);
        }
    } else {
        forn(j, 10){
            Retorno += Resolver(i + 1, 1, Usado + ((j > 0) ? 1 : 0), (Usar_cero == 1 or j > 0) ? 1 : 0);
        }
    }
    return PD[i][Libre][Usado][Usar_cero] = Retorno;
}
void Resolver(){
    ll l, r;
    cin>>l>>r;
    l--;
    n = Cadena(r);
    PD.assign(int(n.size()), vector< vector< vector<ll> > >(2, vector< vector<ll> >(4, vector<ll>(2, -2LL))));
    ll Respuesta = Resolver(0, 0, 0, 0);
    if(l > 0LL){
        n = Cadena(l);
        PD.assign(int(n.size()), vector< vector< vector<ll> > >(2, vector< vector<ll> >(4, vector<ll>(2, -2LL))));
        Respuesta -= Resolver(0, 0, 0, 0);
    }
    cout<<Respuesta<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}