#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
typedef unsigned int ui;
typedef long double ld;
using namespace std;
ui n;
vector< vector<ld> > PD, Torneo;
ld Resolver(ui i, ui M_scara){
    if(i == 0 and (ui)__popcount(M_scara) == n - (ui)1) return (ld)1;
    if(M_scara & (ui)1) return (ld)0;
    if(PD[i][M_scara] > (ld)-1) return PD[i][M_scara];
    ld Mayor = (ld)0;
    for(ui j = 0; j < n; j++){
        if(i == j) continue;
        if((M_scara & ((ui)1<<j)) == (ui)0){
            Mayor = max(Mayor, Resolver(i, M_scara | ((ui)1<<j)) * Torneo[i][j] + Resolver(j, M_scara | ((ui)1<<i)) * Torneo[j][i]);
        }
    }
    return PD[i][M_scara] = Mayor;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    PD.assign(n, vector<ld>(1<<n, (ld)-2));
    Torneo.assign(n, vector<ld>(n));
    forn(i, n){
        forn(j, n){
            cin>>Torneo[i][j];
        }
    }
    ld Mayor = 0;
    forn(i, n) Mayor = max(Mayor, Resolver((ui)i, (ui)0));
    cout<<setprecision(22)<<Mayor;
    return 0;
}