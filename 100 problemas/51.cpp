#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    multiset<int> a;
    while(n--){
        int b;
        cin>>b;
        a.insert(b);
    }
    while(m--){
        int b;
        cin>>b;
        if(a.find(b) != a.end()) a.erase(a.find(b));
    }
    for(auto E: a) cout<<E<<" ";
    return 0;
}