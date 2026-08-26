#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    set<long long> s;
    for(long long i = 1; i < 10; i++){
        for(long long Aumento = -9; Aumento < 10; Aumento++){
            long long Valor = i, Anterior = i;
            s.insert(Valor);
            for(int d = 2; d < 19; d++){
                Anterior += Aumento;
                if(Anterior < 0 or Anterior > 9) break;
                Valor *= 10;
                Valor += Anterior;
                s.insert(Valor);
            }
        }
    }
    //for(auto E: s) cerr<<E<<" ";
    cout<<*s.lower_bound(n);
    return 0;
}