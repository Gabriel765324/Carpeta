#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long s = 0, m = 1;
    cin>>n;
    while(n--){
        long long a;
        cin>>a;
        s += a * m;
        m = 1 - m;
    }
    cout<<s;
    return 0;
}