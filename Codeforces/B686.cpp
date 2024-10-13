#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n, 0);
        vector< vector<long long> > b(n);
        for(long long i = 0; i < n; i++){
            long long A;
            cin>>A;
            a[A - 1]++;
            b[A - 1].push_back(i + 1);
        }
        bool No = 1;
        for(long long i = 0; i <= n; i++){
            if(a[i] == 1){
                No = 0;
                cout<<b[i].front()<<"\n";
                break;
            }
        }
        if(No) cout<<"-1\n";
    }
    return 0;
}