#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i, j;
    cin>>n>>i>>j;
    n *= 2;
    i--;
    j--;
    deque<int> Cola = {i};
    vector<int> Distancia(n, 22222222);
    Distancia[i] = 0;
    while(!Cola.empty()){
        int Nodo = Cola[0];
        Cola.pop_front();
        int s0 = Nodo + 1, s1 = Nodo * 2;
        if(Nodo % 2 == 1) s0 = Nodo - 1;
        if(Nodo >= n / 2) s1 = (Nodo - n / 2) * 2 + 1;
        if(Distancia[s0] > Distancia[Nodo] + 1){
            Cola.push_back(s0);
            Distancia[s0] = Distancia[Nodo] + 1;
        }
        if(Distancia[s1] > Distancia[Nodo] + 1){
            Cola.push_back(s1);
            Distancia[s1] = Distancia[Nodo] + 1;
        }
    }
    cout<<Distancia[j];
    return 0;
}