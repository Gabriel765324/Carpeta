#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map< vector<int>, int> Mapa;
    map<int, vector<int> > iMapa;
    vector<int> Final = {1, 2, 3, 4, 5};
    int i = 0;
    do{
        Mapa[Final] = i;
        iMapa[i] = Final;
        i++;
    } while(next_permutation(Final.begin(), Final.end()));
    vector<int> Distancias(122, 2222), Padres(122, -2);
    vector< pair<int, int> > Usado(122, {-2, -2});
    Distancias[0] = 0;
    queue<int> Cola;
    Cola.push(0);
    vector< vector<int> > Posibles = {
        {3, 0, 1, 2, 4},
        {3, 4, 0, 1, 2},
        {1, 2, 3, 0, 4},
        {0, 4, 1, 2, 3},
        {2, 3, 4, 0, 1},
        {0, 2, 3, 4, 1},
    };
    vector< pair<int, int> > Cambio_usado = {{2, 1}, {3, 1}, {1, 2}, {3, 2}, {1, 3}, {2, 3}} ;
    int Mayor____ = 0;
    while(!Cola.empty()){
        int Nodo = Cola.front();
        vector<int> Actual = iMapa[Nodo];
        Cola.pop();
        int Cambio_actual = 0;
        for(auto E: Posibles){
            vector<int> Siguiente;
            for(i = 0; i < 5; i++){
                Siguiente.push_back(Actual[E[i]]);
            }
            int ns = Mapa[Siguiente];
            if(Distancias[ns] == 2222){
                Padres[ns] = Nodo;
                Distancias[ns] = Distancias[Nodo] + 1;
                Mayor____ = max(Mayor____, Distancias[ns]);
                Cola.push(ns);
                Usado[ns] = Cambio_usado[Cambio_actual];
            }
            Cambio_actual++;
        }
    }
    int n;
    cin>>n;
    deque<int> a(n);
    for(i = 0; i < n; i++) cin>>a[i];
    vector< pair<int, int> > Cambios;
    for(i = n; i > 5; i--){
        //cerr<<i<<"\n";
        int p;
        for(int j = 0; j < n; j++){
            if(a[j] == i){
                p = j;
                break;
            }
        }
        if(p == i - 1) continue;
        int m = 2 - p;
        for(int j = 0; j < m; j++){
            Cambios.push_back({1, 2});
            int v = a[3];
            a.erase(a.begin() + 3);
            a.push_front(v);
        }
        p = max(2, p);
        Cambios.push_back({p - 1, i - 2});
        vector<int> Valores = {a[p - 2], a[p - 1], a[p]};
        a.erase(a.begin() + p - 2);
        a.erase(a.begin() + p - 2);
        a.erase(a.begin() + p - 2);
        //int Diferencia = i - 1 - p;
        a.insert(a.begin() + i - 3, Valores[0]);
        a.insert(a.begin() + i - 2, Valores[1]);
        a.insert(a.begin() + i - 1, Valores[2]);
        /*for(auto E: a) cerr<<E<<" ";
        cerr<<"\n";*/
    }
    Final = {a[0], a[1], a[2], a[3], a[4]};
    int Estado = Mapa[Final];
    while(1){
        /*for(auto E: iMapa[Estado]) cerr<<E<<" ";
        cerr<<"\n";*/
        if(Estado == 0) break;
        Cambios.push_back(Usado[Estado]);
        Estado = Padres[Estado];
        if(Estado == 0) break;
    }
    cout<<int(Cambios.size())<<"\n";
    for(auto E: Cambios){
        cout<<E.first<<" "<<E.second<<"\n";
    }
    return 0;
}