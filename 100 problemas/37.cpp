#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int r = 2;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin>>a[i];
        if(n == 2){
            if(a[1] <= 2 * a[0]) cout<<"2\n";
            else cout<<"-1\n";
            continue;
        }
        sort(a.begin() + 1, a.end() - 1);
        int Tama_o_mayor = 2 * a[0];
        for(int i = 1; i < n; i++){
            if(a.back() <= Tama_o_mayor) break;
            if(i == n - 1){
                r = -1;
                break;
            }
            int I = i, D = n - 2, m = n;
            while(1){
                int p = (I + D) / 2;
                if(a[p] <= Tama_o_mayor){
                    I = p + 1;
                    m = p;
                } else {
                    D = p - 1;
                }
                if(I >= D + 1) break;
            }
            if(m == n){
                r = -1;
                break;
            }
            Tama_o_mayor = 2 * a[m];
            i = m;
            r++;
        }
        cout<<r<<"\n";
    }
    return 0;
}