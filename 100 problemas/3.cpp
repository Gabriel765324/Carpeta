#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long n, r = 0, Base = 2;
    cin>>n;
    while(Base <= n){
        r += (long long)((long double)0.5 * (sqrt((long double)n / (long double)Base) + (long double)1.0));
        Base *= 2;
    }
    cout<<r;
    return 0;
}