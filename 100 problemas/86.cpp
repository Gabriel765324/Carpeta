#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int s = 0, Dos = 1, r = 1;
    while(1){
        s += Dos;
        if(s > n){
            cout<<r;
            return -0;
        }
        Dos *= 2;
        r++;
    }
    return 0;
}