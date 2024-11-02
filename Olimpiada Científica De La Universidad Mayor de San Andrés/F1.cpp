#include "bits/stdc++.h"
using namespace std;
bool o(pair<long long, long long> &A, pair<long long, long long> &B){
    long long a = A.first - A.second, b = B.first - B.second;
    if(a < b) return 1;
    else if(a > b) return 0;
    else {
        if(A.first < B.first) return 1;
        else return 0;
    }
}
bool oo(pair<long long, long long> &a, pair<long long, long long> &b){
    if(a.first < b.first) return 0;
    if(a.first > b.first) return 1;
    if((a.first - a.second) < (b.first - b.second)) return 1;
    return 0;
}
vector< pair<long long, long long> > Bueno;
vector<long long> Proceso;
long long Preproceso(long long i, long long m){
    if(i == Bueno.size()) return 0;
    if(Proceso[i] != -1) return Proceso[i];
    long long a = 0, i = 0, d = LLONG_MAX / Bueno[i].first, m;
    while(1){
        
    }
    Proceso[i] = Preproceso(lower_bound(Bueno.begin(), Bueno.end(), make_pair(Bueno[i].second, -2)) - Bueno.begin(), Bueno[i].second) + a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n>>m;
    vector< pair<long long, long long> > ab(n);
    vector<long long> c(m);
    for(long long i = 0; i < n; i++){
        cin>>ab[i].first;
    }
    for(long long i = 0; i < n; i++){
        cin>>ab[i].second;
    }
    for(long long i = 0; i < m; i++){
        cin>>c[i];
    }
    sort(ab.begin(), ab.end(), o);
    set<long long> Diferencias;
    for(long long i = 0; i < n; i++){
        if(Diferencias.count(ab[i].first - ab[i].second) == 0){
            Diferencias.insert(ab[i].first - ab[i].second);
            Bueno.push_back(ab[i]);
        }
    }
    n = Bueno.size();
    Proceso.assign(n, -1);
    sort(Bueno.begin(), Bueno.end(), oo);
    long long Irrelevante = Preproceso(0, 22222222222);
    return 0;
}