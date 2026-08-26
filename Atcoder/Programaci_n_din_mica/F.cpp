#include "bits/stdc++.h"
using namespace std;
int n, m;
string s, t;
struct Valor{
    int Mayor, Ir_s, Ir_t;
    bool Tomado;
    Valor(int a, int b, int c, bool d){
        Mayor = a;
        Ir_s = b;
        Ir_t = c;
        Tomado = d;
    }
    Valor operator+(const int& a){
        return Valor(Mayor + a, Ir_s, Ir_t, Tomado);
    }
    bool operator<(const Valor& a){
        return Mayor < a.Mayor;
    }
    bool operator>(const Valor& a){
        return Mayor > a.Mayor;
    }
};
vector< vector<Valor> > PD;
vector< vector<int> > Posiciones;
Valor Resolver(int i, int j){
    if(i >= n or j >= m) return Valor(1, n + 22, m + 22, 0);
    if(PD[i][j].Mayor != -2) return PD[i][j];
    PD[i][j] = Valor(Resolver(i + 1, j).Mayor, i + 1, j, 0);
    int c = *lower_bound(Posiciones[s[i] - 'a' + 22].begin(), Posiciones[s[i] - 'a' + 22].end(), j + 1);
    //cerr<<i<<" "<<j<<"\n";
    if(c < m and Resolver(i + 1, c) + 1 > PD[i][j]){
        //cerr<<i<<" "<<j<<" Posiciones 1.\n";
        PD[i][j] = Valor(Resolver(i + 1, c).Mayor + 1, i + 1, c, 1);
        //cerr<<i<<" "<<j<<"\n";
        //cerr<<i<<" "<<j<<" Posiciones 2.\n";
    }
    //cerr<<i<<" "<<j<<"\n";
    //cerr<<s[i]<<" "<<t[j]<<" "<<i<<" "<<j<<" van a "<<PD[i][j].Ir_s<<" "<<PD[i][j].Ir_t<<" con "<<PD[i][j].Mayor<<" y "<<PD[i][j].Tomado<<".\n";
    return PD[i][j];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>t;
    t = " " + t;
    n = s.size();
    m = t.size();
    PD.assign(n, vector<Valor>(m, Valor(-2, -2, -2, 0)));
    Posiciones.assign(222, {});
    for(int i = 1; i < m; i++) Posiciones[t[i] - 'a' + 22].push_back(i);
    for(int i = 0; i < 222; i++) Posiciones[i].push_back(m + 22);
    int Mejor = -2, p0 = -2, p1 = -2, Ir = 0;
    for(int i = 0; i < n; i++){
        int c = *lower_bound(Posiciones[s[i] - 'a' + 22].begin(), Posiciones[s[i] - 'a' + 22].end(), 0);
        //cerr<<i<<" "<<c<<"\n";
        if(c < m and Resolver(i, 0).Mayor > Mejor){
            Mejor = Resolver(i, 0).Mayor;
            p0 = i;
            p1 = 0;
        }
    }
    string r = "";
    if(Mejor == -2){
        cout<<r;
        return 0;
    }
    for(; p0 < n; ){
        while(p0 < n){
            if(Resolver(p0, p1).Tomado) break;
            int c0 = p0, c1 = p1;
            p0 = Resolver(c0, c1).Ir_s;
            p1 = Resolver(c0, c1).Ir_t;
        }
        if(p0 >= n) break;
        r += s[p0];
        int c0 = p0, c1 = p1;
        p0 = Resolver(c0, c1).Ir_s;
        p1 = Resolver(c0, c1).Ir_t;
    }
    cout<<r;
    return 0;
}