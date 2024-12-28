#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, x, y, s = 0, r = 0;
        cin>>n>>x>>y;
        vector<long long> a(n);
        for(long long i = 0; i < n; i++){
            cin>>a[i];
            s += a[i];
        }
        sort(a.begin(), a.end());
        a.push_back(2222222222222222);
        /*cout<<x<<" "<<y<<" "<<s<<"\n";
        for(auto E: a) cout<<E<<" ";
        cout<<"\n";*/
        for(long long i = 0; i < n - 1; i++){
            long long ii = i + 1, d = n, m1 = ii, m2 = ii;
            while(1){
                long long p = (ii + d) / 2;
                if(s - a[i] - a[p] < x){
                    m1 = p;
                    d = p - 1;
                } else ii = p + 1;
                if(ii >= d + 1) break;
            }
            ii = i + 1;
            d = n;
            while(1){
                long long p = (ii + d) / 2;
                if(s - a[i] - a[p] <= y){
                    m2 = p;
                    d = p - 1;
                } else ii = p + 1;
                if(ii >= d + 1) break;
            }
            r += m1 - m2;
            //cout<<i<<" "<<m2<<" "<<m1<<"\n";
        }
        cout<<r<<"\n";
    }
    return 0;
}