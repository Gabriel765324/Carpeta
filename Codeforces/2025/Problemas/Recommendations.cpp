#include "bits/stdc++.h"
using namespace std;
bool o(pair< pair<long long, long long>, long long> &a, pair< pair<long long, long long>, long long> &b){
    if(a.second < b.second) return 1;
    else return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector< pair< pair<long long, long long>, long long> > a(n);
        set<long long> s;
        vector<long long> r(n, 0);
        for(long long i = 0; i < n; i++){
            cin>>a[i].first.first>>a[i].first.second;
            a[i].first.second /= -1;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        for(auto E: a){
            if(s.lower_bound(-E.first.second) != s.end()){
                r[E.second] += *s.lower_bound(-E.first.second) + E.first.second;
            }
            s.insert(-E.first.second);
        }
        for(long long i = 0; i < n; i++){
            a[i].first.second /= -1;
            a[i].first.first = 1000000001 - a[i].first.first;
            a[i].first.second = 1000000001 - a[i].first.second;
            a[i].first.first /= -1;
            swap(a[i].first.first, a[i].first.second);
        }
        sort(a.begin(), a.end());
        s.clear();
        for(auto E: a){
            if(s.lower_bound(-E.first.second) != s.end()){
                r[E.second] += *s.lower_bound(-E.first.second) + E.first.second;
            }
            s.insert(-E.first.second);
        }
        map< pair<long long, long long>, long long > Igual;
        for(auto E: a){
            Igual[make_pair(E.first.first, E.first.second)]++;
        }
        sort(a.begin(), a.end(), o);
        for(long long i = 0; i < n; i++){
            if(Igual[a[i].first] >= 2) r[i] = 0;
            cout<<r[i]<<"\n";
        }
        //cout<<"\n";
    }
    return 0;
}