#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, k;
    cin>>n>>m>>k;
    if(m * k > n) cout<<"King Canute\n";
    else cout<<"Iron fist Ketil\n";
    return 0;
}