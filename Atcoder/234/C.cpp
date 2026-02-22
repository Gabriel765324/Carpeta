#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    deque<int> s;
    for(long long i = 0; (1LL<<i) <= n; i++){
        s.push_front((((1LL<<i) & n) == 0) ? 0 : 2);
    }
    for(auto E: s) cout<<E;
    return 0;
}