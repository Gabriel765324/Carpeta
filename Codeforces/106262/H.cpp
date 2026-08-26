#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const long long c = 10000022;
    bitset<c> Primos;
    Primos[0] = 1;
    Primos[1] = 1;
    vector<long long> Sumitas2(c, 0LL), Sumitas3(c, 0LL), Sumitas4(c, 0LL);
    vector<int> Lista_de_primos;
    long long Suma = 0, m = 0;
    for(long long i = 2; i < c; i++){
        Sumitas2[i] = (i * m - Suma) % 104206969LL;
        if(!Primos[i]){
            Suma += i;
            Suma %= 104206969LL;
            m++;
            Lista_de_primos.push_back(int(i));
            for(long long j = i * i; j < c; j += i){
                Primos[j] = 1;
            }
        }
    }
    vector<int> d;
    for(auto E: Lista_de_primos){
        if(E + 2LL < c and !Primos[E + 2LL]){
            d.push_back(E + 2LL);
        }
    }
    reverse(d.begin(), d.end());
    m = 0;
    Suma = 0;
    for(long long i = 5; i < c; i++){
        Sumitas3[i] = (2LL * (i * m - Suma)) % 104206969LL;
        if(!d.empty() and d.back() == i){
            Suma += d.back();
            Suma %= 104206969LL;
            m++;
            d.pop_back();
        }
    }
    d.clear();
    for(auto E: Lista_de_primos){
        if((long long)E + 4LL < c and !Primos[E + 2] and !Primos[E + 4]){
            d.push_back(E + 4);
        }
    }
    m = 0;
    Suma = 0;
    for(long long i = 2; i < c; i++){
        Sumitas4[i] = (i * m - Suma) % 104206969LL;
        if(m < int(d.size()) and d[m] == i){
            Suma += d[m];
            Suma %= 104206969LL;
            m++;
        }
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
            cout<<n % 104206969<<"\n";
            continue;
        }
        if(k == 2){
            cout<<Sumitas2[n]<<"\n";
            continue;
        }
        if(k == 3){
            cout<<Sumitas3[n]<<"\n";
            continue;
        }
        if(k == 4){
            cout<<Sumitas4[n]<<"\n";
            continue;
        }
        cout<<"0\n";
    }
    return 0;
}