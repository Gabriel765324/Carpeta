#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.rbegin(), a.rend());
    for(int i = n + 22; i > -1; i--){
        int j = 0, k = n - 1, m = -1;
        while(1){
            int p = (j + k) / 2;
            if(a[p] >= i){
                j = p + 1;
                m = p;
            } else {
                k = p - 1;
            }
            if(j >= k + 1) break;
        }
        m++;
        if(m >= i){
            cout<<i;
            return 0;
        }
    }
    return 0;
}