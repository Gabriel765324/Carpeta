#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r = 0;
    cin>>n>>m;
    vector<string> a(n);
    vector<int> p(n, 0);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++){
        int x = 0, y = 0;
        for(int j = 0; j < n; j++){
            if(a[j][i] == '0') x++;
            else y++;
        }
        if(x < y){
            for(int j = 0; j < n; j++){
                if(a[j][i] == '0') p[j]++;
                r = max(r, p[j]);
            }
        } else if(x > y){
            for(int j = 0; j < n; j++){
                if(a[j][i] == '1') p[j]++;
                r = max(r, p[j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(p[i] == r) cout<<i + 1<<" ";
    }
    return 0;
}