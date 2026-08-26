#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
void Resolver(){
    int n, k, r = 0;
    cin>>n>>k;
    ordered_set<int> x;
    vector<int> Valores(3 * n + 22, 0), Respuestas(3 * n + 22, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        a--;
        Valores[a]++;
    }
    n = int(Valores.size());
    vector<int> Propagar;
    for(int i = 0; i < n; i++){
        if(Valores[i] != 1) x.insert(i);
        if(Valores[i] > 1) Propagar.push_back(i);
    }
    bool Seguir = 1;
    while(Seguir){
        Seguir = 0;
        vector<int> Quedar;
        n = int(Propagar.size());
        for(int i = 0; i < n; i++){
            int p = Propagar[i];
            if(Valores[p] <= 1){
                x.erase(p);
                continue;
            }
            if(Valores[p] <= k and Respuestas[p] >= r){
                Quedar.push_back(p);
                continue;
            }
            Seguir = 1;
            int Siguiente = *x.find_by_order(x.order_of_key(p) + 1);
            Respuestas[Siguiente] = Respuestas[p] + Siguiente - p;
            r = max(Respuestas[Siguiente], r);
            Valores[Siguiente] += Valores[p] - 1;
            Valores[p] = 1;
            x.erase(p);
            if(i + 1 >= n or Propagar[i + 1] != Siguiente){
                Propagar[i] = Siguiente;
                i--;
            }
        }
        swap(Quedar, Propagar);
    }
    cout<<r<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}
/*
1
16 2
1 1 1 1 1 3 3 3 6 6 6 6 6 6 6 6

1
16 4
6 3 7 5 13 6 7 6 3 5 13 7 6 4 3 6

1
5 1
1 3 2 1 4
*/