#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector< vector<long long> > PD(2, vector<long long>(k + 1, 0));
    long long r = 0;
    while(n--){
        int p;
        long long v;
        cin>>p>>v;
        for(int i = 0; i <= k; i++){
            if(i + p <= k){
                PD[1][i + p] = max(PD[0][i] + v, PD[1][i + p]);
                r = max(r, PD[1][i + p]);
            }
            PD[1][i] = max(PD[0][i], PD[1][i]);
            r = max(r, PD[1][i]);
            PD[0][i] = 0;
        }
        swap(PD[0], PD[1]);
    }
    cout<<r;
    return 0;
}