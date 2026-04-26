#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> r = {2LL * 2LL * 2LL * 2LL * 3LL * 3LL * 3LL * 5LL * 5LL * 7LL * 11LL * 13LL * 17LL * 19LL * 23LL * 29LL};
        for(int i = 2; i < n; i++){
            r.push_back(i - 1);
        }
        for(auto E: r) cout<<E<<" ";
        cout<<"\n";
    }
    return 0;
}