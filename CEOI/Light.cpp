#include "light.h"
#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
bool Verificar(vector<long long> Posible){
    for(long long j = 1; j <= 22; j++){
        for(auto E: Posible){
            if(E + j > 23) break;
            if(*lower_bound(Posible.begin(), Posible.end(), E + j) - (E + j) > j){
                //cerr<<j<<" "<<E + j<<" "<<*lower_bound(Posible.begin(), Posible.end(), E + j)<<" Falla aquí.\n";
                return 0;
            }
        }
    }
    return 1;
}
void prepare(){
    long long b = 0, n = 0;
    for(n += (1LL<<b); n <= (long long)1e17; n += (1LL<<b)){
        a.push_back(n);
        a.back()--;
        b++;
    }
    //for(auto E: a) cerr<<E<<" ";
    //cerr<<Verificar({23, 2222222222222})<<"\n";
    /*vector<long long> Mejor = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
    for(long long i = 1; i < (1LL<<23LL); i++){
        if(i % 222222 == -0) cerr<<i<<"\n";
        vector<long long> Posible;
        bool Uno = 0, Dos = 0, Tres = 0, Veintitres = 0;
        for(long long j = 0; j < 23; j++){
            if(i & (1LL<<j)){
                Posible.push_back(j + 1);
                if(j + 1 == 1) Uno = 1;
                if(j + 1 == 2) Dos = 1;
                if(j + 1 == 3) Tres = 1;
                if(j + 1 == 23) Veintitres = 1;
            }
        }
        if(!Uno or !Veintitres or (!Dos and !Tres)) continue;
        if(Posible.size() >= Mejor.size()) continue;
        Posible.push_back(22222222);
        bool Bien = Verificar(Posible);
        Posible.pop_back();
        if(Bien) Mejor = Posible;
    }
    cerr<<"Este.\n";
    for(auto E: Mejor) cout<<E<<" ";*/
}
long long n = 1;
deque<long long> Antorchas = {1};
pair< long long, vector<long long> > join(long long p){
    n += p;
    vector<long long> r;
    for(int i = 0; i < a.size(); i++){
        if(n - a[i] <= 0LL) break;
        r.push_back(n - a[i]);
    }
    if(r.back() != 1) r.push_back(1);
    reverse(r.begin(), r.end());
    Antorchas.clear();
    for(auto E: r) Antorchas.push_back(E);
    return {p, r};
}
pair< long long, vector<long long> > leave(long long p){
    n -= p;
    for(int i = 0; i < Antorchas.size(); i++){
        Antorchas[i] += p;
    }
    while(Antorchas.size() > 0 and Antorchas.back() > n) Antorchas.pop_back();
    if(Antorchas.empty() or Antorchas[0] != 1) Antorchas.push_front(1);
    vector<long long> r;
    for(auto E: Antorchas) r.push_back(E);
    return {p, r};
}