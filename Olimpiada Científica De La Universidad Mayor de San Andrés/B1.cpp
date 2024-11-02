#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    for(long long i = 0; i < t; i++){
        bool Primo = 1;
        long long n;
        cin>>n;
        for(long long j = 2; (j * j) <= n; j++){
            if((n % j) == 0){
                Primo = 0;
                break;
            }
        }
        if(n == 1 or n == 0) Primo = 0;
        cout<<n<<": ";
        if(Primo){
            long long d = 10;
            for(long long j = 0; j < 40; j++){
                cout<<d / n<<" ";
                d = d % n;
                d *= 10;
                //if(j < 39) cout<<" ";
            }
        } else cout<<"-1";
        //if(i < (t - 1)) cout<<"\n";
        cout<<"\n";
    }
    return 0;
}