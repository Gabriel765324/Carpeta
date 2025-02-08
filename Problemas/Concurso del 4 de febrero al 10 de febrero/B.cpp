#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    string Mejor = "aabb";
    for(long long i = 0; i < n; i++){
        cout<<Mejor[i % 4];
    }
    return 0;
}