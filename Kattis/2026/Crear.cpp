#include "bits/stdc++.h"
using namespace std;
mt19937 Aleatorio(chrono::steady_clock::now().time_since_epoch().count());
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    uniform_int_distribution<int> Aleatorizador(1, 22222222);
    cout<<Aleatorizador(Aleatorio);
    return 0;
}