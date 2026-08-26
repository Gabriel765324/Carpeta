#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, p = 0;
        cin>>n;
        while(n % 5 == 0){
            n /= 5;
            n *= 4;
            p++;
        }
        while(n % 3 == 0){
            n /= 3;
            n *= 2;
            p++;
        }
        while(n % 2 == 0){
            n /= 2;
            p++;
        }
        if(n == 1) cout<<p<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}