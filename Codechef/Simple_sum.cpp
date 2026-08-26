#include "bits/stdc++.h"
using namespace std;
const int Mayor = 10000001;
unsigned long long Funci_n[Mayor] = {};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < Mayor; i++){
        Funci_n[i] = i;
    }
    for(int i = 2; i < Mayor; i++){
        unsigned long long ulli = i;
        if(Funci_n[i] == ulli){
            for(int j = i; j < Mayor; j += i){
                Funci_n[j] -= Funci_n[j] / ulli;
            }
        }
        Funci_n[i] *= ulli;
    }
    for(int i = Mayor - 1; i > 0; i--){
        for(int j = 2 * i; j < Mayor; j += i){
            Funci_n[j] += Funci_n[i];
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<Funci_n[n]<<"\n";
    }
    return 0;
}