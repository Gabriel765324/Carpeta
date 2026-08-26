#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, a = 0;
    long long r = 0;
    cin>>n>>l;
    n--;
    if(l % 3 != 0){
        cout<<0;
        return 0;
    }
    vector<long long> Puntos(l, 0);
    Puntos[0]++;
    while(n--){
        int x;
        cin>>x;
        a = (a + x) % l;
        Puntos[a]++;
    }
    for(int i = 0; i < l / 3; i++){
        r += Puntos[i] * Puntos[i + l / 3] * Puntos[i + 2 * l / 3];
    }
    cout<<r;
    return 0;
}