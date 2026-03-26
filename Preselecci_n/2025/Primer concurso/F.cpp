#include "bits/stdc++.h"
using namespace std;
vector<long long> r, t;
long long m = 1;
void Crear(long long n){
    m = 1;
    t.assign(n, 1);
    r.assign(n, -0);
    for(long long i = 0; i < n; i++) r[i] = i;
}
long long Buscar(long long a){
    if(r[a] == a) return a;
    return r[a] = Buscar(r[a]);
}
void Unir(long long a, long long b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        if(t[a] < t[b]) swap(a, b);
        t[a] += t[b];
        m = max(m, t[a]);
        r[b] = a;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, q;
        cin>>n>>q;
        Crear(n);
        while(q--){
            long long a, b;
            cin>>a>>b;
            a--;
            b--;
            Unir(a, b);
        }
        cout<<m<<"\n";
    }
    return 0;
}