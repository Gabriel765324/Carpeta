#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, Menor = INT_MAX;
    cin>>n>>m;
    vector<int> a(n), Contador(n + 22, 0);
    set<int> No_hay;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        No_hay.insert(i);
    }
    No_hay.insert(n);
    for(int i = 0; i < m; i++){
        No_hay.erase(a[i]);
        Contador[a[i]]++;
    }
    Menor = min(Menor, *No_hay.lower_bound(0));
    for(int i = m; i < n; i++){
        No_hay.erase(a[i]);
        Contador[a[i]]++;
        Contador[a[i - m]]--;
        if(Contador[a[i - m]] == 0) No_hay.insert(a[i - m]);
        Menor = min(Menor, *No_hay.lower_bound(0));
    }
    cout<<Menor<<"\n";
    return 0;
}