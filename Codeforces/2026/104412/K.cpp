#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, r = 0;
    cin>>n>>k;
    vector< vector<int> > a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0; i + k - 1 < n; i++){
        for(int j = 0; j + k - 1 < n; j++){
            r += (a[i][j] == a[i][j + k - 1] and a[i + k - 1][j] == a[i][j + k - 1] and a[i + k - 1][j + k - 1] == a[i][j + k - 1]) ? 1 : 0;
        }
    }
    cout<<r<<"\n";
    return 0;
}