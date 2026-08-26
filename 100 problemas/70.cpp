#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, p;
    cin>>n>>p;
    vector<long long> a(n * 2 + 3, 2);
    for(long long i = 0; i < n; i++){
        cin>>a[2 * i + 2];
    }
    a[0] = 1;
    a.back() = 1;
    p *= 2;
    p++;
    long long i = 0, j = n * 2 + 2;
    for(; i < p - 1; i += 2){
        if(a[i] == 0) break;
    }
    for(; j > p + 1; j -= 2){
        if(a[j] == 0) break;
    }
    long long r = 0;
    for(long long k = i + 2; k <= j - 2; k += 2) r += a[k] + 1;
    r += 2 - a[i] - a[j];
    cout<<r;
    return 0;
}