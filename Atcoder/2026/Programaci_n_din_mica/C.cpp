#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector< vector<long long> > PD(n + 1, vector<long long>(3, 0));
    for(int i = 0; i < n; i++){
        long long a, b, c;
        cin>>a>>b>>c;
        PD[i + 1][0] = max(PD[i][1], PD[i][2]) + a;
        PD[i + 1][1] = max(PD[i][0], PD[i][2]) + b;
        PD[i + 1][2] = max(PD[i][0], PD[i][1]) + c;
    }
    cout<<max(PD.back()[0], max(PD.back()[1], PD.back()[2]));
    return 0;
}