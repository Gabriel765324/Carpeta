#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, r = 0;
    cin>>n>>m>>k;
    vector< vector<int> > Pruebas(m);
    vector<bool> Resultados(m, 0);
    for(int i = 0; i < m; i++){
        int c;
        cin>>c;
        while(c--){
            int l;
            cin>>l;
            Pruebas[i].push_back(l - 1);
        }
        char b;
        cin>>b;
        if(b == 'o') Resultados[i] = 1;
    }
    for(int i = 0; i < (1<<n); i++){
        bool Bien = 1;
        for(int j = 0; j < m; j++){
            int c = 0;
            for(auto E: Pruebas[j]) if(i & (1<<E)) c++;
            if((c >= k and !Resultados[j]) or (c < k and Resultados[j])){
                Bien = 0;
                break;
            }
        }
        r += Bien;
    }
    cout<<r;
    return 0;
}