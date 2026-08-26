#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, Victorias = 0;
    cin>>n;
    vector<long long> Rivales(n);
    multiset<long long> Enanos, Elfos;
    for(long long i = 0; i < n; i++) cin>>Rivales[i];
    for(long long i = 0; i < n; i++){
        long long a;
        cin>>a;
        Enanos.insert(a);
    }
    for(long long i = 0; i < n; i++){
        long long a;
        cin>>a;
        Elfos.insert(a);
    }
    while(!Elfos.empty()){
        long long Elfo = *Elfos.begin();
        Elfos.erase(Elfos.begin());
        if(Enanos.lower_bound(Elfo) == Enanos.begin()){
            auto e = Enanos.end();
            e--;
            Enanos.erase(e);
        } else {
            auto e = Enanos.lower_bound(Elfo);
            e--;
            Enanos.erase(e);
            Victorias++;
        }
    }
    cout<<Victorias;
    return 0;
}