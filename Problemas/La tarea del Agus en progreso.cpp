#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, c = 672;
    cin>>n;
    vector<long long> d(c, 1);
    for(long long i = 1; i < c; i++) d[i] = (d[i - 1] * 10) % n;
    deque< vector<long long> > PD(2, vector<long long>(n, 2222222222222222));
    PD[0][0] = 0;
    for(long long i = c - 2; i > -1; i--){
        swap(PD[0], PD[1]);
        for(long long j = 0; j < n; j++){
            long long m = 2222222222222222;
            PD[0][j] = 2222222222222222;
            for(long long k = 0; k < 10; k++){
                long long So = 0;
                if(k == 0 and PD[1][(j + d[i] * k) % n] == 0) So = 2222222222222222;
                m = min(m, PD[1][(j + d[i] * k) % n] + k + So);
            }
            PD[0][j] = min(PD[0][j], m);
        }
    }
    cout<<PD[0][0];
    return 0;
}