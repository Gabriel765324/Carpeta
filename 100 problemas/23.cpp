#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    int a = 0;
    while(n--){
        int b;
        cin>>b;
        if(b - a > k){
            cout<<"No";
            return 0;
        }
        a = b;
    }
    cout<<"Yes";
    return 0;
}