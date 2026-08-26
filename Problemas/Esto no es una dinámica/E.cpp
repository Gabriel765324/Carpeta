#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector< vector<double> > m(n, vector<double>(n)), a(n, vector<double>(n)), b(n, vector<double>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>m[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i == j){
                a[i][j] = m[i][j];
                b[i][j] = -0;
                continue;
            }
            a[i][j] = (m[i][j] + m[j][i]) / 2;
            a[j][i] = a[i][j];
            b[i][j] = m[i][j] - a[i][j];
            b[j][i] = -b[i][j];
        }
    }
    for(auto E: a){
        for(auto e: E) cout<<setprecision(22)<<e<<" ";
        cout<<"\n";
    }
    for(auto E: b){
        for(auto e: E) cout<<setprecision(22)<<e<<" ";
        cout<<"\n";
    }
    return 0;
}