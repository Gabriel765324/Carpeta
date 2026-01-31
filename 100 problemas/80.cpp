#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    if(a > b) swap(a, b);
    cout<<(a <= c and c <= b ? "Yes" : "No");
    return 0;
}