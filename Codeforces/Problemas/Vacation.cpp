#include "bits/stdc++.h"
using namespace std;
vector<long long> a;
vector< vector<long long> > Memorizaci_n;
long long PD(long long i, long long Anterior){
    if(i == a.size()) return 0;
    if(Memorizaci_n[i][Anterior] != -2) return Memorizaci_n[i][Anterior];
    long long m = -2;
    switch(a[i]){
        case 0:
        return Memorizaci_n[i][Anterior] = PD(i + 1, 0);
        break;
        case 1:
        m = max(m, PD(i + 1, 0));
        if(Anterior != 1) m = max(m, PD(i + 1, 1) + 1);
        break;
        case 2:
        m = max(m, PD(i + 1, 0));
        if(Anterior != 2) m = max(m, PD(i + 1, 2) + 1);
        break;
        case 3:
        m = max(m, PD(i + 1, 0));
        if(Anterior != 1) m = max(m, PD(i + 1, 1) + 1);
        if(Anterior != 2) m = max(m, PD(i + 1, 2) + 1);
        break;
    }
    return Memorizaci_n[i][Anterior] = m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    a.assign(n, 0);
    for(long long i = 0; i < n; i++){
        cin>>a[i];
    }
    Memorizaci_n.assign(n, vector<long long>(3, -2));
    cout<<n - PD(0, 0);
    return 0;
}