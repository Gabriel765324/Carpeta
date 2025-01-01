#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, c = 672;
    cin>>n;
    vector<long long> d(c, 1);
    for(long long i = 1; i < c; i++) d[i] = (d[i - 1] * 10) % n;
    deque< vector< vector<long long> > > PD(2, vector< vector<long long> >(2, vector<long long>(n, 2222222222222222)));
    PD[0][1][0] = 0;
    for(long long i = c - 2; i > -1; i--){
        swap(PD[0], PD[1]);
        for(long long j = 0; j < n; j++){
            PD[0][0][j] = 2222222222222222;
            PD[0][1][j] = 2222222222222222;
        }
        PD[0][1][0] = 0;
        for(long long j = 0; j < n; j++){
            long long m0 = 2222222222222222, m1 = m0;
            for(long long k = 0; k < 10; k++){
                m0 = min(m0, PD[1][(long long)(k > 0)][(j + d[i] * k) % n] + k);
                m1 = min(m1, PD[1][1][(j + d[i] * k) % n] + k);
            }
            PD[0][0][j] = min(PD[0][0][j], m0);
            PD[0][1][j] = min(PD[0][1][j], m1);
        }
    }
    cout<<PD[0][0][0];
    return 0;
}