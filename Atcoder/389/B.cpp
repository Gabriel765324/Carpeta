#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    long long i = 1;
    for(i = 1; n > 1; i++) n /= i;
    cout<<i - 1;
    return 0;
}