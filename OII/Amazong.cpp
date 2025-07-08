#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector< vector< pair<int, int> > > Grafo(n);
    vector<int> Ancestros(n, -2);
    vector<long long> Acumuladas(n, -2222222222222222);
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        Grafo[a].push_back({b, c});
        Grafo[b].push_back({a, c});
    }
    vector<int> Posici_n(n, 0);
    unordered_map<long long, long long> Mapa;
    long long r = 0;
    int Nodo = 0;
    Acumuladas[0] = 0;
    while(1){
        cerr<<Nodo + 1<<" ";
        if(Posici_n[Nodo] >= Grafo[Nodo].size() and Nodo == 0) break;
        if(Posici_n[Nodo] == 0){
            r += Mapa[Acumuladas[Nodo]];
            int Otro = Ancestros[Nodo];
            while(Otro != -2){
                Mapa[Acumuladas[Nodo] * 2 - Acumuladas[Otro]]++;
                Otro = Ancestros[Otro];
            }
        }
        if(Grafo[Nodo][Posici_n[Nodo]].first == Ancestros[Nodo]) Posici_n[Nodo]++;
        if(Posici_n[Nodo] >= Grafo[Nodo].size()){
            int Otro = Ancestros[Nodo];
            while(Otro != -2){
                Mapa[Acumuladas[Nodo] * 2 - Acumuladas[Otro]]--;
                Otro = Ancestros[Otro];
            }
            Nodo = Ancestros[Nodo];
            continue;
        }
        Ancestros[Grafo[Nodo][Posici_n[Nodo]].first] = Nodo;
        Acumuladas[Grafo[Nodo][Posici_n[Nodo]].first] = Acumuladas[Nodo] + Grafo[Nodo][Posici_n[Nodo]].second;
        Posici_n[Nodo]++;
        Nodo = Grafo[Nodo][Posici_n[Nodo] - 1].first;
    }
    cout<<r;
    return 0;
}