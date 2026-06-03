#include "bits/stdc++.h"
using namespace std;
struct Rango{
    long long l, r;
    Rango(){}
    bool operator<(const Rango& a){
        if(r - l < a.r - a.l) return 1;
        if(r - l > a.r - a.l) return 0;
        if(l < a.l) return 1;
        if(l > a.l) return 0;
        return r < a.r;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Rango> q(n);
    vector<long long> Extra(222, 0);
    for(int i = 0; i < n; i++){
        cin>>q[i].l>>q[i].r;
        q[i].l <<= 1LL;
        q[i].r <<= 1LL;
    }
    sort(q.rbegin(), q.rend());
    long long r = 0;
    for(int i = 0; i < n; i++){
        long long p = (q[i].l + q[i].r) >> 1LL;
        for(; q[i].l <= q[i].r; q[i].l++){
            r += Extra[q[i].l];
        }
        Extra[p]++;
    }    
    cout<<r;
    return 0;
}