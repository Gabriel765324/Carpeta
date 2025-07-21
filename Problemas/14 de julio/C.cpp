#include "iostream"
#include "vector"
#include "unordered_map"
#include "set"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin>>n>>x;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int Valor;
        cin>>Valor;
        if(a.size() == 20) b.push_back(Valor);
        else a.push_back(Valor);
    }
    unordered_map<int, long long> Mapa1, Mapa2;
    set<int> Hay;
    for(int i = 0; i < (1<<a.size()); i++){
        int Suma = 0;
        for(int j = 0; j < a.size(); j++){
            if(i & (1<<j)){
                Suma += a[j];
                if(Suma > x) break;
            }
        }
        if(Suma <= x){
            Mapa1[Suma]++;
            Hay.insert(Suma);
        }
    }
    for(int i = 0; i < (1<<b.size()); i++){
        int Suma = 0;
        for(int j = 0; j < b.size(); j++){
            if(i & (1<<j)){
                Suma += b[j];
                if(Suma > x) break;
            }
        }
        if(Suma <= x) Mapa2[Suma]++;
    }
    long long r = 0;
    for(auto E: Hay){
        r += Mapa1[E] * Mapa2[x - E];
        Mapa1[E] = 0;
    }
    cout<<r;
    return 0;
}