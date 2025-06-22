#include "bits/stdc++.h"
using namespace std;
vector<long long> r, t;
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
        r[b] = a;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n>>m;
    for(long long i = 0; i < n; i++){
        r.push_back(i);
        t.push_back(1);
    }
    vector<long long> Amiguitos(n, 1);
    while(m--){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Unir(a, b);
        Amiguitos[a]++;
        Amiguitos[b]++;
    }
    bool Razonable = 1;
    for(long long i = 0; i < n and Razonable; i++) if(t[Buscar(i)] > Amiguitos[i]) Razonable = 0;
    cout<<((Razonable) ? "YES" : "NO");
    return 0;
}