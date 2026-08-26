#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> a(n, 0);
    while(q--){
        int x;
        cin>>x;
        x--;
        if(x >= 0){
            a[x]++;
            cout<<x + 1<<" ";
        } else {
            int m = INT_MAX, p = -2;
            for(int i = 0; i < n; i++){
                if(a[i] < m){
                    m = min(m, a[i]);
                    p = i;
                }
            }
            a[p]++;
            cout<<p + 1<<" ";
        }
    }
    return 0;
}