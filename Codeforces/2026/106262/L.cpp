#include "bits/stdc++.h"
using namespace std;
struct Par{
    int x, y;
    long long v;
    Par(){}
    bool operator<(const Par& a) const{
        return make_pair(x, y) < make_pair(a.x, a.y);
    }
    bool operator==(const Par& a) const{
        return make_pair(x, y) == make_pair(a.x, a.y);
    }
};
long long m = 1006903069;
long long S(long long a, long long b){
    return ((a % m) + (b % m)) % m;
}
long long M(long long a, long long b){
    return ((a % m) * (b % m)) % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ka, kb, i = 0, j = 0;
    cin>>n>>ka;
    long long r = 0;
    vector<Par> a(ka);
    for(int i = 0; i < ka; i++) cin>>a[i].x>>a[i].y>>a[i].v;
    cin>>kb;
    vector<Par> b(kb);
    for(int i = 0; i < ka; i++) cin>>b[i].y>>b[i].x>>b[i].v;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(i < ka and j < kb){
        //cerr<<i<<" "<<j<<"\n";
        if(i >= ka){
            r = S(r, b[j].v);
            j++;
            continue;
        }
        if(j >= kb){
            r = S(r, a[i].v);
            i++;
            continue;
        }
        if(a[i] == b[j]){
            r = S(r, M(a[i].v, b[j].v));
            i++;
            j++;
        } else if(a[i] < b[j]){
            i++;
        } else {
            j++;
        }
    }
    cout<<r % m<<"\n";
    return 0;
}