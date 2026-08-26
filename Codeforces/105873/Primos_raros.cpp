#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(long long i = 1e9; i <= (long long)1e9 + (long long)2222; i++){
        //cerr<<i<<"\n";
        bool Bien = 1;
        for(long long j = 2; j * j <= i; j++){
            if(i % j == 0){
                //cerr<<i<<" "<<j<<"\n";
                Bien = 0;
                break;
            }
        }
        //cerr<<Bien<<"\n";
        if(Bien) cout<<i<<"\n";
    }
    return 0;
}