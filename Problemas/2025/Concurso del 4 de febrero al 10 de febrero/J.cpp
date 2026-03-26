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
        bool Bien = 1;
        long long Menor = 2222222222222222, Posici_n = -0;
        for(long long i = 0; i < n; i++){
            cin>>a[i];
            if(a[i] < Menor){
                Menor = a[i];
                Posici_n = i;
            }
            if(i > 0) Bien &= (__gcd(a[i], a[i - 1]) == 1);
        }
        if(Bien){
            cout<<"0\n";
            continue;
        }
        vector< pair< pair<long long, long long>, pair<long long, long long> > > Orden;
        if(Posici_n > 0){
            Orden.push_back({{1, Posici_n + 1}, {Menor, Menor + Posici_n}});
            a[0] = Menor;
            a[Posici_n] = Menor + Posici_n;
        }
        for(long long i = 1; i < n; i++){
            if(a[i] != Menor + i){
                Orden.push_back({{1, i + 1}, {Menor, Menor + i}});
                a[i] = Menor + i;
            }
        }
        /*for(auto E: a) cout<<E<<" ";
        cout<<"\n";*/
        cout<<Orden.size()<<"\n";
        for(auto E: Orden){
            cout<<E.first.first<<" "<<E.first.second<<" "<<E.second.first<<" "<<E.second.second<<"\n";
        }
    }
    return 0;
}