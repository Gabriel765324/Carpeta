#include "bits/stdc++.h"
using namespace std;
vector<long long> r;
long long Buscar(long long a){
    if(r[a] == a) return a;
    return r[a] = Buscar(r[a]);
}
bool Unir(long long a, long long b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        r[b] = a;
        return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    for(long long i = 0; i < n; i++) r.push_back(i);
    deque< pair<long, long> > Calles_malas;
    for(long long i = 0; i < n - 1; i++){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        if(!Unir(a, b)) Calles_malas.push_back({a + 1, b + 1});
    }
    map<long long, long long> Uniones;
    set<long long> Representantes;
    for(long long i = 0; i < n; i++){
        r[i] = Buscar(r[i]);
        Uniones[r[i]] = i + 1;
        Representantes.insert(r[i]);
    }
    cout<<Calles_malas.size()<<"\n";
    while(Representantes.size() > 1){
        auto E = Representantes.begin();
        auto e = Representantes.begin();
        e++;
        cout<<Calles_malas[0].first<<" "<<Calles_malas[0].second<<" "<<Uniones[*E]<<" "<<Uniones[*e]<<"\n";
        Calles_malas.pop_front();
        Representantes.erase(E);
    }
    return 0;
}
/*
6
1 2
2 3
3 1
4 3
4 5
*/