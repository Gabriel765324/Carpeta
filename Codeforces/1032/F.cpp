#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, s, x;
        cin>>n>>s>>x;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin>>a[i];
        long long r = 0;
        int Inicio = -2;
        for(int i = 0; i < n; i++){
            if(Inicio == -2 and a[i] <= x) Inicio = i;
            if(a[i] > x) Inicio = -2;
            if(a[i] == x){
                int Final = i;
                for(; Final < n and a[Final] <= x; Final++){}
                Final--;
                vector<long long> Extra = {0};
                long long Acumulada = 0;
                map<long long, long long> Mapa;
                for(int j = Inicio; j <= Final; j++){
                    Acumulada += a[j];
                    if(a[j] == x){
                        while(!Extra.empty()){
                            Mapa[Extra.back()]++;
                            Extra.pop_back();
                        }
                    }
                    Extra.push_back(Acumulada);
                    r += Mapa[Acumulada - s];
                }
                i = Final;
            }
        }
        cout<<r<<"\n";
    }
    return 0;
}