#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long r = 0, s = 0, Mayor = LLONG_MIN;
    bool Primero = 1, No_negativo = 0;
    for(int i = 0; i < n; i++){
        long long a;
        cin>>a;
        Mayor = max(a, Mayor);
        s = max(0LL, a + s);
        r = max(r, s);
        if(a >= 0) No_negativo = 1;
    }
    if(No_negativo) cout<<r;
    else cout<<Mayor;
    return 0;
}