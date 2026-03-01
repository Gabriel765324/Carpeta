#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p, x = -2, y = -2;
    cin>>n>>p;
    if(n % 2 == 0 and n != 2){
        cout<<"N";
        return 0;
    }
    int t1 = p;
    vector< vector<int> > Grafo(n);
    set< pair<int, int> > Aristas;
    deque<int> a, b;
    while(p--){
        int aa;
        cin>>aa;
        a.push_back(aa);
    }
    cin>>p;
    int t2 = p;
    if(t1 + t2 > (n * (n - 1) / 2 + 1)){
        cout<<"N";
        return 0;
    }
    while(p--){
        int aa;
        cin>>aa;
        b.push_back(aa);
    }
    if(n == 2){
        while(!b.empty()){
            a.push_front(b.back());
            b.pop_back();
        }
        if(a.size() > 2){
            cout<<"N";
            return 0;
        }
        set< deque<int> > Posibles;
        Posibles.insert({});
        Posibles.insert({1});
        Posibles.insert({2});
        Posibles.insert({1, 2});
        Posibles.insert({2, 1});
        if(Posibles.count(a) == 1 or a.empty()) cout<<"Y";
        else cout<<"N";
        return 0;
    }
    if(!a.empty() and !b.empty() and a[0] != b.back()){
        cout<<"N";
        return 0;
    }
    for(int i = b.size() - 2 + (a.empty() ? 1 : 0); i > -1; i--) a.push_front(b[i]);
    for(int i = 1; i < a.size(); i++){
        int _0 = a[i] - 1, _1 = a[i - 1] - 1;
        if(_0 == _1){
            cout<<"N";
            return 0;
        }
        if(_0 > _1) swap(_0, _1);
        if(Aristas.count({_0, _1}) == 1){
            cout<<"N";
            return 0;
        }
        Aristas.insert({_0, _1});
    }
    if(a.size() == 0){
        cout<<((n % 2 == 1 or n == 2) ? "Y" : "N");
        return 0;
    }
    if(Aristas.size() == n * (n - 1) / 2){
        cout<<"Y";
        return 0;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(Aristas.count({i, j}) == 1) continue;
            Grafo[i].push_back(j);
            Grafo[j].push_back(i);
        }
    }
    int Inicio = a[0] - 1, Final = a.back() - 1, Impar = 0, Yo_impar = 0;
    for(int i = 0; i < n; i++){
        if(Grafo[i].size() % 2 == 1){
            //cerr<<i<<" "<<Inicio<<" "<<Final<<"\n";
            Impar++;
            if(i == Inicio or i == Final) Yo_impar++;
        }
    }
    if(Impar != 2 and Impar != 0){
        cout<<"N";
        return 0;
    }
    if(Inicio == Final and Impar != 0){
        cout<<"N";
        return 0;
    }
    if(Inicio != Final and Impar != 2){
        cout<<"N";
        return 0;
    }
    //cerr<<Yo_impar<<"\n";
    if(Inicio != Final and Yo_impar != 2){
        cout<<"N";
        return 0;
    }
    //cerr<<"Llego.\n";
    bitset<2222> Visitados;
    deque<int> Cola = {Inicio};
    Visitados[Inicio] = 1;
    while(!Cola.empty()){
        int Nodo = Cola[0];
        Cola.pop_front();
        for(auto E: Grafo[Nodo]){
            if(Visitados[E]) continue;
            Cola.push_back(E);
            Visitados[E] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        if(!Visitados[i] and Grafo[i].size() > 0){
            cout<<"N";
            return 0;
        }
    }
    cout<<"Y";
    return 0;
}