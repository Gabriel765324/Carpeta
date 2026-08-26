#include "bits/stdc++.h"
using namespace std;
struct Valor{
    bool Posible, Hecho;
    int vs, is, ps;
    Valor(){
        Posible = 0;
        Hecho = 0;
    }
    Valor(bool p, bool h){
        Posible = p;
        Hecho = h;
    }
};
vector<int> Valores = {1, 2, 5, 10, 20, 50, 100, 200, 500};
vector< vector< vector<Valor> > > PD;
bool Resolver(int n, int i, int p){
    if(n == 0) return p == 1;
    if(n < 0) return 0;
    if(i == 9) return 0;
    if(PD[n][i][p].Hecho) return PD[n][i][p].Posible;
    for(int m = 0; 1; m++){
        if(n - m * Valores[i] < 0) break;
        int Lograble = p;
        if(m & 1) Lograble = 1;
        if(Resolver(n - m * Valores[i], i + 1, Lograble)){
            PD[n][i][p].vs = n - m * Valores[i];
            PD[n][i][p].is = i + 1;
            PD[n][i][p].ps = Lograble;
            PD[n][i][p].Hecho = 1;
            return PD[n][i][p].Posible = 1;
        }
    }
    PD[n][i][p].Hecho = 1;
    return PD[n][i][p].Posible = 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    PD.assign(n + 1, vector< vector<Valor> >(9, vector<Valor>(2, Valor())));
    if(Resolver(n, 0, 0)){
        vector<int> Necesarios;
        int v = n, i = 0, p = 0;
        while(v > 0){
            int vs = PD[v][i][p].vs;
            int is = PD[v][i][p].is;
            int ps = PD[v][i][p].ps;
            while(v > vs){
                Necesarios.push_back(Valores[i]);
                v -= Valores[i];
            }
            v = vs;
            i = is;
            p = ps;
        }
        cout<<int(Necesarios.size())<<"\n";
        for(auto E: Necesarios) cout<<E<<" ";
        cout<<"\n";
        return 0;
    }
    cout<<"splittable\n";
    return 0;
}