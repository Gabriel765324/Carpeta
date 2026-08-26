#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    vector< pair<long long, bool> > p;
    p.push_back({0, 0});
    long long r = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(i >= 2){
            if(a[i - 2] < a[i - 1] and a[i - 1] > a[i]) p.push_back({i - 1, 0});
            if(a[i - 2] > a[i - 1] and a[i - 1] < a[i]) p.push_back({i - 1, 1});
        }
    }
    p.push_back({n - 1, 0});
    for(int i = 1; i < p.size() - 2; i++){
        if(p[i].second != p[i + 1].second and !p[i].second){
            //cerr<<p[i - 1].first<<" "<<p[i].first<<" "<<p[i + 1].first<<" "<<p[i + 2].first<<"\n";
            r += (p[i].first - p[i - 1].first) * (p[i + 2].first - p[i + 1].first);
        }
    }
    cout<<r;
    return 0;
}