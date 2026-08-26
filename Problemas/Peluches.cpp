#include "bits/stdc++.h"
using namespace std;
long long m = 998244353;
long long Suma(long long a, long long b){
    return (a % m + b % m) % m;
}
long long Resta(long long a, long long b){
    return ((a % m - b % m) % m + m) % m;
}
/*long long Resta(long long a, long long b){
    return ((a % m - b % m) % m + m) % m;
}*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long q, k;
    cin>>q>>k;
    vector<long long> Subconjuntos(k + 1, 0);
    Subconjuntos[0]++;
    while(q--){
        char c;
        long long x;
        cin>>c>>x;
        //cout<<c<<" "<<x<<"\n";
        if(c == '+'){
            for(long long i = k; (i - x) > -1; i--){
                //cout<<i<<" "<<Subconjuntos[i]<<" "<<i - x<<" "<<Subconjuntos[i - x]<<"\n";
                Subconjuntos[i] = Suma(Subconjuntos[i], Subconjuntos[i - x]);
            }
        } else {
            for(long long i = 0; i + x <= k; i++){
                Subconjuntos[i + x] = Resta(Subconjuntos[i + x], Subconjuntos[i]);
            }
        }
        //for(auto E: Subconjuntos) cout<<E<<" ";
        cout<<Subconjuntos[k]<<"\n";
    }
    return 0;
}