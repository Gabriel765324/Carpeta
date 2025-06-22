#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        bool Posible = 0;
        set<long long> Ya_obtenidos;
        while(1){
            if(Ya_obtenidos.find(n) != Ya_obtenidos.end()){
                break;
            }
            if(n >= m){
                Posible = 1;
                break;
            }
            Ya_obtenidos.insert(n);
            if(n % 2 == 0) n = n * 3 / 2;
            else n--;
        }
        cout<<((Posible == 1) ? "YES\n" : "NO\n");
    }
    return 0;
}