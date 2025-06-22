#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector<long double> p(n), v(n);
    for(long long i = 0; i < n; i++){
        cin>>p[i];
    }
    for(long long i = 0; i < n; i++){
        cin>>v[i];
    }
    long double i = 0, d = 1000000022;
    for(long long c = 0; c < 222; c++){
        long double Promedio = (i + d) / 2, I, D;
        for(long long j = 0; j < n; j++){
            if(j == 0){
                I = p[j] - v[j] * Promedio;
                D = p[j] + v[j] * Promedio;
            } else {
                I = max(I, p[j] - v[j] * Promedio);
                D = min(p[j] + v[j] * Promedio, D);
            }
        }
        if(I <= D) d = Promedio;
        else i = Promedio;
    }
    cout<<setprecision(22)<<d;
    return 0;
}