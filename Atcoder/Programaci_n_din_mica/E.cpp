#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> PD(222222, -2);
    PD[0] = 0LL;
    while(n--){
        long long p;
        int v;
        cin>>p>>v;
        for(int i = 222221 - v; i > -1; i--){
            if(PD[i] != -2){
                PD[i + v] = min(PD[i + v], PD[i] + p);
                if(PD[i + v] == -2LL) PD[i + v] = PD[i] + p;
            }
        }
    }
    for(int i = 222221; i > -1; i--){
        if(PD[i] != -2LL and PD[i] <= k){
            cout<<i;
            return 0;
        }
    }
    return 0;
}