#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    multiset<int> s;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int n;
            cin>>n;
            s.insert(n);
        } else {
            cout<<*s.begin()<<"\n";
            s.erase(s.begin());
        }
    }
    return 0;
}