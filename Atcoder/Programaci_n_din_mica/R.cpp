#include "bits/stdc++.h"
using namespace std;
struct Nodo{
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
    unsigned long long Distancia, Copias_de_m_;
    vector<int> Ir;
    vector<M_dulo> Copias;
    Nodo(unsigned long long d, unsigned long long cm, vector<int> i, vector<unsigned long long> c){
        Distancia = d;
        Copias_de_m_ = M_dulo(cm);
        Ir = i;
        for(int I = 0; I < c.size(); I++){
            Copias.push_back(M_dulo(c[I]));
        }
    }
    Nodo Combinar(const int& Capa, const Nodo& a){
        if(a.Ir.size() <= Capa or Ir.size() <= Capa){
            return Nodo(2, 0, {}, {});
        }

    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    return 0;
}