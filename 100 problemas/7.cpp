#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector< vector<int> > Poseedores(n + 22);
    vector< set<int> > Contenidos(m);
    for(int i = 0; i < m; i++){
        int k;
        cin>>k;
        while(k--){
            int Ingrediente;
            cin>>Ingrediente;
            Contenidos[i].insert(Ingrediente);
            Poseedores[Ingrediente].push_back(i);
        }
    }
    int Comer = 0;
    while(n--){
        int Sirve;
        cin>>Sirve;
        for(auto E: Poseedores[Sirve]){
            Contenidos[E].erase(Sirve);
            if(Contenidos[E].size() == 0) Comer++;
        }
        cout<<Comer<<"\n";
    }
    return 0;
}