#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        long long x, o, t = 0, Anterior = 0;
        cin>>x>>o;
        while(1){
            t++;
            if(x + Anterior >= o){
                cout<<t<<"\n";
                break;
            }
            long long Nuevo = x + Anterior;
            Anterior = x;
            x = Nuevo;
        }
    }
    return 0;
}