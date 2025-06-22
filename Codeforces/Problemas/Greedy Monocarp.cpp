#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, k, Suma = 0;
        cin>>n>>k;
        vector<long long> a(n);
        bool Bien = 0;
        for(long long i = 0; i < n; i++) cin>>a[i];
        sort(a.rbegin(), a.rend());
        for(long long i = 0; i < n; i++){
            Suma += a[i];
            if(Suma == k){
                cout<<"0\n";
                Bien = 1;
                break;
            } else if(Suma > k){
                Bien = 1;
                Suma -= a[i];
                cout<<k - Suma<<"\n";
                break;
            }
        }
        if(Bien == 0) cout<<k - Suma<<"\n";
    }
    return 0;
}