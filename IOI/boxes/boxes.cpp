#include "boxes.h"
#include "bits/stdc++.h"
using namespace std;
long long delivery(int n, int k, int L, int P[]){
    long long r = LLONG_MAX, l = L;
    vector<long long> p;
    for(int i = 0; i < n; i++) if(P[i] != 0) p.push_back(P[i]);
    n = p.size();
    if(n == 0) return 0;
    vector<long long> Izquierda(n), Derecha(n + 1, 0);
    for(int i = 0; i < k and i < n; i++){
        Izquierda[i] = p[i] + min(p[i], l - p[i]);
        Derecha[n - i - 1] = l - p[n - i - 1] + min(p[n - i - 1], l - p[n - i - 1]);
    }
    for(int i = k; i < n; i++){
        Izquierda[i] = p[i] + min(p[i], l - p[i]) + Izquierda[i - k];
        Derecha[n - i - 1] = l - p[n - i - 1] + min(p[n - i - 1], l - p[n - i - 1]) + Derecha[n - i - 1 + k];
    }
    for(int i = 0; i < n; i++){
        r = min(r, Izquierda[i] + Derecha[i + 1]);
        //cerr<<Izquierda[i]<<" "<<Derecha[i + 1]<<"\n";
    }
    //cerr<<"0 "<<Derecha[0]<<"\n";
    r = min(r, Derecha[0]);
    //cerr<<r;
    return r;
}