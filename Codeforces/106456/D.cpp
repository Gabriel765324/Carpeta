#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        if(n & 1){
            long long a = n >> 1, b = n - a;
            cout<<a * b<<"\n";
        } else {
            long long r = 0;
            for(int i = 0; i < 100; i++){
                long long a = (n >> 1) - i, b = n - a;
                if(a <= 0LL or b <= 0LL) break;
                r = max(r, a / __gcd(a, b) * b);
            }
            cout<<r<<"\n";
        }
    }
    return 0;
}