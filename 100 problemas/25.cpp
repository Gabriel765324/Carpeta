#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r = INT_MAX;
    cin>>n>>m;
    deque< pair<int, int> > a(m);
    for(int i = 0; i < m; i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(), a.end());
    multiset<int> Fin;
    for(int i = 1; i <= n; i++){
        while(!a.empty() and a[0].first == i){
            Fin.insert(a[0].second);
            a.pop_front();
        }
        while(!Fin.empty() and *Fin.begin() < i) Fin.erase(*Fin.begin());
        r = min(r, (int)Fin.size());
    }
    cout<<r;
    return 0;
}