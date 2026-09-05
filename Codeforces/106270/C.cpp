#include "bits/stdc++.h"
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
struct Tres{
    int a, b, c, v;
    Tres(){}
    Tres(int X, int Y, int Z, int V){
        a = X;
        b = Y;
        c = Z;
        v = V;
    }
    bool operator==(const Tres& x){
        return mp(a, mp(b, c)) == mp(x.a, mp(x.b, x.c));
    }
    bool operator!=(const Tres& x){
        return mp(a, mp(b, c)) != mp(x.a, mp(x.b, x.c));
    }
};
struct Tr_o{
    int a, b, c;
    Tr_o(int A, int B, int C){
        a = A;
        b = B;
        c = C;
    }
    Tr_o(Tres x){
        a = x.a;
        b = x.b;
        c = x.c;
    }
    bool operator==(const Tres& x){
        return mp(mp(a, b), c) == mp(mp(x.a, x.b), x.c);
    }
    bool operator<(const Tr_o& x) const{
        return mp(mp(a, b), c) < mp(mp(x.a, x.b), x.c);
    }
};
vector< vector< vector<Tres> > > Representantes;
Tres Buscar(Tres a){
    if(Representantes[a.a][a.b][a.c] == a) return Representantes[a.a][a.b][a.c];
    return Representantes[a.a][a.b][a.c] = Buscar(Representantes[a.a][a.b][a.c]);
}
void Unir(Tres a, Tres b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        if(a.v < b.v) swap(a, b);
        Representantes[a.a][a.b][a.c].v += Representantes[b.a][b.b][b.c].v;
        a.v = Representantes[a.a][a.b][a.c].v;
        Representantes[b.a][b.b][b.c] = a;
    }
}
void Resolver(){
    int x, y, z;
    cin>>x>>y>>z;
    Representantes.assign(z, vector< vector<Tres> >(x, vector<Tres>(y)));
    vector< vector<string> > Grilla(z, vector<string>(x));
    forn(i, z) forn(j, x) cin>>Grilla[i][j];
    forn(i, z){
        forn(j, x){
            forn(k, y){
                Representantes[i][j][k] = Tres(i, j, k, Grilla[i][j][k] == '.' ? 1 : 0);
            }
        }
    }
    vi ca = {1, -1, 0, 0, 0, 0};
    vi cb = {0, 0, 1, -1, 0, 0};
    vi cc = {0, 0, 0, 0, 1, -1};
    forn(i, z){
        forn(j, x){
            forn(k, y){
                Tres Actual = Buscar(Tres(i, j, k, 0));
                if(Grilla[Actual.a][Actual.b][Actual.c] == '#') continue;
                forn(l, 6){
                    Tres Siguiente = Tres(i + ca[l], j + cb[l], k + cc[l], 0);
                    if(Siguiente.a >= z or Siguiente.a < 0) continue;
                    if(Siguiente.b >= x or Siguiente.b < 0) continue;
                    if(Siguiente.c >= y or Siguiente.c < 0) continue;
                    if(Grilla[Siguiente.a][Siguiente.b][Siguiente.c] == '#') continue;
                    Siguiente = Buscar(Siguiente);
                    Unir(Actual, Siguiente);
                }
            }
        }
    }
    int Mejor = 0;
    forn(i, x){
        forn(j, y){
            set<Tr_o> Hay;
            int Posible = 0;
            forn(k, z){
                if(Grilla[k][i][j] == '#') continue;
                Tres Actual = Buscar(Tres(k, i, j, 0));
                if(Hay.find(Tr_o(Actual)) == Hay.end()){
                    Hay.insert(Tr_o(Actual));
                    Posible += Actual.v;
                }
            }
            Mejor = max(Mejor, Posible);
        }
    }
    cout<<Mejor<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}