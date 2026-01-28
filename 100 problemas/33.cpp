#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n, 0);
    for(int i = 1; i < n; i++){
        cin>>a[i];
        a[i] += a[i - 1];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int r = a[j] - a[i];
            cout<<r<<" ";
        }
        cout<<"\n";
    }
    return 0;
}