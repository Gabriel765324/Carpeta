#include "bits/stdc++.h"
using namespace std;
int f(string a, string b){
    while(a.size() < b.size()) a = '0' + a;
    while(b.size() < a.size()) b = '0' + b;
    int n = a.size(), r = 0;
    for(int i = 0; i < n; i++) if(a[i] == b[i]) r++;
    return r;
}
vector< vector<int> > PD;
string l, r;
int Resolver(int i, int Estado){
    if(i == l.size()) return 0;
    if(PD[i][Estado] != -2) return PD[i][Estado];
    if(Estado == 0){
        if(l[i] == r[i]) return PD[i][Estado] = Resolver(i + 1, 0) + 2;
        if(r[i] - l[i] >= 2) return PD[i][Estado] = 0;
        if(r[i] - l[i] == 1) return PD[i][Estado] = min(Resolver(i + 1, 1), Resolver(i + 1, 2)) + 1;
    }
    if(Estado == 1){
        int Retorno = 22222222;
        if(l[i] == '9') Retorno = min(Resolver(i + 1, 1) + 1, Retorno);
        else if(l[i] == '8'){
            if(r[i] == '9') Retorno = min(Resolver(i + 1, 3) + 1, Retorno);
            else Retorno = min(Resolver(i + 1, 3), Retorno);
        } else Retorno = min(Retorno, Resolver(i + 1, 3));
        return PD[i][Estado] = Retorno;
    }
    if(Estado == 2){
        int Retorno = 22222222;
        if(r[i] == '0') Retorno = min(Resolver(i + 1, 2) + 1, Retorno);
        else if(r[i] == '1'){
            if(l[i] == '0') Retorno = min(Resolver(i + 1, 3) + 1, Retorno);
            else Retorno = min(Resolver(i + 1, 3), Retorno);
        } else Retorno = min(Retorno, Resolver(i + 1, 3));
        return PD[i][Estado] = Retorno;
    }
    if(Estado == 3) return PD[i][Estado] = 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>l>>r;
        while(l.size() < r.size()) l = '0' + l;
        while(r.size() < l.size()) r = '0' + r;
        PD.assign(l.size(), vector<int>(4, -2));
        cout<<Resolver(0, 0)<<"\n";
    }
    return 0;
}