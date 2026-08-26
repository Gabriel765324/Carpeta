#include "bits/stdc++.h"
using namespace std;
struct M_dulo{
    unsigned long long v, m;
    M_dulo(unsigned long long a){
        m = 1000000007;
        v = a % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo((v % m + a.v % m) % m);
    }
    M_dulo operator*(const M_dulo& a){
        return M_dulo((v % m * a.v % m) % m);
    }
};
unsigned long long Dos_elevado_a_algo(unsigned long long a){
    return ((unsigned long long)1)<<a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    unsigned long long k;
    cin>>n>>k;
    vector<M_dulo> Llegadas(n, M_dulo(1));
    vector< vector< vector<M_dulo> > > Mesa(1, vector< vector<M_dulo> >(n, vector<M_dulo>(n, M_dulo(0))));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            unsigned long long a;
            cin>>a;
            Mesa[0][i][j] = M_dulo(a);
        }
    }
    unsigned long long Capa = 0;
    while(k > 0){
        if(Dos_elevado_a_algo(Capa) > k){
            Capa--;
            while(k > 0){
                int i = 1, d = Capa, m = 0;
                while(i < d + 1){
                    int p = (i + d) / 2;
                    if(k >= Dos_elevado_a_algo(p)){
                        i = p + 1;
                        m = p;
                    } else d = p - 1;
                }
                vector<M_dulo> Nuevo(n, M_dulo(0));
                k -= Dos_elevado_a_algo(m);
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        Nuevo[j] = Nuevo[j] + (Mesa[m][i][j] * Llegadas[i]);
                    }
                }
                Llegadas = Nuevo;
            }
            break;
        }
        vector<M_dulo> Nuevo(n, M_dulo(0));
        k -= Dos_elevado_a_algo(Capa);
        Mesa.push_back(vector< vector<M_dulo> >(n, vector<M_dulo>(n, M_dulo(0))));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                Nuevo[j] = Nuevo[j] + (Mesa[Capa][i][j] * Llegadas[i]);
                for(int k = 0; k < n; k++){
                    Mesa.back()[i][k] = Mesa.back()[i][k] + (Mesa[Capa][i][j] * Mesa[Capa][j][k]);
                }
            }
        }
        Llegadas = Nuevo;
        Capa++;
    }
    M_dulo r = M_dulo(0);
    for(auto E: Llegadas) r = r + E;
    cout<<r.v;
    return 0;
}