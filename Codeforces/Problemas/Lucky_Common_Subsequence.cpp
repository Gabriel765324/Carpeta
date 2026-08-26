#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define ll long long
#define el "\n"
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using namespace std;
struct Tres{
    int i, j, k;
    Tres(){}
    Tres(int I, int J, int K){
        i = I;
        j = J;
        k = K;
    }
    bool operator!=(const Tres& a) const{
        return i != a.i or j != a.j or k != a.k;
    }
};
struct Valor{
    int v;
    Tres Entrada, Siguiente;
    Valor(){}
    Valor(int V, Tres E, Tres S){
        v = V;
        Entrada = E;
        Siguiente = S;
    }
    bool operator<(const Valor& a) const{
        return v < a.v;
    }
    bool operator<=(const Valor& a) const{
        return v <= a.v;
    }
    bool operator>(const Valor& a) const{
        return v > a.v;
    }
    bool operator>=(const Valor& a) const{
        return v > a.v;
    }
    Valor operator+(const int& a) const{
        return Valor(this->v + a, this->Entrada, this->Siguiente);
    }
};
int n, m, o;
string a, b, c;
vector< vi > No_z;
Valor Nulo = Valor(INT_MIN, Tres(INT_MIN, INT_MIN, INT_MIN), Tres(INT_MIN, INT_MIN, INT_MIN));
vector< vector< vector<Valor> > > PD;
Valor Resolver(int i, int j, int k){
    if(k == o) return Valor(INT_MIN, Tres(i, j, k), Tres(INT_MIN, INT_MIN, INT_MIN));
    if(i == n or j == m) return Valor(0, Tres(i, j, k), Tres(INT_MIN, INT_MIN, INT_MIN));
    if(PD[i][j][k].v != Nulo.v) return PD[i][j][k];
    if(a[i] == b[j]){
        if(a[i] == c[k]){
            Valor _0 = Resolver(i + 1, j + 1, k + 1), _1 = Resolver(i + 1, j, k);
            if(_0.v == INT_MIN and _1.v == INT_MIN) return Valor(INT_MIN + 22, Tres(i, j, k), _1.Entrada);
            if(_0.v == INT_MIN) return PD[i][j][k] = Valor(_1.v, Tres(i, j, k), _1.Entrada);
            if(_1.v == INT_MIN) return PD[i][j][k] = Valor(_0.v + 1, Tres(i, j, k), _0.Entrada);
            if((_0 + 1) > _1) return PD[i][j][k] = Valor(_0.v + 1, Tres(i, j, k), _0.Entrada);
            else return PD[i][j][k] = Valor(_1.v, Tres(i, j, k), _1.Entrada);
        }
        Valor _0 = Resolver(i + 1, j + 1, No_z[k][a[i] - 'A']), _1 = Resolver(i + 1, j, k);
        if(_0.v == INT_MIN and _1.v == INT_MIN) return Valor(INT_MIN + 22, Tres(i, j, k), _1.Entrada);
        if(_0.v == INT_MIN) return PD[i][j][k] = Valor(_1.v, Tres(i, j, k), _1.Entrada);
        if(_1.v == INT_MIN) return PD[i][j][k] = Valor(_0.v + 1, Tres(i, j, k), _0.Entrada);
        if((_0 + 1) > _1) return PD[i][j][k] = Valor(_0.v + 1, Tres(i, j, k), _0.Entrada);
        else return PD[i][j][k] = Valor(_1.v, Tres(i, j, k), _1.Entrada);
    }
    Valor r = Resolver(i + 1, j, k);
    Valor _0 = Valor(r.v, Tres(i, j, k), r.Entrada);
    if(_0.v == INT_MIN) _0.v += 22;
    return PD[i][j][k] = _0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c;
    n = int(a.size());
    m = int(b.size());
    o = int(c.size());
    No_z.assign(o, vi(26, 0));
    string s = "" + c[0];
    forsn(i, 1, o){
        forsn(j, 'A', 'Z' + 1){
            s += char(j);
            vi Prefijos(i + 1, 0);
            forsn(k, 1, i + 1){
                int p = Prefijos[k - 1];
                while(p > 0 and s[k] != s[p]) p = Prefijos[p - 1];
                if(s[p] == s[k]) p++;
                Prefijos[k] = p;
            }
            No_z[i][j - 'A'] = Prefijos.back();
            s.pop_back();
        }
    }
    PD.assign(n, vector< vector<Valor> >(m, vector<Valor>(o, Nulo)));
    Valor Mejor = Resolver(0, 0, 0);
    forn(i, m) Mejor = max(Mejor, Resolver(0, i, 0));
    cerr<<Mejor.v<<el;
    if(Mejor.v <= 0){
        cout<<0;
        return 0;
    }
    s = "";
    for(Tres p = Mejor.Entrada; p.i < n and p.j < m and p.k < o;){
        cerr<<PD[p.i][p.j][p.k].v<<" "<<p.i<<" "<<p.j<<" "<<p.k<<el;
        Tres Siguiente = PD[p.i][p.j][p.k].Siguiente;
        if(p.j < Siguiente.j) s += a[p.i];
        p = Siguiente;
    }
    cout<<s;
    return 0;
}