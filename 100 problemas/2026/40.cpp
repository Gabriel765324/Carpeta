#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    deque< pair<long long, long long> > a;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            long long c, x;
            cin>>c>>x;
            a.push_back({x, c});
        } else {
            long long k, r = 0;
            cin>>k;
            while(!a.empty()){
                if(a[0].second > k){
                    a[0].second -= k;
                    r += a[0].first * k;
                    break;
                } if(a[0].second == k){
                    r += a[0].first * a[0].second;
                    a.pop_front();
                    break;
                } else {
                    r += a[0].first * a[0].second;
                    k -= a[0].second;
                    a.pop_front();
                }
            }
            cout<<r<<"\n";
        }
    }
    return 0;
}