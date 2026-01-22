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
        vector< vector<int> > Grafo(n);
        int m = n - 1;
        while(m--){
            int a, b;
            cin>>a>>b;
            a--;
            b--;
            Grafo[a].push_back(b);
            Grafo[b].push_back(a);
        }
        
    }
    return 0;
}