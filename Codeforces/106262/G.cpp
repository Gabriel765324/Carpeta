#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long b, Mayor = -22222222;
    cin>>n>>b;
    n--;
    vector<long long> a(n);
    bool No_negativo = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b += max(0LL, a[i]);
        Mayor = max(Mayor, a[i]);
        No_negativo = No_negativo or a[i] >= 0LL;
    }
    if(No_negativo) cout<<b<<"\n";
    else cout<<(b >= abs(Mayor) ? b + Mayor : -1)<<"\n";
    return 0;
}