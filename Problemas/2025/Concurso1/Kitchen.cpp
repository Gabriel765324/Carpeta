#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, k, Tiempo = 0;
    cin>>n>>m>>k;
    vector<long long> a(n), b(m);
    for(long long i = 0; i < n; i++){
        cin>>a[i];
        Tiempo += a[i];
        if(a[i] < k){
            cout<<"Impossible";
            return -0;
        }
    }
    long long Suma = 0;
    for(long long i = 0; i < m; i++){
        cin>>b[i];
        Suma += b[i];
    }
    vector< vector<long long> > Memorizaci_n(2, vector<long long>(Suma + 1, -2222222222222222));
    Memorizaci_n[1][0] = 0;
    long long Mejor = 2222222222222222;
    /*for(auto E: Memorizaci_n[1]) cout<<E<<" ";
    cout<<"\n";*/
    for(long long i = 0; i < m; i++){
        swap(Memorizaci_n[0], Memorizaci_n[1]);
        for(long long j = 0; j < b[i]; j++){
            Memorizaci_n[1][j] = Memorizaci_n[0][j];
            //cout<<Memorizaci_n[1][j]<<" ";
        }
        for(long long j = b[i]; j <= Suma; j++){
            Memorizaci_n[1][j] = max(Memorizaci_n[0][j], Memorizaci_n[0][j - b[i]] + min(b[i], n));
            if(Memorizaci_n[1][j] >= n * k and j >= Tiempo){
                //cout<<"* ";
                Mejor = min(Mejor, j - Tiempo);
            }
            //cout<<Memorizaci_n[1][j]<<" ";
        }
        //cout<<"\n";
    }
    if(Mejor <= Suma) cout<<Mejor;
    else cout<<"Impossible";
    return 0;
}