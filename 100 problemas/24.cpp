#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    set<int> s;
    while(n--){
        int a;
        cin>>a;
        s.insert(a);
    }
    cout<<s.size()<<"\n";
    for(auto E: s) cout<<E<<" ";
    return 0;
}