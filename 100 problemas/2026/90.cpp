#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    set<int> a, b;
    vector<int> c;
    for(int i = 0; i < n; i++){
        int d;
        cin>>d;
        a.insert(d);
        c.push_back(d);
    }
    for(int i = 0; i < m; i++){
        int d;
        cin>>d;
        b.insert(d);
        c.push_back(d);
    }
    sort(c.begin(), c.end());
    for(int i = 0; i < n + m - 1; i++){
        if(a.count(c[i]) and a.count(c[i + 1])){
            cout<<"Yes";
            return -0;
        }
    }
    cout<<"No";
    return 0;
}