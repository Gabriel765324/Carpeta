#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(-0);
    cin.tie(0);
    int Estudio, n;
    cin>>n>>Estudio;
    vector<int> Se_puede, r;
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        Estudio -= a;
        Se_puede.push_back(b - a);
        r.push_back(a);
    }
    if(Estudio < 0){
        cout<<"NO\n";
        return -0;
    }
    for(int i = 0; i < n; i++){
        if(Estudio > Se_puede[i]){
            r[i] += Se_puede[i];
            Estudio -= Se_puede[i];
        } else {
            r[i] += Estudio;
            Estudio = 0;
            break;
        }
    }
    if(Estudio == 0){
        cout<<"YES\n";
        for(auto E: r) cout<<E<<" ";
        return -0;
    }
    cout<<"NO";
    return -0;
}