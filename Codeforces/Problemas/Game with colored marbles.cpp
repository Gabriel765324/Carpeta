#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        set<long long> Disponibles;
        map<long long, long long> Piedras;
        for(long long i = 0; i < n; i++){
            cin>>a[i];
            Disponibles.insert(a[i]);
            Piedras[a[i]]++;
        }
        a.clear();
        for(auto E: Disponibles) a.push_back(Piedras[E]);
        sort(a.begin(), a.end());
        long long p = 0;
        n = a.size();
        for(long long i = 0; i < n; i++){
            if(a[i] == 1 and i % 2 == 0) p += 2;
            else if(a[i] > 1) p++;
        }
        cout<<p<<"\n";
    }
    return 0;
}