#include "bits/stdc++.h"
using namespace std;
long long m = 1e9 + 7;
deque< pair<long long, long long> > L_mites;
deque< deque<long long> > Grafo;
deque<long long> Por_aqu_;
deque<long long> Representantes, El_enano;
unordered_set<long long> Unidos;
long long Tama_o(long long i){
    return L_mites[i].second - L_mites[i].first + 1;
}
bool DFS(long long Nodo, long long Objetivo, long long Anterior){
    if(Nodo == Objetivo){
        Por_aqu_.push_front(Nodo);
        return 1;
    }
    bool Bien = 0;
    for(auto E: Grafo[Nodo]){
        if(E != Anterior){
            Bien |= DFS(E, Objetivo, Nodo);
        }
    }
    if(Bien){
        Por_aqu_.push_front(Nodo);
        return 1;
    }
    return 0;
}
long long Multiplicar(long long a, long long b){
    return (a % m * b % m) % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    Grafo.assign(n, {});
    for(long long i = 0; i < n - 1; i++){
        long long a;
        cin>>a;
        a--;
        Grafo[i + 1].push_back(a);
        Grafo[a].push_back(i + 1);
    }
    for(long long i = 0; i < n; i++){
        Representantes.push_back(i);
        long long l, r;
        cin>>l>>r;
        L_mites.push_back({l, r});
        El_enano.push_back(Tama_o(i));
    }
    long long q;
    cin>>q;
    while(q--){
        long long a, b, c, d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        c--;
        d--;
        Por_aqu_.clear();
        deque<long long> a_b, c_d;
        DFS(a, b, -2);
        a_b = Por_aqu_;
        Por_aqu_.clear();
        DFS(c, d, -2);
        c_d = Por_aqu_;
        long long nn = a_b.size();
        for(long long i =)
    }
    return 0;
}