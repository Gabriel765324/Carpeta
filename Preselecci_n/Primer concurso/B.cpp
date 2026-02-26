#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long k;
    bool Primero = 1;
    while(cin>>k){
        if(k == 0) return 0;
        if(!Primero) cout<<"\n";
        else Primero = 0;
        vector<long long> g(k);
        for(long long i = 0; i < k; i++){
            cin>>g[i];
        }
        for(long long a = 0; a + 5 < k; a++){
            for(long long b = a + 1; b + 4 < k; b++){
                for(long long c = b + 1; c + 3 < k; c++){
                    for(long long d = c + 1; d + 2 < k; d++){
                        for(long long e = d + 1; e + 1 < k; e++){
                            for(long long f = e + 1; f < k; f++){
                                cout<<g[a]<<" "<<g[b]<<" "<<g[c]<<" "<<g[d]<<" "<<g[e]<<" "<<g[f]<<"\n";
                            }
                        }
                    }
                }
            }
        }
    }
}