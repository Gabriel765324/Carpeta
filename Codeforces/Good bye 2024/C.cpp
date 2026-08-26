#include "bits/stdc++.h"
using namespace std;
map<long long, long long> Memorizaci_n, Capas;
//Podría ser todas las capas o solo las capas con longitud impar.
//vector< pair<long long, pair<long long, long long> > > Mal;
long long Resolver_bruto(long long l, long long r, long long k){
    if(r - l + 1 < k) return 0;
    long long m = (l + r) / 2;
    if((r - l + 1) % 2 == 0){
        long long rr = Resolver_bruto(l, m, k) + Resolver_bruto(m + 1, r, k);
        //cout<<r<<" "<<l<<" "<<rr<<"\n";
        return rr;
    } else {
        long long rr = m + Resolver_bruto(l, m - 1, k) + Resolver_bruto(m + 1, r, k);
        //cout<<r<<" "<<l<<" "<<rr<<"\n";
        return rr;
    }
}
pair<long long, long long> Resolver(long long l, long long r, long long k){
    if(r - l + 1 < k){
        //cout<<"Retorno "<<r<<" "<<l<<"\n";
        return make_pair(0, 0);
    }
    if(Memorizaci_n.count(r - l + 1) == 1){
        //Mal.push_back(make_pair(Memorizaci_n[r - l + 1] + l - 1, make_pair(r, l)));
        return make_pair(Memorizaci_n[r - l + 1] + (l - 1) * Capas[r - l + 1], Capas[r - l + 1]);
    }
    long long m = (l + r) / 2;
    if((r - l + 1) % 2 == 1){
        Memorizaci_n[r - l + 1] = m;
        pair<long long, long long> _1 = Resolver(l, m - 1, k);
        Memorizaci_n[r - l + 1] += _1.first;
        Capas[r - l + 1] = _1.second;
        pair<long long, long long> _2 = Resolver(m + 1, r, k);
        Memorizaci_n[r - l + 1] += _2.first;
        Capas[r - l + 1] += _2.second + 1;
        //cout<<_1.first<<" "<<l<<" "<<m - 1<<"\n";
        //cout<<_2.first<<" "<<m + 1<<" "<<r<<"\n";
        //cout<<k<<" "<<r<<" "<<l<<" "<<Memorizaci_n[r - l + 1]<<"\n";
        //Mal.push_back(make_pair(Memorizaci_n[r - l + 1], make_pair(r, l)));
        return make_pair(Memorizaci_n[r - l + 1], Capas[r - l + 1]);
    } else {
        pair<long long, long long> _1 = Resolver(l, m, k);
        Memorizaci_n[r - l + 1] = _1.first;
        Capas[r - l + 1] = _1.second;
        pair<long long, long long> _2 = Resolver(m + 1, r, k);
        Memorizaci_n[r - l + 1] += _2.first;
        Capas[r - l + 1] += _2.second;
        //cout<<k<<" "<<r<<" "<<l<<" "<<Memorizaci_n[r - l + 1]<<"\n";
        //Mal.push_back(make_pair(Memorizaci_n[r - l + 1], make_pair(r, l)));
        return make_pair(Memorizaci_n[r - l + 1], Capas[r - l + 1]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        Memorizaci_n.clear();
        Capas.clear();
        long long n, k;
        cin>>n>>k;
        if(k == 1) cout<<n * (n + 1) / 2;
        else cout<<Resolver(1, n, k).first;
        cout<<"\n";
        /*for(long long i = 0; i < Mal.size() and k != 1; i++){
            cout<<k<<" "<<Mal[i].first<<" "<<Resolver_bruto(Mal[i].second.second, Mal[i].second.first, k)<<" "<<Mal[i].second.second<<" "<<Mal[i].second.first<<"\n";
        }*/
    }
    return 0;
}