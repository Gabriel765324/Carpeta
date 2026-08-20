#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(long long i = 2000222000; i <= 2000224222; i++){
        bool Primo = 1;
        for(long long j = 2; j * j <= i; j++) Primo = Primo and (i % j != 0);
        if(Primo) cout<<i<<"\n";
    }
    return 0;
}