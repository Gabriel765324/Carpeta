#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const long long c = 10000001;
    bitset<c> Primos;
    Primos[0] = 1;
    Primos[1] = 1;
    for(long long i = 2; i < c; i++){
        if(!Primos[i]){
            for(long long j = i * i; j < c; j += i){
                Primos[j] = 1;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n, l;
        cin>>n>>l;
        long long r = 0;
        if(l == 1) r = n;
        if(l == 2){
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    if(!Primos[j - i]){
                        r++;
                    }
                }
            }
        }
        if(l == 3){
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    for(int k = j + 1; k <= n; k++){
                        if(!Primos[k - i] and !Primos[j - i] and !Primos[k - j]){
                            //cout<<i<<" "<<j<<" "<<k<<"\n";
                            r++;
                        }
                    }
                }
            }
        }
        cout<<r % 104206969LL<<"\n";
    }
    return 0;
}