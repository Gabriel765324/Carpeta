#include "bits/stdc++.h"
using namespace std;
struct Nodo{
    vector< pair<int, int> > Mejores;
};
Nodo operator+(const Nodo& a, const Nodo& b){
    Nodo c;
    for(auto E: a.Mejores) c.Mejores.push_back(E);
    for(auto E: b.Mejores) c.Mejores.push_back(E);
    sort(c.Mejores.rbegin(), c.Mejores.rend());
    Nodo r;
    set<int> Usados;
    for(auto E: c.Mejores){
        if(Usados.find(E.second) == Usados.end()){
            r.Mejores.push_back(E);
            Usados.insert(E.second);
            if(r.Mejores.size() == 3) break;
        }
    }
    while(r.Mejores.size() < 3) r.Mejores.push_back({-2, -2});
    return r;
}
bool operator<(const Nodo& a, const Nodo& b){
    return a.Mejores[0].first < b.Mejores[0].first;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0, k;
    cin>>k;
    Nodo a;
    vector< pair<int, int> > Extra;
    for(int i = 0; i < k; i++){
        int m;
        cin>>m;
        n += m;
        while(m--){
            int v;
            cin>>v;
            Extra.push_back({v, i + 1});
        }
    }
    sort(Extra.begin(), Extra.end());
    for(int i = 0; i < n; i++){
        if(i >= 2){
            int j = 0, k = 0;
            for(; j < 2; j++){
                for(k = j + 1; k < 3; k++){
                    if(a.Mejores[j].first != -2 and a.Mejores[k].first != -2 and Extra[i].first < a.Mejores[j].first + a.Mejores[k].first and Extra[i].second != a.Mejores[j].second and Extra[i].second != a.Mejores[k].second and a.Mejores[j].second != a.Mejores[k].second){
                        cout<<Extra[i].second<<" "<<Extra[i].first<<" "<<a.Mejores[j].second<<" "<<a.Mejores[j].first<<" "<<a.Mejores[k].second<<" "<<a.Mejores[k].first;
                        return 0;
                    }
                }
            }
        }
        Nodo A_adir;
        A_adir.Mejores.push_back(Extra[i]);
        a = a + A_adir;
    }
    cout<<"NIE";
    return 0;
}