#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        deque<long long> a(n), b(n), ab;
        for(long long i = 0; i < n; i++) cin>>a[i];
        for(long long i = 0; i < n; i++) cin>>b[i];
        for(long long i = 0; i < n; i++){
            ab.push_back(a[i]);
            ab.push_back(b[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        /*for(auto E: a) cout<<E<<" ";
        cout<<"\n";
        for(auto E: b) cout<<E<<" ";
        cout<<"\n";*/
        a.push_front(-2222222222222222);
        b.push_front(-2222222222222222);
        a.push_back(2222222222222222);
        b.push_back(2222222222222222);
        long long Ganancia = 0;
        for(long long i = 0; i < 2 * n; i++){
            long long Precio = ab[i], No_comprar = 0, Comprar_bien = 0, Comprar_mal = 0;
            Comprar_bien = lower_bound(a.begin(), a.end(), Precio) - a.begin() - 1;
            Comprar_bien = n - Comprar_bien;
            No_comprar = lower_bound(b.begin(), b.end(), Precio) - b.begin() - 1;
            Comprar_mal = n - No_comprar - Comprar_bien;
            //cout<<Comprar_bien<<" "<<Comprar_mal<<" "<<No_comprar<<" "<<Precio<<"\n";
            if(Comprar_mal <= k) Ganancia = max(Ganancia, Precio * (Comprar_bien + Comprar_mal));
        }
        cout<<Ganancia<<"\n";
    }
    return 0;
}