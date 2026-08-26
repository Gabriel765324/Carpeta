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
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector< vector<M_dulo> > PD(n, vector<M_dulo>(m, M_dulo(0)));
    vector<string> a(n);
    PD[0][0] = M_dulo(1);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i > 0) PD[i][j] = PD[i][j] + PD[i - 1][j];
            if(j > 0) PD[i][j] = PD[i][j] + PD[i][j - 1];
            if(a[i][j] == '#') PD[i][j] = M_dulo(0);
            //cerr<<PD[i][j].v<<" ";
        }
        //cerr<<"\n";
    }
    cout<<PD.back().back().v;
    return 0;
}