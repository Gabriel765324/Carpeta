#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin>>a>>b;
    int n = a.size(), m = b.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            if(j == m){
                cout<<"Yes";
                return 0;
            }
            if(j + i >= n) break;
            if(!(a[i + j] == b[j] or a[i + j] == '?')) break;
        }
    }
    cout<<"No";
    return 0;
}