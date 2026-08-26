#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n = 2222222;
    vector<long long> Criba(n, -2);
    Criba[0] = 0;
    Criba[1] = 1;
    for(long long i = 2; i < n; i++){
        if(Criba[i] == -2){
            Criba[i] = i;
            for(long long j = i * i; j < n; j += i) Criba[j] = i;
        }
    }
    while(cin>>n){
        map<long long, long long> Descomponer;
        set<long long> Hay;
        if(n < 0){
            n *= -1;
            Descomponer[-1]++;
            Hay.insert(-1);
        }
        for(long long i = 2; i * i <= n; i++){
            if(n < 2222222){
                for(i = n; i > 1; i /= Criba[i]){
                    Hay.insert(Criba[i]);
                    Descomponer[Criba[i]]++;
                }
                n = i;
                break;
            }
            while(n % i == 0){
                Hay.insert(i);
                Descomponer[i]++;
                n /= i;
            }
        }
        if(n > 1){
            Descomponer[n]++;
            Hay.insert(n);
        }
        for(auto E: Hay){
            cout<<E;
            if(Descomponer[E] > 1) cout<<"^"<<Descomponer[E];
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}