#include "bits/stdc++.h"
using namespace std;
long long m = 1000000007;
vector< vector< pair<long long, long long> > > Grafo;
vector<long long> d, c, Menor, Mayor;
vector<bool> v;
vector<long long> Dijkstra(){
    set< pair<long long, long long> > Cola;
    Cola.insert(make_pair(-1, 0));
    d[0] = 0;
    c[0] = 1;
    Menor[0] = 0;
    Mayor[0] = 0;
    while(!Cola.empty()){
        long long Nodo = (*Cola.begin()).second;
        Cola.erase(Cola.begin());
        if(v[Nodo]) continue;
        v[Nodo] = 1;
        for(auto E: Grafo[Nodo]){
            if((d[Nodo] + E.first) < d[E.second]){
                d[E.second] = d[Nodo] + E.first;
                c[E.second] = c[Nodo] % m;
                Menor[E.second] = Menor[Nodo] + 1;
                Mayor[E.second] = Mayor[Nodo] + 1;
                v[E.second] = 0;
                Cola.insert(make_pair(d[E.second], E.second));
            } else if((d[Nodo] + E.first) == d[E.second]){
                c[E.second] = (c[E.second] % m + c[Nodo] % m) % m;
                Menor[E.second] = min(Menor[Nodo] + 1, Menor[E.second]);
                Mayor[E.second] = max(Mayor[Nodo] + 1, Mayor[E.second]);
                v[E.second] = 0;
                Cola.insert(make_pair(d[E.second], E.second));
            }
        }
    }
    return {d.back(), c.back(), Menor.back(), Mayor.back()};
}
void Cos(){
    cout<<"\n";
    for(auto E: d) cout<<E<<" ";
    cout<<"\n";
    for(auto E: c) cout<<E<<" ";
    cout<<"\n";
    for(auto E: Menor) cout<<E<<" ";
    cout<<"\n";
    for(auto E: Mayor) cout<<E<<" ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, nn;
    cin>>n>>nn;
    Grafo.assign(n, vector< pair<long long, long long> >());
    d.assign(n, 2222222222222222);
    v.assign(n, 0);
    c.assign(n, 0);
    Menor.assign(n, 2222222222222222);
    Mayor.assign(n, -2222222222222222);
    for(long long i = 0; i < nn; i++){
        long long a, b, cc;
        cin>>a>>b>>cc;
        a--;
        b--;
        Grafo[a].push_back(make_pair(cc, b));
    }
    vector<long long> a = Dijkstra();
    cout<<a[0]<<" "<<a[1] % m<<" "<<a[2]<<" "<<a[3];
    //Cos();
    return 0;
}