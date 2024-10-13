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
        bool Igual = 1;
        for(long long i = 0; i < n; i++){
            cin>>a[i];
            if(a[i] != a[0]) Igual = 0;
        }
        if(Igual) cout<<"0\n";
        else {
            vector< vector<long long> > Posiciones(n);
            for(long long i = 0; i < n; i++){
                Posiciones[a[i] - 1].push_back(i);
            }
            long long Menor = 2222222222222222;
            for(long long i = 0; i < n; i++){
                long long m = Posiciones[i].size();
                if(m == 1){
                    if(Posiciones[i][0] > 0 and Posiciones[i][0] < (n - 1)) Menor = min(Menor, 2LL);
                    else Menor = min(Menor, 1LL);
                } else if(m != 0){
                    long long Posible = 0;
                    for(long long j = 0; j < (m - 1); j++){
                        long long k = Posiciones[i][j], l = Posiciones[i][j + 1];
                        if((l - k) >= 2LL) Posible++;
                    }
                    if(Posiciones[i][0] > 0) Posible++;
                    if(Posiciones[i].back() < (n - 1)) Posible++;
                    Menor = min(Menor, Posible);
                }
            }
            cout<<Menor<<"\n";
        }
    }
    return 0;
}