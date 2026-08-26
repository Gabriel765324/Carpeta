#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c = 0;
    cin>>n>>m;
    vector<bool> v(m, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        a--;
        if(a < m){
            if(!v[a]) c++;
            if(c == m){
                cout<<n - i;
                return 0;
            }
            v[a] = 1;
        }
    }
    cout<<0;
    return 0;
}