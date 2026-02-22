#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    k--;
    deque<long long> a(n);
    long long r = 0;
    for(int i = 0; i < n; i++) cin>>a[i];
    while(!a.empty() and a[0] <= 0){
        a.pop_front();
    }
    while(!a.empty() and a.back() <= 0){
        a.pop_back();
    }
    vector< pair<long long, pair<int, int> > > Borrar;
    bool Apagado = 1;
    n = a.size();
    for(int i = 0; i < n; i++){
        if(a[i] <= 0){
            if(Apagado){
                Borrar.push_back({0LL, {i, -2}});
                Apagado = 1;
            }
            Borrar.back().first += a[i];
        } else if(!Apagado){
            Borrar.back().second.second = i;
            Apagado = 1;
        }
    }
    sort(Borrar.begin(), Borrar.end());
    
    return 0;
}