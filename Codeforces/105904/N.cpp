#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const long long Mayor = 1000022;
    vector<int> Divisores(Mayor, 0);
    for(long long i = 2; i < Mayor; i++){
        if(Divisores[i] != 0) continue;
        Divisores[i] = i;
        for(long long j = i * i; j < Mayor; j += i){
            Divisores[j] = i;
        }
    }
    int n;
    cin>>n;
    vector<int> Contador(Mayor, 0);
    bitset<Mayor> Encendidos;
    set< pair<int, int> > Valores;
    while(n--){
        int a, ca;
        cin>>a;
        ca = a;
        Encendidos[a] = !Encendidos[a];
        while(a > 1){
            int p = Divisores[a];
            //cerr<<p<<" ";
            Valores.erase(make_pair(-Contador[p], p));
            Contador[p] += Encendidos[ca] ? 1 : -1;
            Valores.insert(make_pair(-Contador[p], p));
            while(a % p == 0){
                a /= p;
            }
        }
        /*for(auto E: Valores) cerr<<-E.first<<" "<<E.second<<"\n";
        cerr<<"\n";*/
        if(int(Valores.size()) == 0) cout<<0<<"\n";
        else cout<<-Valores.begin()->first<<"\n";
    }
    return 0;
}