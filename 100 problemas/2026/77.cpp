#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r = 1, i = 9, j = 8;
    while(i--){
        int a;
        cin>>a;
        r += a;
    }
    while(j--){
        int a;
        cin>>a;
        r -= a;
    }
    if(r < 0){
        cout<<-0;
        return 0;
    }
    cout<<r;
    return 0;
}