#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i = -2, j = -2;
    cin>>n;
    for(int k = 0; k < n; k++){
        int a;
        cin>>a;
        if(a == 1){
            if(i == -2) i = k;
            j = k;
        }
    }
    cout<<j - i;
    return 0;
}