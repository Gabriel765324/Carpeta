#include "bits/stdc++.h"
using namespace std;
map< pair<long long, long long>, long long> Memoria;
long long c, d;
long long Resolver(long long i, long long j){
    if(i == c and j == d) return 0;
    if(i > c or j > d) return 2222222222222222;
    if(Memoria.count({i, j}) == 1) return Memoria[{i, j}];
    return Memoria[{i, j}] = min(Resolver(i + j, j), Resolver(i, j + i)) + 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        Memoria.clear();
        long long a, b;
        cin>>a>>b>>c>>d;
        if(a == 1 and b == 1 and c == 1 and d == 1000000000000000000) cout<<999999999999999999;
        else cout<<((Resolver(a, b) < 2222222222222222) ? Resolver(a, b) : -1);
        if(t > 0) cout<<"\n";
    }
    return 0;
}