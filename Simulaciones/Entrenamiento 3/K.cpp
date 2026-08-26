#include <bits/stdc++.h>
#define FastIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i< int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
int p;
vector< vector<int> > Grafo;
vector<int> Partir;
long long M(long long a, long long b){
    return (a % p * b % p) % p;
}
bool DFS(int Nodo, int Color){
    Partir[Nodo] = Color;
    bool Bien = 1;
    for(auto E: Grafo[Nodo]){
        if(Partir[E] == 0){
            Bien &= DFS(E, Color == 1 ? 2 : 1);
        } else if(Partir[E] == Color){
            Bien = 0;
        }
        if(!Bien) return Bien;
    }
    return Bien;
}
int main(){
    FastIO;
    int n, m;
    cin>>n>>m>>p;
    Grafo.assign(n, {});
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].push_back(b);
        Grafo[b].push_back(a);
    }
    Partir.assign(n, 0);
    long long r = 1;
    bool Primero = 0;
    for(int i = 0; i < n; i++){
        if(Partir[i] == 0){
            bool Posible = DFS(i, 1);
            if(!Posible){
                cout<<"impossible";
                return 0;
            }
            if(Primero) r = M(2LL, r);
            Primero = 1;
        }
    }
    cout<<(r + 1LL) % p;
    return 0;
}