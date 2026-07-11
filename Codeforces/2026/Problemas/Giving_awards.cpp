#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
bitset<30000> Visitados;
vector< bitset<30000> > Grafo;
vector< ii > Orden;
int t = 0, r = 1, n;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    forn(i, n){
        if(Visitados[i]) continue;
        if(Grafo[Nodo][i]) continue;
        DFS(i);
    }
    Orden[Nodo] = {t, Nodo};
    t++;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m;
    Grafo.assign(n, {});
    Orden.assign(n, {});
    forn(i, m){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[b][a] = 1;
    }
    forn(i, n) if(!Visitados[i]) DFS(i);
    sort(all(Orden));
    for(auto E: Orden) cout<<E.second + 1<<" ";
    return 0;
}