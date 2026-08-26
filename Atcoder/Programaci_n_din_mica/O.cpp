#include "bits/stdc++.h"
using namespace std;
struct M_dulo{
    long long v, m;
    M_dulo(long long a){
        m = 1000000007;
        v = a % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo((v % m + a.v % m) % m);
    }
    bool operator!=(const M_dulo& a){
        return a.v != v;
    }
};
int n;
vector< vector<M_dulo> > PD;
vector< vector<int> > Pasar;
M_dulo Resolver(int i, int M_scara){
    if(i == n) return 1;
    if(PD[i][M_scara] != M_dulo(-2)) return PD[i][M_scara];
    PD[i][M_scara] = M_dulo(0);
    for(auto E: Pasar[i]){
        if((M_scara & (1<<E)) == 0){
            PD[i][M_scara] = PD[i][M_scara] + Resolver(i + 1, M_scara + (1<<E));
        }
    }
    return PD[i][M_scara];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    PD.assign(n, vector<M_dulo>((1<<n), M_dulo(-2)));
    Pasar.assign(n, {});
    vector< vector<int> > Posible(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>Posible[i][j];
            if(Posible[i][j] == 1) Pasar[i].push_back(j);
        }
    }
    cout<<Resolver(0, 0).v;
    return 0;
}