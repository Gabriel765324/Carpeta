#include "bits/stdc++.h"
using namespace std;
int c = 222;
vector< vector<int> > PD(c, vector<int>(c, -2));
int Resolver(int n, int m){
    if(n == 0 and m == 0) return PD[n][m] = 1;
    if(n == 0 or m == 0) return PD[n][m] = 0;
    if(PD[n][m] != -2) return PD[n][m];
    return PD[n][m] = ((m & 1) * (Resolver(n - 1, m) & 1) + (Resolver(n - 1, m - 1) & 1)) & 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int n = 0; n < c; n++){
        for(int m = 0; m < c - n; m++){
            cout<<(Resolver(n + m, m) ? '#' : '.');
        }
        cout<<"\n";
    }
    return 0;
}