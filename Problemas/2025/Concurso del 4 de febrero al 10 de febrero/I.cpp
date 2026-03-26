#include "bits/stdc++.h"
using namespace std;
vector<bool> Criba;
bool Primo(long long n){
    if(Criba.size() == 0){
        long long m = 1000222;
        Criba.assign(m, 1);
        Criba[0] = 0;
        Criba[1] = 0;
        for(long long i = 0; i * i < m; i++){
            if(Criba[i]){
                for(long long j = i * i; j < m; j += i){
                    Criba[j] = 0;
                }
            }
        }
    }
    return Criba[n];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    while(n--){
        long long a;
        cin>>a;
        if(a != 1){
            long long i = 0, d = 1000022, m = 0;
            bool Bien = 0;
            while(1){
                long long p = (i + d) / 2;
                if(p * p <= a){
                    i = p + 1;
                    m = p;
                } else d = p - 1;
                if(i >= d + 1) break;
            }
            cout<<((m * m == a and Primo(m)) ? "YES\n" : "NO\n");
        } else cout<<"NO\n";
    }
    return 0;
}