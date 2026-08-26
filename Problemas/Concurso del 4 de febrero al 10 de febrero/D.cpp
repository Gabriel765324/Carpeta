#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        vector<string> Matriz(n);
        for(long long i = 0; i < n; i++) cin>>Matriz[i];
        long long c = 0;
        if(n == 1 and m == 1) cout<<c;
        else if(n == 1){
            for(long long i = 0; i < m - 1; i++){
                c += Matriz[0][i] == 'D';
            }
            cout<<c;
        } else if(m == 0){
            for(long long i = 0; i < n - 1; i++){
                c += Matriz[i][0] == 'R';
            }
            cout<<c;
        } else {
            for(long long i = 0; i < n - 1; i++){
                c += Matriz[i][m - 1] == 'R';
            }
            for(long long i = 0; i < m - 1; i++){
                c += Matriz[n - 1][i] == 'D';
            }
            cout<<c;
        }
        cout<<"\n";
    }
    return 0;
}