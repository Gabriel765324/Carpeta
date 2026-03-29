#include "bits/stdc++.h"
using namespace std;
int n;
vector<string> a;
vector< vector<int> > PD;
bool Es_vocal(char a){
    return a == 'A' or a == 'E' or a == 'I' or a == 'O' or a == 'U' or a == 'Y';
}
int Resolver(int i, int d){
    if(d < 0) return -2222;
    if(i == n) return 0;
    if(PD[i][d] != -2) return PD[i][d];
    int Vocal = d, Mejor = INT_MAX;
    for(int j = 0; j < 3 and j < a[i].size(); j++){
        if(Es_vocal(a[i][j])){
            Vocal = 2;
            int r = Resolver(i + 1, 2);
            if(r >= 0) Mejor = min(Mejor, r + j + 1);
        } else {
            Vocal--;
            if(Vocal < 0) break;
            int r = Resolver(i + 1, Vocal);
            if(r >= 0) Mejor = min(Mejor, r + j + 1);
        }
    }
    //cerr<<Mejor<<" "<<i<<" "<<d<<"\n";
    if(Mejor != INT_MAX) return PD[i][d] = Mejor;
    return PD[i][d] = -2222;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    PD.assign(n, vector<int>(3, -2));
    a.assign(n, "");
    for(int i = 0; i < n; i++) cin>>a[i];
    int r = Resolver(0, 2);
    if(r <= 0) cout<<"*";
    else cout<<r;
    return 0;
}