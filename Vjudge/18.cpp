#pragma GCC target("popcnt")
#include "bits/stdc++.h"
using namespace std;
const int_fast16_t m0 = 3000, m1 = 47;
int_fast64_t a[m0][m1] = {};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int_fast16_t n = 3000;
    memset(a, 0, sizeof(a));
    //cin>>n;
    for(int_fast16_t i = 0; i < n; i++){
        string s(n, '1');
        //cin>>s;
        for(int_fast16_t j = 0; j < n; j++){
            a[i][j / 64] += (s[j] - '0') * ((int_fast64_t)1<<((int_fast64_t)j % (int_fast64_t)64));
        }
    }
    int_fast64_t r = 0;
    for(int_fast16_t i = 0; i < n - 1; i++){
        for(int_fast16_t j = i + 1; j < n; j++){
            int_fast64_t e = 0;
            for(int_fast16_t k = 0; k < 47; k++){
                e += (int_fast64_t)__popcount(a[i][k] & a[j][k]);
            }
            //cerr<<((e * e - e)>>(int_fast64_t)1)<<" "<<i<<" "<<j<<"\n";
            r += (e * e - e)>>(int_fast64_t)1;
        }
    }
    cerr<<setprecision(22)<<(long double)clock() / (long double)CLOCKS_PER_SEC<<"\n";
    cout<<r;
    return 0;
}