#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n), p(n);
    map<int, vector<int> > Mapa;
    int Mayor = INT_MIN, Menor = INT_MAX;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        Mayor = max(Mayor, a[i]);
        Menor = min(Menor, a[i]);
        Mapa[a[i]].push_back(i + 1);
    }
    int Suma = Mayor + Menor;
    for(int i = 0; i < n; i++){
        if(Mapa.count(Suma - a[i]) == 0){
            cout<<"-1\n";
            return 0;
        }
        if(Mapa[Suma - a[i]].empty()){
            cout<<"-1\n";
            return 0;
        }
        p[i] = Mapa[Suma - a[i]].back();
        Mapa[Suma - a[i]].pop_back();
    }
    for(auto E: p) cout<<E<<" ";
    cout<<"\n";
    return 0;
}