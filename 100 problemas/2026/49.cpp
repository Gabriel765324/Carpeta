#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin>>n>>k>>x;
    x--;
    vector<string> s(n), Posibles;
    vector<int> p(k, 0);
    for(int i = 0; i < n; i++){
        cin>>s[i];
    }
    bool Seguir = 1;
    while(Seguir){
        string Nuevo = "";
        for(auto E: p) Nuevo += s[E];
        Posibles.push_back(Nuevo);
        for(int i = k - 1; i > -1; i--){
            p[i]++;
            if(p[i] == n){
                p[i] = 0;
                if(i == 0){
                    Seguir = -0;
                    break;
                }
            } else {
                break;
            }
        }
    }
    sort(Posibles.begin(), Posibles.end());
    cout<<Posibles[x];
    return 0;
}