#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    vector<bool> Todos(n + 22, 0);
    vector< map<int, bool> > Puede(n + 22);
    while(q--){
        int t, x, y;
        cin>>t;
        switch(t){
            case 1:
            cin>>x>>y;
            Puede[x][y] = 1;
            break;
            case 2:
            cin>>x;
            Todos[x] = 1;
            break;
            case 3:
            cin>>x>>y;
            cout<<((Todos[x] or Puede[x][y]) ? "Yes" : "No")<<"\n";
            break;
        }
    }
    return 0;
}