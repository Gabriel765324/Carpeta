#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, c;
    while(cin>>c>>n){
        if(n == 0 and c == 0) return 0;
        vector<long long> a(n);
        set<long long> Usados;
        for(long long i = 0; i < n; i++){
            cin>>a[i];
            a[i] %= c;
            if(i > 0) a[i] += a[i - 1];
            a[i] %= c;
        }
        for(long long i = 0; i < n; i++){
            if(Usados.find(a[i]) != Usados.end()){
                long long j;
                for(j = 0; a[j] != a[i]; j++){}
                for(j++; j <= i; j++) cout<<j + 1<<" ";
                cout<<"\n";
                break;
            } else if(a[i] == 0){
                long long j;
                for(j = 0; j <= i; j++) cout<<j + 1<<" ";
                cout<<"\n";
                break;
            }
            Usados.insert(a[i]);
        }
    }
    return 0;
}