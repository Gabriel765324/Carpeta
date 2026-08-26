#include "bits/stdc++.h"
using namespace std;
bool operator<(const vector<int>& a, const vector<int>& b){
    for(int i = 0; 1; i++){
        if(a[i] < b[i]) return 1;
        if(b[i] < a[i]) return 0;
    }
}
void Resolver(){
    string s;
    cin>>s;
    int n = int(s.size());
    vector< set< vector<int> > > a(3);
    set<int> C;
    for(int i = 0; i < n; i++){
        if(s[i] == 'C'){
            C.insert(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'I'){
            a[0].insert({i + 1});
        } else if(s[i] == 'C' and !a[0].empty()){
            vector<int> Copia = *a[0].begin();
            Copia.push_back(i + 1);
            a[0].erase(a[0].begin());
            a[1].insert(Copia);
        } else if(s[i] == 'P' and !a[1].empty()){
            vector<int> Copia = *a[1].begin();
            Copia.push_back(i + 1);
            a[1].erase(a[1].begin());
            a[2].insert(Copia);
        }
    }
    n = 0;
    vector< vector<int> > Finales;
    for(auto E: a[2]){
        Finales.push_back(E);
    }
    int m = int(Finales.size());
    for(int i = m - 1; i > -1; i--){
        int p = Finales[i].back();
        auto E = C.lower_bound(p);
        if(E == C.end()) continue;
        Finales[i].push_back(*E + 1);
        C.erase(E);
        C.erase(Finales[i][1] - 1);
        n++;
    }
    cout<<n<<"\n";
    if(n == 0) return;
    for(auto E: Finales){
        if(int(E.size()) == 4){
            for(auto e: E) cout<<e<<" ";
            cout<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}