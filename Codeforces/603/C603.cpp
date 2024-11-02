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
        deque<long long> r = {n};
        long long k = 1;
        while(r[0] != 0){
            long long Izquierda = k + 1;
            long long Derecha = n + 1;
            long long Mejor;
            while(1){
                long long Promedio = (Izquierda + Derecha) / 2;
                if((n / Promedio) < r[0]){
                    Derecha = Promedio - 1;
                    Mejor = Promedio;
                } else Izquierda = Promedio + 1;
                if(Izquierda >= (Derecha + 1)) break;
            }
            r.push_front(n / Mejor);
        }
        cout<<r.size()<<"\n";
        for(auto E: r) cout<<E<<" ";
        cout<<"\n";
    }
    return 0;
}