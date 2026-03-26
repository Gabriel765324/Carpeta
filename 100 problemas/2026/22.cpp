#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n = s.size();
    vector< vector<long long> > PD(n + 1, vector<long long>(10, 2222222222222222));
    for(int i = 0; i < 10; i++) PD[n][i] = 0;
    for(int i = n - 1; i > -1; i--){
        long long j = s[i] - '0';
        PD[i][j] = 1;
        if(i == n - 1) PD[i][j] += j;
        long long r = 2222222222222222;
        for(int k = 0; k < 10; k++){
            r = min(r, PD[i + 1][(j - k + 220) % 10] + k);
        }
        PD[i][j] += r;
    }
    for(auto E: PD){
        for(auto e: E){
            cerr<<e<<" ";
        }
        cerr<<"\n";
    }
    cout<<PD[0][s[0] - '0'];
    return 0;
}