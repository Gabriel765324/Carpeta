#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double a, b;
    cin>>a>>b;
    double c = a / b;
    if(c - (double)((long long)c) >= 0.5) cout<<(long long)c + 1;
    else cout<<(long long)c;
    return 0;
}