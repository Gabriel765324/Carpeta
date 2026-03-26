#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '#'){
                int s = 0;
                if(i > 0 and a[i - 1][j] == '#') s++;
                if(j > 0 and a[i][j - 1] == '#') s++;
                if(i < n - 1 and a[i + 1][j] == '#') s++;
                if(j < m - 1 and a[i][j + 1] == '#') s++;
                if(s != 2 and s != 4){
                    cout<<"No";
                    return 0;
                }
            }
        }
    }
    cout<<"Yes";
    return 0;
}