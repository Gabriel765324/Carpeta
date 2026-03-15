#include "bits/stdc++.h"
using namespace std;
int n;
vector< vector<long double> > PD;
vector<long double> a;
long double Resolver(int i, int c){
    if(i == n){
        if(c > n / 2) return 1;
        else return 0;
    }
    if(PD[i][c] >= 0) return PD[i][c];
    PD[i][c] = Resolver(i + 1, c) * (long double)(1 - a[i]) + Resolver(i + 1, c + 1) * a[i];
    return PD[i][c];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    PD.assign(n + 1, vector<long double>(n + 1, -2));
    a.assign(n, 0);
    for(int i = 0; i < n; i++) cin>>a[i];
    cout<<setprecision(22)<<Resolver(0, 0);
    return 0;
}