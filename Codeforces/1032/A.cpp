#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        int n, s;
        cin>>n>>s;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        int Menor = 101, Mayor = 0;
        for(int i = 0; i < n; i++){
            Menor = min(a[i], Menor);
            Mayor = max(a[i], Mayor);
        }
        if(Mayor < s) cout<<s - Menor<<"\n";
        else if(Menor > s) cout<<Mayor - s<<"\n";
        else cout<<min(Mayor - Menor + s - Menor, Mayor - s + Mayor - Menor)<<"\n";
    }
    return 0;
}