#include "bits/stdc++.h"
using namespace std;
int main(){
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    long long n, t;
    cin>>n>>t;
    vector< pair<long long, long long> > a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
        a[i].second = a[i].first + t * a[i].second;
    }
    sort(a.begin(), a.end());
    long long r = 1LL;
    set< pair<long long, long long> > s;
    for(auto E: a){
        auto e = s.lower_bound(make_pair(E.second, -2LL));
        if(e != s.end()){
            pair<long long, int> Actual = *e;
            s.insert(make_pair(E.second, Actual.second + 1LL));
            r = max(r, Actual.second + 1LL);
            for(e = s.lower_bound(make_pair(E.second, Actual.second + 1LL)); e != s.begin(); ){
                e--;
                if((*e).second <= Actual.second + 1LL) s.erase(e);
                else break;
                e = s.lower_bound(make_pair(E.second, Actual.second + 1LL));
            }
        } else {
            s.insert(make_pair(E.second, 1LL));
            r = max(r, 1LL);
        }
    }
    cout<<r;
    return 0;
}