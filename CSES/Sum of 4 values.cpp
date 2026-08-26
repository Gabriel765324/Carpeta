#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, x;
    cin>>n>>x;
    vector< pair<long long, long long> > a(n);
    for(long long i = 0; i < n; i++){
        long long aa;
        cin>>aa;
        a[i] = make_pair(aa, i + 1);
    }
    sort(a.begin(), a.end());
    /*for(auto E: a) cout<<E.first<<" ";
    cout<<"\n";*/
    set< pair<long long, pair<long long, long long> > > Sumas;
    for(long long i = 0; i < (n - 1); i++){
        for(long long j = i + 1; j < n; j++){
            Sumas.insert(make_pair(a[i].first + a[j].first, make_pair(i, j)));
        }
    }
    /*for(auto E: Sumas) cout<<E.first<<" "<<a[E.second.first].second<<" "<<a[E.second.second].second<<"\n";
    cout<<"\n";
    for(auto E: Sumas) cout<<E.first<<" "<<E.second.first<<" "<<E.second.second<<"\n";
    cout<<"\n";*/
    for(long long i = 0; i < (n - 1); i++){
        for(long long j = i + 1; j < n; j++){
            long long Actual = a[i].first + a[j].first;
            //cout<<x - Actual<<"\n";
            auto E = Sumas.lower_bound(make_pair(x - Actual, make_pair(-1, -1)));
            for(long long k = 0; k < 8 and E != Sumas.end(); k++){
                if(((*E).first + Actual) == x and i != (*E).second.first and i != (*E).second.second and j != (*E).second.first and j != (*E).second.second){
                    cout<<a[i].second<<" "<<a[j].second<<" "<<a[(*E).second.first].second<<" "<<a[(*E).second.second].second;
                    //cout<<"\n"<<i<<" "<<j<<" "<<(*E).second.first<<" "<<(*E).second.second;
                    return 0;
                }
                E++;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}