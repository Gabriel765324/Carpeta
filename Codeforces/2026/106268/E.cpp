#include "bits/stdc++.h"
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
struct Fracci_n{
    ull p, q;
    Fracci_n(){
        p = 1;
        q = 1;
    }
    Fracci_n(ull a, ull b){
        ull MCD = __gcd(a, b);
        p = a / MCD;
        q = b / MCD;
    }
    bool operator<(const Fracci_n& a) const{
        return p * a.q < q * a.p;
    }
    bool operator>(const Fracci_n& a) const{
        return p * a.q > q * a.p;
    }
};
void Resolver(){
    ld a, b, c, k, i = 1e-10, d = 2e9, m = 2e9;
    cin>>a>>b>>c>>k;
    while(1){
        ld p = (i + d) / (ld)2;
        //cerr<<p<<" "<<m<<"\n";
        if(abs(m - p) <= (ld)1e-10) break;
        if((ld)floor(a / p) * (ld)floor(b / p) * (ld)floor(c / p) >= k){
            m = p;
            i = p;
        } else {
            d = p;
        }
    }
    Fracci_n Mejor = min(Fracci_n((ull)round(a), (ull)floor(a / m)), min(Fracci_n((ull)round(b), (ull)floor(b / m)), Fracci_n((ull)round(c), (ull)floor(c / m))));
    cout<<Mejor.p<<" "<<Mejor.q<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}