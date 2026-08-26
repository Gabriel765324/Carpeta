#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bitset<222222> Ganador;
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    Ganador[0] = 0;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i - a[j] >= 0 and Ganador[i - a[j]] == 0){
                Ganador[i] = 1;
                break;
            }
        }
    }
    cout<<(Ganador[k] ? "First" : "Second");
    return 0;
}