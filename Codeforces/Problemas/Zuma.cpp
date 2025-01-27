#include "bits/stdc++.h"
using namespace std;
long long n;
vector<long long> a;
vector< vector<long long> > Memorizaci_n;
long long Resolver(long long i, long long j){
    if(i == j) return 1;
    if(i > j or i >= n or j >= n or i < 0 or j < 0) return 0;
    if(Memorizaci_n[i][j] != -2) return Memorizaci_n[i][j];
    long long Menor = min(Resolver(i + 1, j) + 1, Resolver(i, j - 1) + 1);
    if(i < n - 1 and a[i] == a[i + 1]) Menor = min(Menor, 1 + Resolver(i + 2, j));
    if(j > 0 and a[j] == a[j - 1]) Menor = min(Menor, Resolver(i, j - 2) + 1);
    for(long long k = i + 2; k <= j; k++) if(a[i] == a[k]) Menor = min(Menor, Resolver(i + 1, k - 1) + Resolver(k + 1, j));
    return Memorizaci_n[i][j] = Menor;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    a.assign(n, 0);
    Memorizaci_n.assign(n, vector<long long>(n, -2));
    for(long long i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<Resolver(0, n - 1);
    return 0;
}