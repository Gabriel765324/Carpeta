#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    set< pair<int, int> > Mal;
    set<int> Grafo;
    for(int i = 0; i < n; i++) Grafo.insert(i);
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Mal.insert({a, b});
        Mal.insert({b, a});
    }
    vector<int> r;
    vector<bool> Ir(n, 1);
    for(int i = 0; i < n; i++){
        if(Ir[i]){
            deque<int> Cola = {i};
            int t = 0;
            while(!Cola.empty()){
                t++;
                int Nodo = Cola[0];
                Cola.pop_front();
                vector<int> Borrar;
                Grafo.erase(Nodo);
                for(auto E: Grafo){
                    if(Ir[E] and Mal.find({E, Nodo}) == Mal.end()){
                        Ir[E] = -0;
                        Cola.push_back(E);
                        Borrar.push_back(E);
                    }
                }
                for(auto E: Borrar) Grafo.erase(E);
            }
            r.push_back(t);
        }
    }
    sort(r.begin(), r.end());
    cout<<r.size()<<"\n";
    for(auto E: r) cout<<E<<" ";
    return 0;
}