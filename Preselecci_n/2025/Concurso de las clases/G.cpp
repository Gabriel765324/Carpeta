#include "bits/stdc++.h"
using namespace std;
long long Final, n;
vector< vector<long long> > Resolver;
long long Caminos(long long p, long long Cambios){
    if(Cambios <= -1 and p == Final + 22) return 1;
    if(Cambios <= -1) return 0;
    if(Resolver[p][Cambios] != -2) return Resolver[p][Cambios];
    return Resolver[p][Cambios] = Caminos(p - 1, Cambios - 1) + Caminos(p + 1, Cambios - 1);
}
long long Potencia(long long b, long long e){
    if(e == 0) return 1;
    if(e == 1) return b;
    long long a = Potencia(b, e / 2);
    a *= a * Potencia(b, e % 2);
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin>>s>>t;
    n = s.size();
    long long p = 0;
    for(long long i = 0; i < n; i++){
        if(s[i] == '+') p++;
        else p--;
    }
    Final = p;
    p = 0;
    long long Cambios = 0;
    for(long long i = 0; i < n; i++){
        if(t[i] == '+') p++;
        else if(t[i] == '-') p--;
        else Cambios++;
    }
    Resolver.assign(44, vector<long long>(Cambios, -2));
    long long Bien = Caminos(22 + p, Cambios - 1);
    long long Mal = Potencia(2, Cambios);
    cout<<setprecision(22)<<(double)Bien / (double)Mal;
    return 0;
}