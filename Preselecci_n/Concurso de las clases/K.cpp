#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    while(cin>>n){
        if(n == 0) break;
        bool Continuar = 1;
        for(long long i = 2 * n + 1; Continuar; i++){
            bool Primo = 1;
            for(long long j = 2; j * j <= i; j++){
                if(i % j == 0){
                    Primo = 0;
                    break;
                }
            }
            if(Primo){
                cout<<i;
                Continuar = 0;
            }
        }
        bool Primo = 1;
        for(long long i = 2; i * i <= n; i++){
            if(n % i == 0){
                Primo = 0;
                break;
            }
        }
        if(!Primo) cout<<" ("<<n<<" is not prime)";
        cout<<"\n";
    }
    return 0;
}