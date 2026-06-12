#include "bits/stdc++.h"
using namespace std;
long long p;
long long Potencia(long long b, long long e){
    if(e == 0LL) return 1LL;
    if(e == 1LL) return b % p;
    long long a = Potencia(b, e>>1LL) % p;
    a = (a % p * a % p) % p;
    a = (a % p * Potencia(b, e & 1LL) % p) % p;
    return a % p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long u, v;
    cin>>u>>v>>p;
    if(u == v){
        cout<<0;
        return 0;
    }
    queue< pair<int, bool> > Cola;
    Cola.push({u, 0});
    Cola.push({v, 1});
    map<int, int> Padres;
    deque<int> Camino;
    set< pair<int, int> > Hay;
    Padres[u] = u;
    Padres[v] = v;
    Hay.insert({u, 0});
    Hay.insert({v, 1});
    while(1){
        long long Nodo = Cola.front().first, Siguiente = (Nodo + 1LL) % p;
        int Capa = (int)Cola.front().second;
        Cola.pop();
        //cerr<<Nodo<<" Nodo\n"<<Siguiente<<" Siguiente.\n";
        if(Hay.count({Siguiente, 1 - Capa}) == 1){
            while(Nodo != u and Nodo != v){
                Camino.push_front(Nodo);
                Nodo = Padres[Nodo];
            }
            Camino.push_front(Nodo);
            Nodo = Siguiente;
            while(Nodo != v and Nodo != u){
                Camino.push_back(Nodo);
                Nodo = Padres[Nodo];
            }
            Camino.push_back(Nodo);
            break;
        } else {
            auto E = Hay.lower_bound({Siguiente, -2});
            if(E == Hay.end() or E->first != Siguiente){
                Cola.push({Siguiente, Capa});
                Padres[Siguiente] = Nodo;
                Hay.insert({Siguiente, Capa});
            }
        }
        Siguiente = (Nodo + p - 1LL) % p;
        //cerr<<"Llego0.\n"<<Siguiente<<" Siguiente.\n";
        if(Hay.count({Siguiente, 1 - Capa}) == 1){
            while(Nodo != u and Nodo != v){
                Camino.push_front(Nodo);
                Nodo = Padres[Nodo];
            }
            Camino.push_front(Nodo);
            Nodo = Siguiente;
            while(Nodo != v and Nodo != u){
                Camino.push_back(Nodo);
                Nodo = Padres[Nodo];
            }
            Camino.push_back(Nodo);
            break;
        } else {
            auto E = Hay.lower_bound({Siguiente, -2});
            if(E == Hay.end() or E->first != Siguiente){
                Cola.push({Siguiente, Capa});
                Padres[Siguiente] = Nodo;
                Hay.insert({Siguiente, Capa});
            }
        }
        Siguiente = Potencia(Nodo, p - 2LL);
        //cerr<<"Llego1.\n"<<Siguiente<<" Siguiente.\n";
        if(Hay.count({Siguiente, 1 - Capa}) == 1){
            while(Nodo != u and Nodo != v){
                Camino.push_front(Nodo);
                Nodo = Padres[Nodo];
            }
            Camino.push_front(Nodo);
            Nodo = Siguiente;
            while(Nodo != v and Nodo != u){
                Camino.push_back(Nodo);
                Nodo = Padres[Nodo];
            }
            Camino.push_back(Nodo);
            break;
        } else {
            auto E = Hay.lower_bound({Siguiente, -2});
            if(E == Hay.end() or E->first != Siguiente){
                Cola.push({Siguiente, Capa});
                Padres[Siguiente] = Nodo;
                Hay.insert({Siguiente, Capa});
            }
        }
        //cerr<<"Llego2.\n";
    }
    /*for(auto E: Camino) cerr<<E<<" ";
    cerr<<"\n";*/
    if(Camino[0] == v) reverse(Camino.begin(), Camino.end());
    /*for(auto E: Camino) cerr<<E<<" ";
    cerr<<"\n";*/
    int n = int(Camino.size()) - 1;
    cout<<n<<"\n";
    for(int i = 0; i < n; i++){
        if(Camino[i + 1] == (Camino[i] + 1LL) % p) cout<<"1 ";
        else if(Camino[i + 1] == (Camino[i] + p - 1LL) % p) cout<<"2 ";
        else cout<<"3 ";
    }
    return 0;
}