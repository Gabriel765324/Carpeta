#include "light.h"
#include <bits/stdc++.h>
using namespace std;
vector<long long> Dos;
void prepare(){
    long long b = 0, n = 0;
    for(n += (1LL<<b); n <= (long long)1e17; n += (1LL<<b)){
        Dos.push_back(n);
        Dos.back()--;
        b++;
    }
}
long long n = 1;
bool Se_fue = 0;
pair< long long, vector<long long> > join(long long p){
    n += p;
    vector<long long> r;
    if(Se_fue){
        r = {n};
        return {p, r};
    }
    for(auto E: Dos){
        if(n - E < 1) break;
        r.push_back(n - E);
    }
    if(r.back() != 1) r.push_back(1);
    reverse(r.begin(), r.end());
    return {p, r};
}
pair< long long, vector<long long> > leave(long long p){
    n -= p;
    Se_fue = 1;
    vector<long long> r = {n};
    return {p, r};
}