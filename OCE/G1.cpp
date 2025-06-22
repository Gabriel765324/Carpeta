#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, q;
    cin>>n>>q;
    vector<long long> a(n);
    for(long long i = 0; i < n; i++) cin>>a[i];
    vector<long long> Uno(n), Dos(n), Impar(n);
    for(long long i = 0; i < n; i++){
        if(a[i] == 1) Uno[i] = 1;
        else Uno[i] = 0;
        if((a[i] % 2) == 1) Impar[i] = a[i];
        else Impar[i] = 0;
        long long b = a[i];
        while((b % 2) == 0) b /= 2;
        if(b == 1) Dos[i] = a[i];
        else Dos[i] = 0;
        if(i > 0){
            Uno[i] += Uno[i - 1];
            Dos[i] += Dos[i - 1];
            Impar[i] += Impar[i - 1];
        }
    }
    while(q--){
        long long l, r;
        cin>>l>>r;
        l--;
        r--;
        long long u = Uno[r], d = Dos[r], i = Impar[r];
        if(l > 0){
            u -= Uno[l - 1];
            d -= Dos[l - 1];
            i -= Impar[l - 1];
        }
        long long A = (u + 1) / 2 + d, B = u / 2 + i;
        if(A > B) cout<<"A\n";
        else if(B > A) cout<<"B\n";
        else cout<<"E\n";
    }
    return 0;
}