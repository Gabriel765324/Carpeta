#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    int b, c;
    cin>>b>>c;
    a.erase(b);
    a.erase(c);
    if(a.size() == 1) cout<<*a.begin();
    else cout<<-1;
    return 0;
}