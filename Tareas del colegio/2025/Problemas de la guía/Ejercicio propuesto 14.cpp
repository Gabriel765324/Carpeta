#include "bits/stdc++.h"
using namespace std;
mt19937 Aleatorio(2);
int main(){
    vector<int> a(10);
    for(int i = 0; i < a.size(); i++){
        uniform_int_distribution<int> Aleatorizador(1, 257876);
        a[i] = Aleatorizador(Aleatorio);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < 10; i++) cout<<a[i]<<" ";
    return 0;
}