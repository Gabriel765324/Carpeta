#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, x;
    cin>>r>>x;
    if((x == 1 and r >= 1600 and r <= 2999) or (x == 2 and r >= 1200 and r <= 2399)) cout<<"Yes";
    else cout<<"No";
    return 0;
}