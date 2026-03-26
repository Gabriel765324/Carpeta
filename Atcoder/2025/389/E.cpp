#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n>>m;
    vector<long long> a(n);
    multiset< pair<long long, long long> > Productos;
    for(long long i = 0; i < n; i++){
        cin>>a[i];
        Productos.insert(make_pair(a[i], 0));
    }
    vector<long long> Cuadrados;
    for(long long i = 1; i <= 1442600; i++) Cuadrados.push_back(i * i);
    long long c;
    for(c = 0; m > 0; c++){
        pair<long long, long long> zd = *Productos.begin();
        //cout<<zd.first<<" "<<zd.second<<"\n";
        m -= zd.first;
        zd.first /= Cuadrados[zd.second];
        zd.second++;
        zd.first *= Cuadrados[zd.second];
        Productos.erase(Productos.begin());
        Productos.insert(zd);
    }
    cout<<c;
    return 0;
}