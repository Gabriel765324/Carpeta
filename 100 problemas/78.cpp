#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> a(n), b = a;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(a[i][j] != b[i][j]){
        cout<<i + 1<<" "<<j + 1;
        return -0;
    }
    return 0;
}