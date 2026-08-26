#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        if(n == 1){
            cout<<k<<"\n";
            continue;
        }
        int Mejor = 1, Siguiente = 3;
        while(Siguiente < k){
            Mejor = Siguiente;
            Siguiente *= 2;
            Siguiente++;
        }
        cout<<Mejor<<" "<<k - Mejor<<" ";
        for(int i = 2; i < n; i++) cout<<"0 ";
        cout<<"\n";
    }
    return 0;
}