#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        if(a >= m){
            cout<<i + 1<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}