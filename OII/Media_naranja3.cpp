#include "bits/stdc++.h"
using namespace std;
struct Rango{
    int l, r, m;
    Rango(){}
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Rango> q(n);
    for(int i = 0; i < n; i++){
        cin>>q[i].l>>q[i].r;
        q[i].m = q[i].l + q[i].r;
        q[i].l <<= 1;
        q[i].r <<= 1;
    }
    long long r = 0;
    for(int i = 0; i < n; i++){
        int I = i + 1, D = n - 1, m = i;
        while(I < D + 1){
            int p = (I + D) / 2;
            if(q[p].l <= q[i].m){
                m = p;
                I = p + 1;
            } else D = p - 1;
        }
        I = i + 1;
        D = m;
        m = i;
        while(I < D + 1){
            int p = (I + D) / 2;
            if(q[p].m <= q[i].r){
                m = p;
                I = p + 1;
            } else D = p - 1;
        }
        r += max(0LL, (long long)m - (long long)i);
    }
    cout<<r;
    return 0;
}