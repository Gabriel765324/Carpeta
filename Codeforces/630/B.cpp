#include "bits/stdc++.h"
using namespace std;
bool Primo(long long a){
    for(long long i = 2; i * i <= a; i++) if(a % i == 0) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    vector<long long> Primos;
    for(long long i = 2; Primos.size() <= 11; i++){
        if(Primo(i)) Primos.push_back(i);
    }
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n), c(n);
        for(long long i = 0; i < n; i++) cin>>a[i];
        long long Colores = 0;
        vector<bool> Pintados(n, 0);
        /*a.clear();
        c.clear();
        Pintados.clear();
        for(long long i = 4; i <= 1000; i++) if(!Primo(i)) a.push_back(i);
        n = a.size();
        c.assign(n, 0);
        Pintados.assign(n, 0);*/
        bool Mal = 1;
        for(long long i = 0; Mal; i++){
            long long p = Primos[i];
            Mal = 0;
            Colores++;
            for(long long j = 0; j < n; j++){
                if(!Pintados[j] and a[j] % p == 0){
                    Mal = 1;
                    c[j] = Colores;
                    Pintados[j] = 1;
                }
                if(!Pintados[j]) Mal = 1;
            }
        }
        unordered_set<long long> Diferentes;
        for(long long i = 0; i < n; i++) Diferentes.insert(c[i]);
        Colores = Diferentes.size();
        unordered_map<long long, long long> Mapa;
        long long i = 1;
        for(auto E: Diferentes){
            Mapa[E] = i;
            i++;
        }
        /*for(long long i = 0; i < n - 1; i++){
            for(long long j = i + 1; j < n; j++){
                if(Mapa[c[i]] == Mapa[c[j]] and __gcd(a[i], a[j]) == 1) Mal = 1;
            }
        }
        if(Mal) cout<<"Mal.\n";*/
        cout<<Colores<<"\n";
        for(auto E: c) cout<<Mapa[E]<<" ";
        cout<<"\n";
    }
    return 0;
}