#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin>>n>>k;
    k--;
    vector<long long> a(n), d(n - 1);
    for(long long i = 0; i < n; i++){
        cin>>a[i];
    }
    for(long long i = 0; i < (n - 1); i++){
        d[i] = a[i + 1] - a[i] - 1;
    }
    sort(d.rbegin(), d.rend());
    long long Operando = a.back() - a[0] + 1;
    for(long long i = 0; i < k; i++) Operando -= d[i];
    cout<<Operando;
    return 0;
}