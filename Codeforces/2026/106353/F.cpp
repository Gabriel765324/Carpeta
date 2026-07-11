#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long s = 0, d = 0;
    cin>>n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i];
        s += a[i];
        d += b[i];
    }
    for(int i = 0; i < n; i++){
        long long Recibir = s - a[i];
        d -= Recibir;
        if(d <= b[i]){
            cout<<i + 1<<"\n";
            return 0;
        }
        d += Recibir;
    }
    cout<<"impossible\n";
    return 0;
}