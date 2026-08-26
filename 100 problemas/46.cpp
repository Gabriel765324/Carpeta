#include "bits/stdc++.h"
using namespace std;
int n;
string s;
vector<bool> Visitados;
void DFS(int Nodo){
    Visitados[Nodo] = 1;
    for(int i = 0; i < n; i++){
        //cerr<<Nodo<<" "<<Nodo + (1<<i)<<" "<<(Nodo & (1<<i))<<" "<<s[Nodo + (1<<i)]<<" "<<Visitados[Nodo + (1<<i)]<<"\n";
        if(((Nodo & (1<<i)) == 0) and (s[Nodo + (1<<i)] == '0') and !Visitados[Nodo + (1<<i)]){
            DFS(Nodo + (1<<i));
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>s;
        s = "0" + s;
        Visitados.assign(s.size(), 0);
        DFS(0);
        cout<<(Visitados.back() ? "Yes" : "No")<<"\n";
    }
    return 0;
}