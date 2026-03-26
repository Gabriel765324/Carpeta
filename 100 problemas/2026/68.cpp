#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long x, c;
    cin>>x>>c;
    long long m = 0;
    while(1){
        if((1000LL + c) * m > x){
            m--;
            break;
        }
        m++;
    }
    cout<<m * 1000LL;
    return 0;
}