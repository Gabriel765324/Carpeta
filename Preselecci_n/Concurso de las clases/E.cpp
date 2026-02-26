#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> a;
    string s;
    while(cin>>s) a.push_back(s);
    set<string> r;
    long long n = a.size();
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            if(i != j) r.insert(a[i] + a[j]);
        }
    }
    for(auto E: r) cout<<E<<"\n";
    return 0;
}