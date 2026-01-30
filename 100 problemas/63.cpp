#include "bits/stdc++.h"
using namespace std;
long long f(long long n){
    vector<long long> a;
    while(n > 0){
        a.push_back(n % 10LL);
        n /= 10LL;
    }
    n = 0;
    long long d = 1;
    for(int i = a.size() - 1; i > -1; i--){
        n += a[i] * d;
        d *= 10LL;
    }
    return n;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long x, y;
    cin>>x>>y;
    vector<long long> a = {x, y};
    int i = 0;
    while(a.size() < 10){
        a.push_back(f(a[i] + a[i + 1]));
        i++;
    }
    cout<<a.back();
    return 0;
}