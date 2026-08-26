#include "bits/stdc++.h"
using namespace std;
vector<int> r, Mayor;
int Buscar(int a){
    if(r[a] == a) return a;
    return r[a] = Buscar(r[a]);
}
void Unir(int a, int b){
    //cerr<<a<<" "<<b<<"\n";
    a = Buscar(a);
    b = Buscar(b);
    if(a != b){
        Mayor[max(a, b)] = max(Mayor[a], Mayor[b]);
        r[min(a, b)] = max(a, b);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        r.assign(n, 0);
        Mayor.assign(n, 0);
        vector<int> a(n);
        for(int i = 1; i < n; i++) r[i] = i;
        set< pair<int, int> > Cola;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            Mayor[i] = a[i];
            for(auto E = Cola.upper_bound({a[i], i}); E != Cola.end(); ){
                //cerr<<(*E).first<<" E\n";
                Unir((*E).second, i);
                Cola.erase(E);
                E = Cola.upper_bound({a[i], i});
            }
            Cola.insert({Mayor[Buscar(i)], i});
        }
        for(int i = 0; i < n; i++) cout<<Mayor[Buscar(i)]<<" ";
        cout<<"\n";
    }
    return 0;
}