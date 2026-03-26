#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    set<string> s;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j) s.insert(a[i] + a[j]);
        }
    }
    cout<<s.size();
    return 0;
}