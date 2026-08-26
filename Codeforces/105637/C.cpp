#include "bits/stdc++.h"
using namespace std;
int n;
long double d;
vector< pair<long double, long double> > a;
vector<int> PD;
int Resolver(int i){
    if(i == n - 1) return 1;
    if(PD[i] != -2) return PD[i];
    long double Mayor_pendiente = (a[i + 1].second - a[i].second + d) / (a[i + 1].first - a[i].first);
    long double Menor_pendiente = (a[i + 1].second - a[i].second - d) / (a[i + 1].first - a[i].first);
    int r = 2222;
    for(int j = i + 1; j < n; j++){
        Mayor_pendiente = min(Mayor_pendiente, (a[j].second - a[i].second + d) / (a[j].first - a[i].first));
        Menor_pendiente = max(Menor_pendiente, (a[j].second - a[i].second - d) / (a[j].first - a[i].first));
        if(Menor_pendiente > Mayor_pendiente) break;
        if((a[j].second - a[i].second) / (a[j].first - a[i].first) >= Menor_pendiente and (a[j].second - a[i].second) / (a[j].first - a[i].first) <= Mayor_pendiente){
            r = min(r, Resolver(j) + 1);
            //cerr<<i<<" "<<j<<" "<<Resolver(j) + 1<<"\n";
        }
    }
    return PD[i] = r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    PD.assign(n, -2);
    a.assign(n, {});
    for(int i = 0; i < n; i++) cin>>a[i].first>>a[i].second;
    cin>>d;
    cout<<Resolver(0);
    return 0;
}