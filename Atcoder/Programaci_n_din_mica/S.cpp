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
    M_dulo operator-(const M_dulo& a){
        return M_dulo(((v % m - a.v % m) % m + m) % m);
    }
    bool operator!=(const M_dulo& a){
        return a.v != v;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    int m;
    cin>>n>>m;
    vector< vector< vector<M_dulo> > > PD(2, vector< vector<M_dulo> >(m, vector<M_dulo>(2, M_dulo(0))));
    PD[0][0][0] = M_dulo(1);
    for(int i = 0; i < n.size(); i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 10; k++){
                if(k <= n[i] - '0') PD[1][(j + k) % m][k != n[i] - '0'] = PD[1][(j + k) % m][k != n[i] - '0'] + PD[0][j][0];
                PD[1][(j + k) % m][1] = PD[1][(j + k) % m][1] + PD[0][j][1];
            }
            PD[0][j][0] = M_dulo(0);
            PD[0][j][1] = M_dulo(0);
        }
        swap(PD[0], PD[1]);
    }
    cout<<(PD[0][0][0] + PD[0][0][1] - M_dulo(1)).v;
    return 0;
}