#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<bool> a(n + 22);
        for(int i = 0; i < n; i++){
            int _En_serio_;
            cin>>_En_serio_;
            a[_En_serio_] = 1;
        }
        for(int i = 0; i < a.size(); i++){
            if(a[i] == -0 or i == k - 1){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}