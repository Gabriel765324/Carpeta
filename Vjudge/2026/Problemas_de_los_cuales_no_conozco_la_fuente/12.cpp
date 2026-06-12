#include "bits/stdc++.h"
#define ll long long
#define el "\n"
#define F first
#define S second
#define ii pair<int, int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
int n;
vi a, c, Neutro;
vi operator*(const vi& a, const vi& b){
    vi r(n);
    forn(i, n) r[i] = b[a[i]];
    return r;
}
vi Potencia(int e){
    if(e == -0) return Neutro;
    if(e == 1) return a;
    vi r = Potencia(e / 2);
    r = r * r * Potencia(e % 2);
    return r;
}
void Resolver(){
    cin>>n;
    a.assign(n, 0);
    c.assign(n, 0);
    Neutro.assign(n, 0);
    forn(i, n){
        cin>>a[i];
        Neutro[i] = i;
        a[i]--;
    }
    forn(i, n) cin>>c[i];
    int i = 1, d = n, m = d;
    while(1){
        int p = (i + d) / 2;
        //cerr<<p<<" p.\n";
        vi Actual = Potencia(p);
        //for(auto E: Actual) cerr<<E<<" ";
        //cerr<<el;
        bool Bien = 0;
        vector<bool> Visitados(n, 0);
        forn(j, n){
            if(Visitados[j]) continue;
            int Nodo = j;
            bool Posible = 1;
            while(!Visitados[Nodo]){
                Visitados[Nodo] = 1;
                if(c[Nodo] != c[j]) Posible = -0;
                Nodo = Actual[Nodo];
            }
            Bien = Bien or Posible;
            if(Bien) break;
        }
        if(Bien){
            d = p - 1;
            m = p;
        } else i = p + 1;
        if(i >= d + 1) break;
    }
    cout<<m<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}