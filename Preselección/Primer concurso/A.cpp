//No completo.
#include "bits/stdc++.h"
using namespace std;
long long Lograr, h, k;
vector<long long> d = {1};
vector< vector< vector<long long> > > Memoria;
bool Posible(long long Suma, long long Elegir, long long Posici_n){
    if(Suma == Lograr) return 1;
    if(Suma > Lograr or Elegir == h or Posici_n == d.size()) return 0;
    if(Memoria[Suma][Elegir][Posici_n] != -2) return Memoria[Suma][Elegir][Posici_n];
    bool _1 = Posible(Suma + d[Posici_n], Elegir + 1, Posici_n);
    bool _2 = Posible(Suma, Elegir, Posici_n + 1);
    return Memoria[Suma][Elegir][Posici_n] = _1 or _2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>h>>k){
        if(h == 0 and k == 0) break;
        if(h == 1 and k >= h){
            for(long long i = 1; i <= k; i++){
                if(i < 10) cout<<"  ";
                else if(i < 100) cout<<" ";
                cout<<i;
            }
            cout<<" ->";
            if(k < 10) cout<<"  ";
            else if(k < 100) cout<<" ";
            cout<<k<<"\n";
            continue;
        }
        vector<long long> Ganador;
        long long g = 0;
        for(long long Resta = 1; Resta < h; Resta++){
            d = {1};
            long long m = 0;
            while(d.size() < k){
                for(long long i = m + 1; 1; i++){
                    Lograr = i;
                    Memoria.assign(Lograr, vector< vector<long long> >(h, vector<long long>(d.size(), -2)));
                    if(!Posible(0, 0, 0)){
                        d.push_back(i - Resta - d.size() + 1);
                        m = i - 1;
                        break;
                    }
                }
            }
            for(long long i = m + 1; 1; i++){
                Lograr = i;
                Memoria.assign(Lograr, vector< vector<long long> >(h, vector<long long>(d.size(), -2)));
                if(!Posible(0, 0, 0)){
                    m = i - 1;
                    break;
                }
            }
            if(m > g){
                g = m;
                Ganador = d;
            }
        }
        for(auto e: Ganador){
            if(e < 10) cout<<"  ";
            else if(e < 100) cout<<" ";
            cout<<e;
        }
        cout<<" ->";
        if(g < 10) cout<<"  ";
        else if(g < 100) cout<<" ";
        cout<<g<<"\n";
    }
    return 0;
}