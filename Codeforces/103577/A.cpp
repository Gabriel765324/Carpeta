#include "bits/stdc++.h"
#define vi vector<int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp make_pair
#define ii pair<int, int>
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
struct Arista{
    int v, w;
    Arista(int V, int W){
        v = V;
        w = W;
    }
};
struct Par{
    int d, n;
    Par(int D, int N){
        d = D;
        n = N;
    }
    bool operator<(const Par& o) const{
        return mp(d, n) < mp(o.d, o.n);
    }
    bool operator>(const Par& o) const{
        return mp(d, n) > mp(o.d, o.n);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    vector< vector<Arista> > Grafo(n);
    while(m--){
        int a, b, w;
        cin>>a>>b>>w;
        a--;
        b--;
        Grafo[a].pb(Arista(b, w));
    }
    bitset<500> Terminados;
    while(q--){
        int a, b, x;
        cin>>a>>b>>x;
        a--;
        b--;
        vi Distancias(n, INT_MAX);
        Distancias[a] = x;
        priority_queue<Par, vector<Par>, greater<Par> > Cola;
        Cola.push(Par(x, a));
        while(!Cola.empty()){
            int Nodo = Cola.top().n, Distancia = Cola.top().d;
            Cola.pop();
            if(Terminados[Nodo]) continue;
            Terminados[Nodo] = 1;
            for(auto E: Grafo[Nodo]){
                if(Distancias[E.v] > Distancia + E.w + x){
                    Distancias[E.v] = Distancia + E.w + x;
                    Cola.push(Par(Distancia + E.w + x, E.v));
                }
            }
        }
        if(Distancias[b] == INT_MAX) cout<<"-1\n";
        else cout<<Distancias[b]<<el;
        Terminados &= ~Terminados;
    }
    return 0;
}