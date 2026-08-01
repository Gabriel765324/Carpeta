#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n >= 3 or n == 1){
        cout<<"S\n";
        return 0;
    }
    vector<int> a, b;
    int c;
    cin>>c;
    while(c--){
        cin>>n;
        a.push_back(n);
    }
    cin>>c;
    while(c--){
        cin>>n;
        b.push_back(n);
    }
    reverse(b.begin(), b.end());
    for(auto E: b) a.push_back(E);
    bool Bien = 1;
    for(int i = 1; i < int(a.size()); i++){
        Bien = Bien and a[i] >= a[i - 1];
    }
    if(Bien) cout<<"S\n";
    else cout<<"N\n";
    return 0;
}