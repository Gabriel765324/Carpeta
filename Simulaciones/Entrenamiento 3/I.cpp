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
int n, m;
bool Coincide(int a, int b){
    return (a % (m * m)) == (((b / m) % m) + (b / (m * m)));
}
int main(){
    FastIO;
    cin>>n>>m;
    vector<int> v(m * m * m);
    for(int i = 0; i < m * m * m; i++){
        cin>>v[i];
        v[i]--;
    }
    vector< vector< vector<int> > > Grafo(m, vector< vector<int> >(m * m * m));
    for(int i = 0; i < m * m * m; i++){
        for(int j = 0; j < m * m * m; j++){
            if(Coincide(i, j)){
                Grafo[v[j]][i].push_back(j);
            }
        }
    }
    vector<int> Nodos, a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]--;
    }
    for(int i = 0; i < m * m * m; i++){
        if(v[i] == a[0]){
            Nodos.push_back(i);
        }
    }
    for(auto Inicio: Nodos){
        vector<int> Noditos(1, Inicio);
        //cerr<<Inicio<<"\n";
        for(int i = 1; i < n; i++){
            //cerr<<a[i]<<" ";
            vector<int> Nuevos;
            for(auto E: Noditos){
                for(auto e: Grafo[a[i]][E]){
                    Nuevos.push_back(e);
                }
            }
            sort(Nuevos.begin(), Nuevos.end());
            Noditos.clear();
            if(Nuevos.size() > 0){
            Noditos.push_back(Nuevos[0]);
                for(int j = 1; j < Nuevos.size(); j++){
                    if(Nuevos[j] != Nuevos[j - 1]){
                        Noditos.push_back(Nuevos[j]);
                    }
                }
            }
        }
        //cerr<<el;
        for(auto E: Noditos){
            for(auto e: Grafo[a[0]][E]){
                if(e == Inicio){
                    cout<<"yes";
                    return 0;
                }
            }
        }
    }
    cout<<"no";
    return 0;
}