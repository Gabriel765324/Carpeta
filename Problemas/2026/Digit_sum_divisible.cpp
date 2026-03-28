#include "bits/stdc++.h"
using namespace std;
string n;
long long m;
vector< vector< vector< vector< vector<long long> > > > > PD;
deque<long long> Potencias;
long long Resolver(int i, int Me_queda, long long Llevo, int Libre, int V_lido){
    if(Me_queda < 0LL) return 0LL;
    if(i == int(n.size())){
        if(Me_queda == 0 and Llevo == 0 and V_lido == 1) return 1LL;
        else return 0LL;
    }
    if(PD[i][Me_queda][Llevo][Libre][V_lido] != -2) return PD[i][Me_queda][Llevo][Libre][V_lido];
    PD[i][Me_queda][Llevo][Libre][V_lido] = 0;
    if(Libre == 0){
        for(int d = 0; d <= (n[i] - '0'); d++){
            int Validador = V_lido;
            if(d > 0) Validador = 1;
            PD[i][Me_queda][Llevo][Libre][V_lido] += Resolver(i + 1, Me_queda - d, (Llevo + (long long)d * Potencias[i]) % m, int(d < (n[i] - '0')), Validador);
        }
    } else {
        for(int d = 0; d <= 9; d++){
            int Validador = V_lido;
            if(d > 0) Validador = 1;
            PD[i][Me_queda][Llevo][Libre][V_lido] += Resolver(i + 1, Me_queda - d, (Llevo + (long long)d * Potencias[i]) % m, 1, Validador);
        }
    }
    return PD[i][Me_queda][Llevo][Libre][V_lido];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    long long r = 0;
    Potencias.push_back(1);
    while(Potencias.size() < n.size()) Potencias.push_front(10LL * Potencias[0]);
    for(m = 1LL; m <= 9LL * (long long)n.size(); m++){
        PD.assign(n.size(), vector< vector< vector< vector<long long> > > >(m + 1, vector< vector< vector<long long> > >(m, vector< vector<long long> >(2, vector<long long>(2, -2)))));
        r += Resolver(0, m, 0LL, 0, 0);
    }
    cout<<r;
    return 0;
}