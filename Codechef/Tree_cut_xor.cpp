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
vector< vi > Grafo;
void Solucionar(int Nodo, int Padre){
    if(int(Grafo[Nodo].size()) == 1 and Nodo != 0){
        cout<<Nodo + 1<<" "<<Padre + 1<<" "<<Nodo + 1<<el;
        return;
    }
    for(auto E: Grafo[Nodo]){
        if(E == Padre) continue;
        Solucionar(E, Nodo);
    }
    if(Nodo != 0) cout<<Nodo + 1<<" "<<Padre + 1<<" "<<Nodo + 1<<el;
}
bitset<222222> Visitados;
int c;
void Solucionar2(int Nodo, int Padre){
    if(int(Grafo[Nodo].size()) == 1 and Nodo != 0 and c > 4){
        //cerr<<"Corte.\n";
        cout<<Nodo + 1<<" "<<Padre + 1<<" "<<Nodo + 1<<el;
        c--;
        Visitados[Nodo] = 1;
        return;
    }
    for(auto E: Grafo[Nodo]){
        if(E == Padre) continue;
        Solucionar2(E, Nodo);
    }
    if(Nodo != 0 and c > 4){
        //cerr<<"Corte.\n";
        cout<<Nodo + 1<<" "<<Padre + 1<<" "<<Nodo + 1<<el;
        Visitados[Nodo] = 1;
        c--;
    }
}
void Resolver(){
    int n;
    cin>>n;
    c = n;
    if(n != 2) cout<<"0\n";
    else cout<<"1\n";
    Grafo.assign(n, {});
    forn(i, n - 1){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        Grafo[a].pb(b);
        Grafo[b].pb(a);
    }
    if(bool(n & 1) or n == 2){
        Solucionar(0, 0);
        return;
    }
    Solucionar2(0, 0);
    vi Finales;
    forn(i, n){
        //cerr<<Visitados[i];
        if(!Visitados[i]) Finales.push_back(i);
    }
    //cerr<<"\n";
    /*for(auto E: Finales) cerr<<E<<" ";
    cerr<<el;*/
    map<int, int> Mapa, Mapa__1;
    forn(i, 4){
        Mapa[Finales[i]] = i;
        Mapa__1[i] = Finales[i] + 1;
    }
    vector< vi > Grafo2(4);
    forn(i, 4){
        for(auto E: Grafo[Mapa__1[i] - 1]){
            if(!Visitados[E]){
                Grafo2[i].push_back(Mapa[E]);
            }
        }
    }
    /*cerr<<"--\n";
    for(auto E: Grafo2){
        for(auto e: E){
            cerr<<e<<" ";
        }
        cerr<<el;
    }
    cerr<<"--\n";*/
    forn(i, n) Visitados[i] = 0;
    int Malo;
    forn(i, 4){
        if(int(Grafo2[i].size()) == 1){
            Malo = i;
            cout<<Mapa__1[Grafo2[i][0]]<<" "<<Mapa__1[i]<<" "<<Mapa__1[Grafo2[i][0]]<<"\n";
            break;
        }
    }
    forn(i, 4){
        if(int(Grafo2[i].size()) >= 2){
            vi Usar;
            for(auto E: Grafo2[i]){
                if(E != Malo){
                    Usar.pb(E);
                }
            }
            if(int(Usar.size()) < 2) continue;
            cout<<Mapa__1[Usar[0]]<<" "<<Mapa__1[i]<<" "<<Mapa__1[i]<<"\n";
            cout<<Mapa__1[Usar[1]]<<" "<<Mapa__1[i]<<" "<<Mapa__1[i]<<"\n";
            break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}