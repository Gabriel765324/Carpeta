#include "bits/stdc++.h"
using namespace std;
vector<long long> ci = {-1, -1, 0, 1, 1, 1, 0, -1}, cj = {0, 1, 1, 1, 0, -1, -1, -1};
vector< vector<bool> > Visitado;
vector<string> m;
long long n;
bool DFS(long long i, long long j){
    if(i == 1 and j == n - 1) return 1;
    Visitado[i][j] = 1;
    bool r = 0;
    for(long long k = 0; k < 8; k++){
        long long ni = i + ci[k], nj = j + cj[k];
        if(ni > -1 and ni < 2 and nj > -1 and nj < n and !Visitado[ni][nj] and m[ni][nj] == '0') r |= DFS(ni, nj);
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        cin>>n;
        m.assign(2, "");
        Visitado.assign(2, vector<bool>(n, 0));
        cin>>m[0]>>m[1];
        cout<<((DFS(0, 0)) ? "YES" : "NO")<<"\n";
    }
    return 0;
}