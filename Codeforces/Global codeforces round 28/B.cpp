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
        vector<long long> Respuesta(n, -2);
        long long Pendientes = 1;
        for(long long i = k - 1; i < n; i += k){
            Respuesta[i] = Pendientes;
            Pendientes++;
        }
        Pendientes = n;
        for(long long i = 0; i < n; i++){
            if(Respuesta[i] == -2){
                Respuesta[i] = Pendientes;
                Pendientes--;
            }
        }
        for(auto E: Respuesta) cout<<E<<" ";
        cout<<"\n";
    }
    return 0;
}