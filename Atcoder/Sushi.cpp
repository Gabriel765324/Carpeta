#include "bits/stdc++.h"
using namespace std;
vector< vector< vector<long double> > > PD;
long double t;
long double Resolver(int _1, int _2, int _3){
    //cerr<<_1<<" "<<_2<<" "<<_3<<"\n";
    if(_1 < 0 or _2 < 0 or _3 < 0) return 0;
    if(_1 + _2 + _3 == 0) return 0;
    if(PD[_1][_2][_3] >= 0) return PD[_1][_2][_3];
    long double Uno = 1, i = _1, j = _2, k = _3, Suma = i * (Resolver(_1 - 1, _2, _3) + Uno) + j * (Resolver(_1 + 1, _2 - 1, _3) + Uno) + k * (Resolver(_1, _2 + 1, _3 - 1) + Uno);
    //cerr<<i<<" "<<j<<" "<<k<<" "<<Suma<<" "<<i * (Resolver(_1 - 1, _2, _3) + Uno)<<" "<<j * (Resolver(_1 + 1, _2 - 1, _3) + Uno)<<" "<<k * (Resolver(_1, _2 + 1, _3 - 1) + Uno)<<"\n";
    return PD[_1][_2][_3] = (Suma + t - i - j - k) / (i + j + k);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    t = n;
    vector<int> a(3, 0);
    while(n--){
        int b;
        cin>>b;
        a[b - 1]++;
    }
    PD.assign(a[0] + a[1] + a[2] + 2, vector< vector<long double> >(a[1] + a[2] + 2, vector<long double>(a[2] + 2, -22)));
    cout<<setprecision(22)<<Resolver(a[0], a[1], a[2]);
    //cerr<<"\n"<<PD[1][0][0]<<" "<<PD[2][0][0]<<" "<<PD[3][0][0];
    return 0;
}