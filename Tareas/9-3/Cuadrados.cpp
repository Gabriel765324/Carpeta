#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<unsigned long long> Cuadrados = {0};
    for(unsigned long long i = 1; 1; i++){
        if(i % 22 == 0) cerr<<i<<"\n";
        unsigned long long ci = i;
        i *= i;
        Cuadrados.push_back(i);
        if(i % 3 == 1){
            vector<int> Bien(i + 1, -2);
            Bien[0] = 0;
            //cerr<<i<<"\n";
            for(int j = 0; j <= i and (Bien.back() == -2 or Bien.back() > 3); j++){
                for(int k = 0; k + Cuadrados[j] <= i; k++){
                    if(k + Cuadrados[j] <= i and Bien[k] != -2){
                        if(Bien[k + Cuadrados[j]] == -2) Bien[k + Cuadrados[j]] = Bien[k] + 1;
                        else Bien[k + Cuadrados[j]] = min(Bien[k] + 1, Bien[k + Cuadrados[j]]);
                    }
                }
                /*for(auto E: Bien) cerr<<E<<" ";
                cerr<<"\n";*/
            }
            if(Bien.back() == -2 or Bien.back() > 3){
                cout<<i<<" Encontrado.\n";
                return 0;
            }
        }
        i = ci;
    }
    return 0;
}