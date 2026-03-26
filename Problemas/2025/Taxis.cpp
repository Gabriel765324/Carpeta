#include "bits/stdc++.h"
using namespace std;
struct Taxi{
    long long Siempre, Distancia;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Taxi> a(n);
    for(int i = 0; i < n; i++) cin>>a[i].Siempre>>a[i].Distancia;
    vector<int> Posiciones;
    for(int i = 0; i < n; i++){
        cin>>Posiciones[i];
        Posiciones[i]--;
    }
    int q;
    cin>>q;
    while(q--){
        int _1, _2;
        cin>>_1>>_2;
        swap(Posiciones[_1 - 1], Posiciones[_2 - 1]);
        
    }
    return 0;
}