#include "bits/stdc++.h"
#define vi vector<int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp make_pair
#define ii pair<int, int>
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define ld long double
#define el "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long double d, v0, v1, v2, t, ta = 0, p = 0;
    cin>>d>>v0>>v1>>v2>>t;
    bool Adelante = 1;
    while(t - ta > (ld)1e-9){
        if(Adelante){
            ld te = abs(min((ld)1 + v1 * ta, d) - p) / (v2 - v1);
            if(p + te * v2 >= d) te = abs(d - p) / v2;
            ta += te;
            if(ta > t){
                ta -= te;
                te = t - ta;
                ta = t;
            }
            p += te * v2;
            Adelante = 0;
        } else {
            ld te = abs(min(v0 * ta, d) - p) / (v2 + v0);
            ta += te;
            if(ta > t){
                ta -= te;
                te = t - ta;
                ta = t;
            }
            if(d - v0 * ta <= (ld)8e-7) break;
            p -= te * v2;
            Adelante = 1;
        }
        //cerr<<ta<<" "<<v0 * ta<<" "<<(ld)1 + v1 * ta<<" "<<p<<el;
    }
    cout<<setprecision(22)<<p<<el;
    return 0;
}