#include "bits/stdc++.h"
using namespace std;
long long f(long long x){
    return x * x + 2 * x + 3;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long x;
    cin>>x;
    cout<<f(f(f(x) + x) + f(f(x)));
    return 0;
}