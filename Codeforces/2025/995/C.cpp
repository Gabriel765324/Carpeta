#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, m, k;
        cin>>n>>m>>k;
        vector<long long> a(m), Saber(n, 0);
        for(long long i = 0; i < m; i++) cin>>a[i];
        for(long long i = 0; i < k; i++){
            long long aa;
            cin>>aa;
            aa--;
            Saber[aa] = 1;
        }
        long long No_s_ = 0;
        for(long long i = 0; i < n; i++){
            if(Saber[i] == 0){
                No_s_ = i;
                break;
            }
        }
        //cout<<No_s_<<"\n";
        string r = "";
        for(long long i = 0; i < m; i++){
            if(k >= n) r += '1';
            else if(k == n - 1){
                if(a[i] - 1 == No_s_) r += '1';
                else r += '0';
            } else r += '0';
        }
        cout<<r<<"\n";
    }
    return 0;
}