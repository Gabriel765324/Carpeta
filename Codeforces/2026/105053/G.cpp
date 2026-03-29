#include "bits/stdc++.h"
using namespace std;
int n;
long double t;
vector<long double> a, PD;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    //PD.assign(n)
    for(long long i = 1; i <= n; i++){
        for(long long j = 1; j <= n; j++){
            cout<<i<<" "<<j<<" "<<i / __gcd(i, j) * j<<"\n";
        }
    }
    return 0;
}