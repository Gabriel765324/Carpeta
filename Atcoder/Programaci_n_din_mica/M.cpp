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
    int n, k;
    cin>>n>>k;
    vector< vector<M_dulo> > PD(2, vector<M_dulo>(k + 1, M_dulo(0)));
    PD[0][k] = M_dulo(1);
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        M_dulo Llevo = M_dulo(0);
        deque< pair<int, M_dulo> > p;
        for(int j = k; j > -1; j--){
            if(PD[0][j] != M_dulo(0)){
                Llevo = Llevo + PD[0][j];
                p.push_back({j, PD[0][j]});
            }
            if(!p.empty() and p[0].first - j > a){
                Llevo = Llevo - p[0].second;
                p.pop_front();
            }
            PD[1][j] = PD[1][j] + Llevo;
            PD[0][j] = M_dulo(0);
        }
        swap(PD[0], PD[1]);
    }
    cout<<PD[0][0].v;
    return 0;
}