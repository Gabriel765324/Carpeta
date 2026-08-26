#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> a;
    int i = 3;
    while(i--){
        int b;
        cin>>b;
        a.insert(b);
    }
    if(a.size() < 3) cout<<"Yes";
    else cout<<"No";
    return 0;
}