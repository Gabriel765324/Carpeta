#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    map<int, int> p;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]--;
        p[a[i]] = i;
    }
    vector< pair<int, int> > r;
    for(int i = 0; i < n; i++){
        if(a[i] != i){
            r.push_back({i + 1, p[i] + 1});
            swap(a[i], a[p[i]]);
            p[a[p[i]]] = p[i];
            p[i] = i;
        }
    }
    cout<<r.size()<<"\n";
    for(auto E: r){
        cout<<E.first<<" "<<E.second<<"\n";
    }
    return 0;
}