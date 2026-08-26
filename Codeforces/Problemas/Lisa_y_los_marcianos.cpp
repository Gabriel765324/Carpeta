#include "bits/stdc++.h"
#define el "\n"
#define ll long long
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
int M_scara;
struct Soluci_n{
    int i, j, _0, _1;
    Soluci_n(int a, int b, int __0, int __1){
        i = a;
        j = b;
        _0 = __0;
        _1 = __1;
    }
    bool operator<(const Soluci_n& a) const{
        return mp((~(_0 ^ _1)) & M_scara, mp(i, j)) < mp((~(a._0 ^ a._1)) & M_scara, mp(a.i, a.j));
    }
    bool operator<=(const Soluci_n& a) const{
        return (*this < a) or mp(mp(_0, _1), mp(i, j)) == mp(mp(a._0, a._1), mp(i, j));
    }
    bool operator>(const Soluci_n& a) const{
        return !(*this <= a);
    }
    bool operator>=(const Soluci_n& a) const{
        return !(*this < a);
    }
};
struct Valor{
    int v, i;
    Valor(){}
};
Soluci_n Solucionar(vector<Valor>& a, int Capa){
    int n = int(a.size());
    if(Capa < 0){
        return Soluci_n(a[0].i, a[1].i, a[0].v, a[1].v);
    }
    vector< vector<Valor> > Nuevo(2);
    forn(i, n){
        Nuevo[((a[i].v & (1<<Capa)) == 0) ? 0 : 1].pb(a[i]);
    }
    int i = int(Nuevo[0].size()), j = int(Nuevo[1].size());
    if(i == 1 and j == 1){
        return Soluci_n(Nuevo[0][0].i, Nuevo[1][0].i, Nuevo[0][0].v, Nuevo[1][0].v);
    }
    if(i >= 2 and j <= 1){
        return Solucionar(Nuevo[0], Capa - 1);
    }
    if(i <= 1 and j >= 2){
        return Solucionar(Nuevo[1], Capa - 1);
    }
    return max(Solucionar(Nuevo[0], Capa - 1), Solucionar(Nuevo[1], Capa - 1));
}
void Resolver(){
    int n, k;
    cin>>n>>k;
    vector<Valor> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].v;
        a[i].i = i;
    }
    M_scara = (1<<k) - 1;
    Soluci_n r = Solucionar(a, k - 1);
    int x = 0;
    forn(i, k){
        if(((r._0 & (1<<i)) == 0) and ((r._1 & (1<<i)) == 0)) x += (1<<i);
    }
    //cout<<"--------\n";
    cout<<r.i + 1<<" "<<r.j + 1<<" "<<x<<el;
    //cout<<r._0<<" "<<r._1<<" "<<x<<" "<<((r._0 ^ x) & (r._1 ^ x))<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}