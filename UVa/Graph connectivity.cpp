#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Grafo;
vector<bool> Lista;
void DFS(long long Nodo){
    Lista[Nodo] = 1;
    for(auto E: Grafo[Nodo]){
        if(!Lista[E]) DFS(E);
    }
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("01.in", "r", stdin);
    string T;
    getline(cin, T);
    long long t;
    stringstream Conversor;
    Conversor<<T;
    Conversor>>t;
    string Nada;
    getline(cin, Nada);
    unordered_map<char, long long> Valor;
    for(long long i = 'A'; i <= 'Z'; i++){
        Valor[i] = i - 'A';
    }
    bool Primero = 1;
    long long Casos = t;
    vector<long long> r;
    while(t--){
        string Mayor, Conectar;
        getline(cin, Mayor);
        long long n = Valor[Mayor[0]] + 1;
        //cerr<<n<<"\n";
        Grafo.assign(n, {});
        Lista.assign(n, 0);
        while(getline(cin, Conectar)){
            //cerr<<Conectar<<"\n";
            if(Conectar == ""){
                //cerr<<"Roto\n";
                break;
            }
            long long a = Valor[Conectar[0]], b = Valor[Conectar[1]];
            Grafo[a].push_back(b);
            Grafo[b].push_back(a);
        }
        long long c = 0;
        for(long long i = 0; i < n; i++){
            if(!Lista[i]){
                c++;
                DFS(i);
            }
        }
        r.push_back(c);
    }
    while(r.size() > Casos) r.pop_back();
    for(long long i = 0; i < r.size(); i++){
        cout<<r[i]<<"\n";
        if(i < r.size() - 1) cout<<"\n";
    }
    return 0;
}