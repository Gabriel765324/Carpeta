#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector< pair< pair<long long, long long>, long long> > a(n);
    vector<long long> Respuesta(n);
    for(long long i = 0; i < n; i++){
        cin>>a[i].first.first;
        cin>>a[i].first.second;
        a[i].second = i;
        a[i].first.second += a[i].first.first;
        a[i].first.second /= -1;
    }
    sort(a.begin(), a.end());
    set< pair<long long, long long> > Conjunto;
    Conjunto.insert(make_pair(2000000022, 0));
    for(long long i = 0; i < n; i++){
        long long p = a[i].second, r = -a[i].first.second;
        Respuesta[p] = -(*Conjunto.lower_bound(make_pair(r, -2222222222222222))).second + 1;
        if((*Conjunto.lower_bound(make_pair(r, -2222222222222222))).first == r) Conjunto.erase(Conjunto.lower_bound(make_pair(r, -2222222222222222)));
        Conjunto.insert(make_pair(r, -Respuesta[p]));
        /*for(auto E: Conjunto){
            if(E.first < r and E.second <= -Respuesta[p]) Conjunto.erase(E);
            if(E.first >= r) break;
        }*/
        auto j = Conjunto.find(make_pair(r, -Respuesta[p]));
        if(j != Conjunto.begin()){
            j--;
            if((*j).first < r and -(*j).second <= Respuesta[p]) Conjunto.erase(j);
        }
        /*for(auto E: Conjunto){
            cout<<E.first<<" "<<-E.second<<"\n";
        }
        cout<<"\n";*/
    }
    for(auto E: Respuesta) cout<<E - 1<<" ";
    return 0;
}