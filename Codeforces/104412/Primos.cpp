#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(long long i = 1222222222; i < 1222222222 + 2222; i++){
        bool Bien = 1;
        for(long long j = 2; j * j <= i; j++){
            if(i % j == 0LL){
                Bien = 0;
                break;
            }
        }
        if(Bien) cout<<i<<" "<<i * i<<"\n";
    }
    return 0;
}