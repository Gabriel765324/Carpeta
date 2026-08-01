#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const long long c = 10000022;
    bitset<c> Primos;
    Primos[0] = 1;
    Primos[1] = 1;
    deque<int> Lista_de_primos;
    long long Suma = 0, m = 0;
    for(long long i = 2; i < c; i++){
        if(!Primos[i]){
            Lista_de_primos.push_back(int(i));
            for(long long j = i * i; j < c; j += i){
                Primos[j] = 1;
            }
        }
    }
    vector<long long> Suma2(c, 0LL), Suma3(c, 0LL);
    int Cantidad = 0;
    for(int i = 1; i < c; i++){
        if(Cantidad < int(Lista_de_primos.size()) and Lista_de_primos[Cantidad] < i) Cantidad++;
        Suma2[i] = (Cantidad + Suma2[i - 1]) % 104206969LL;
    }
    Lista_de_primos.pop_front();
    Cantidad = 0;
    for(int i = 1; i < c; i++){
        if(Cantidad < int(Lista_de_primos.size()) and Lista_de_primos[Cantidad] < i - 2) Cantidad++;
        Suma3[i] = (Cantidad + Suma3[i - 1]) % 104206969LL;
    }
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        if(k == 0){
            cout<<"1\n";
            continue;
        }
        if(k == 1){
            cout<<n<<"\n";
            continue;
        }
        if(k == 2){
            cout<<Suma2[n]<<"\n";
            continue;
        }
        if(k == 3){
            cout<<(Suma3[n] * 2LL) % 104206969LL<<"\n";
            continue;
        }
        cout<<"0\n";
    }
    return 0;
}