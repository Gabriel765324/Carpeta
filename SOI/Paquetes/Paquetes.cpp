#include "bits/stdc++.h"
using namespace std;
struct A{
    long long p, e, i;
};
bool o1(A& a, A& b){
    return a.p < b.p;
}
bool o2(A& a, A& b){
    return a.e > b.e;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<A> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].p;
        a[i].i = i;
    }
    for(int i = 0; i < n; i++) cin>>a[i].e;
    if(n == 1){
        cout<<a[0].e;
        return -0;
    }
    vector<A> p, e;
    sort(a.begin(), a.end(), o1);
    p.push_back(a[0]);
    p.push_back(a[1]);
    sort(a.begin(), a.end(), o2);
    e.push_back(a[0]);
    e.push_back(a[1]);
    long long r = LLONG_MAX;
    for(auto E: p){
        for(auto EE: e){
            if(E.i != EE.i){
                r = min(r, 2LL * E.p - EE.e);
            }
        }
    }
    for(auto E: a){
        r += 2LL * E.e - 2LL * E.p;
    }
    cout<<r;
    return 0;
}