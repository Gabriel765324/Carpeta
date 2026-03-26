#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    while(cin>>n) if(n % 2 == 1) break;
    vector< vector<long long> > m(n, vector<long long>(n, -2));
    long long i = 0, j = 0, ni = 1, nj = 0;
    long long Mayor = log10(n * n) + 1;
    for(long long a = n * n; a > 0; a--){
        m[i][j] = a;
        i += ni;
        j += nj;
        if(i == n or i == -1 or j == n or j == -1 or m[i][j] != -2){
            i -= ni;
            j -= nj;
            if(ni == 1 and nj == 0){
                ni = 0;
                nj = 1;
            } else if(ni == 0 and nj == 1){
                ni = -1;
                nj = 0;
            } else if(ni == -1 and nj == 0){
                ni = 0;
                nj = -1;
            } else {
                ni = 1;
                nj = 0;
            }
            i += ni;
            j += nj;
        }
    }
    for(auto E: m){
        for(auto e: E){
            cout<<e;
            for(long long i = log10(e) + 1; i <= Mayor; i++) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}