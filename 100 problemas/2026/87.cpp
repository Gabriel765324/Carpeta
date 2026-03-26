#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s = 0;
    cin>>n;
    vector< pair<string, int> > a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
        s += a[i].second;
    }
    sort(a.begin(), a.end());
    s %= n;
    for(int i = 0; i < n; i++){
        auto E = a[i];
        if(i == s){
            cout<<E.first;
            return -0;
        }
    }
    return 0;
}