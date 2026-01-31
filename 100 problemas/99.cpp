#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin>>n>>t;
    int a = 0;
    while(n--){
        int b;
        cin>>b;
        if(a >= b){
            cout<<a + t<<"\n";
            a += t;
        } else {
            cout<<b + t<<"\n";
            a = b + t;
        }
    }
    return 0;
}