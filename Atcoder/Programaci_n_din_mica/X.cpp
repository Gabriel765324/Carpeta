#include "bits/stdc++.h"
using namespace std;
struct Bloque{
    long long Valor;
    int Peso, Soporte;
    Bloque(int p, int s, long long v){
        Peso = p;
        Soporte = s;
        Valor = v;
    }
};
bool o0(const Bloque& a, const Bloque& b){
    if(a.Soporte > b.Soporte) return 1;
    if(a.Soporte < b.Soporte) return 0;
    if(a.Peso > b.Peso) return 1;
    if(a.Peso < b.Peso) return 0;
    return a.Valor > b.Valor;
}
bool o1(const Bloque& a, const Bloque& b){
    if(a.Peso > b.Peso) return 1;
    if(a.Peso < b.Peso) return 0;
    if(a.Soporte > b.Soporte) return 1;
    if(a.Soporte < b.Soporte) return 0;
    return a.Valor > b.Valor;
}
vector<Bloque> a;
vector< vector<long long> > PD;
long long Resolver(int i, int Peso){
    if(Peso < 0) return -2222222222222222;
    if(i == a.size()) return 0;
    if(PD[i][Peso] != -2) return PD[i][Peso];
    return PD[i][Peso] = max(Resolver(i + 1, Peso), Resolver(i + 1, min(Peso - a[i].Peso, a[i].Soporte)) + a[i].Valor);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int p, s;
        long long v;
        cin>>p>>s>>v;
        a.push_back(Bloque(p, s, v));
    }
    sort(a.begin(), a.end(), o0);
    PD.assign(n, vector<long long>(10022, -2));
    long long r = 0;
    for(int i = 0; i < n; i++){
        r = max(r, Resolver(i + 1, a[i].Soporte) + a[i].Valor);
    }
    sort(a.begin(), a.end(), o1);
    PD.assign(n, vector<long long>(10022, -2));
    for(int i = 0; i < n; i++){
        r = max(r, Resolver(i + 1, a[i].Soporte) + a[i].Valor);
    }
    cout<<r;
    return 0;
}