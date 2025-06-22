#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long a, b, c, d, x, y, x1, y1, x2, y2;
        cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
        x1 -= x;
        x2 -= x;
        y1 -= y;
        y2 -= y;
        long long Desplazamientox = b - a, Desplazamientoy = d - c;
        bool Bien = 1;
        if(Desplazamientox > 0) if(x2 < Desplazamientox) Bien = 0;
        if(Desplazamientox == 0) if(x2 == x1) if(a != 0) Bien = 0;
        if(Desplazamientox < 0) if(x1 > Desplazamientox) Bien = 0;
        if(Desplazamientoy > 0) if(y2 < Desplazamientoy) Bien = 0;
        if(Desplazamientoy == 0) if(y2 == y1) if(d != 0) Bien = 0;
        if(Desplazamientoy < 0) if(y1 > Desplazamientoy) Bien = 0;
        cout<<((Bien) ? "YES\n" : "NO\n");
    }
    return 0;
}