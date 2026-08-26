#include "bits/stdc++.h"
using namespace std;
struct Carta{
    long long a, b, i;
};
bool operator<(const Carta&a, const Carta& b){
    if(a.a < b.a) return 1;
    if(a.a > b.a) return 0;
    if(a.b > b.a) return 1;
    if(a.b < b.a) return 0;
    return a.i < b.i;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Carta> a(n);
    vector<bool> Bien(n, 0);
    for(int i = 0; i < n; i++){
        cin>>a[i].a>>a[i].b;
        a[i].i = i;
        a[i].b += (long long)2222222222;
    }
    sort(a.begin(), a.end());
    set< pair<long long, int> > Derechas;
    for(int i = 0; i < n; i++){
        auto E = Derechas.upper_bound(make_pair(a[i].b, -2));
        vector< pair<long long, int> > Borrar;
        while(E != Derechas.end()){
            Bien[(*E).second] = 0;
            Borrar.push_back(*E);
            E++;
        }
        for(auto e: Borrar) Derechas.erase(e);
        Derechas.insert(make_pair(a[i].b, a[i].i));
        Bien[a[i].i] = 1;
    }
    cout<<Derechas.size()<<"\n";
    for(int i = 0; i < n; i++){
        if(Bien[i]){
            cout<<i + 1<<" ";
        }
    }
    return 0;
}