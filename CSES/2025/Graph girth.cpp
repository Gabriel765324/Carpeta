#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin>>n>>m;
    vector< vector<long long> > Grafo(n);
    for(long long i = 0; i < m; i++){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    long long Mejor = 2222222222222222;
    for(long long i = 0; i < n; i++){
        vector<long long> d(n, 2222222222222222), Padres(n, -2);
        deque<long long> Cola = {i};
        d[i] = 0;
        while(!Cola.empty()){
            long long Nodo = Cola[0];
            Cola.pop_front();
            for(auto E: Grafo[Nodo]){
                if(d[E] > (d[Nodo] + 1)){
                    Cola.push_back(E);
                    d[E] = d[Nodo] + 1;
                    Padres[E] = Nodo;
                } else {
                    if(E != Padres[Nodo]) Mejor = min(Mejor, d[Nodo] + d[E] + 1);
                }
            }
        }
        //for(auto E: d) cout<<E<<" ";
        //cout<<"\n";
    }
    if(Mejor != 2222222222222222) cout<<Mejor;
    else cout<<-1;
    return 0;
}