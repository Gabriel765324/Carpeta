#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n;
    vi aa(n);
    forn(i, n) cin>>aa[i];
    ordered_set<int> Ayuda;
    vi Prefijos(n), Sufijos(n);
    forn(i, n){
        Prefijos[i] = ((int)Ayuda.size() - (int)Ayuda.order_of_key(aa[i])) & 1;
        Ayuda.insert(aa[i]);
        if(i > 0) Prefijos[i] ^= Prefijos[i - 1];
    }
    Ayuda.clear();
    for(int i = n - 1; i > -1; i--){
        Sufijos[i] = ((int)Ayuda.size() - (int)Ayuda.order_of_key(aa[i])) & 1;
        Ayuda.insert(aa[i]);
        if(i + 1 < n) Sufijos[i] ^= Sufijos[i + 1];
    }
    for(auto E: Prefijos) cerr<<E;
    cout<<el;
    for(auto E: Sufijos) cerr<<E;
    cerr<<el<<el;
    cin>>m;
    while(m--){
        int a, b, p = 0;
        cin>>a>>b;
        a--;
        forsn(i, a, b){
            if(a - 1 >= 0) Prefijos[i] ^= Prefijos[a - 1];
            if(b < n) Sufijos[i] ^= Sufijos[b];
        }
        forsn(i, a, b){
            swap(Prefijos[i], Sufijos[b - i + a - 1]);
            if(a - 1 >= 0) Prefijos[i] ^= Prefijos[a - 1];
            if(b < n) Sufijos[b - i + a - 1] ^= Sufijos[b];
        }
        forn(i, n){
            p ^= Prefijos[i];
        }
        reverse(aa.begin() + a, aa.begin() + b);
        for(auto E: aa) cerr<<E<<" ";
        cerr<<el;
        for(auto E: Prefijos) cerr<<E;
        cout<<el;
        for(auto E: Sufijos) cerr<<E;
        cerr<<el<<el;
        cout<<(p ? "odd\n" : "even\n");
    }
    return 0;
}