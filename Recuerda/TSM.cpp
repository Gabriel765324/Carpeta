#include "bits/stdc++.h"
using namespace std;
vector<int> r;
int Buscar(int a){
    if(r[a] == a) return a;
    return r[a] = Buscar(r[a]);
}
bool Unir(int a, int b){
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        r[b] = a;
        return 1;
    }
    return 0;
}
struct Arista{
    int a, b, c;
    Arista(){}
    bool operator<(const Arista& o){
        return c < o.c;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++) r.push_back(i);
    vector<Arista> Bien, Mal, Lista(m);
    for(int i = 0; i < m; i++){
        cin>>Lista[i].a>>Lista[i].b>>Lista[i].c;
        Lista[i].a--;
        Lista[i].b--;
    }
    sort(Lista.begin(), Lista.end());
    for(auto E: Lista){
        if(Unir(E.a, E.b)){
            Bien.push_back(E);
        } else {
            Mal.push_back(E);
        }
    }
    for(int i = 0; i < n; i++) r[i] = i;
    reverse(Bien.begin(), Bien.end());
    reverse(Mal.begin(), Mal.end());
    int i = 0, j = 0;
    n = int(Bien.size()), m = int(Mal.size());
    while(1){
        if(i >= n and j >= m) return 0;
        if(i >= n){
            cout<<Mal[j].c<<" ";
            j++;
        } else if(j >= m){
            cout<<Bien[i].c<<" ";
            i++;
        } else {
            if(Buscar(Mal[j].a) == Buscar(Mal[j].b) and Mal[j].c > Bien[i].c){
                cout<<Mal[j].c<<" ";
                j++;
            } else {
                bool Nada = Unir(Bien[i].a, Bien[i].b);
                cout<<Bien[i].c<<" ";
                i++;
            }
        }
    }
    return 0;
}