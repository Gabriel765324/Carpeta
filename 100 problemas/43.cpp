#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, n, r = 0;
    cin>>a>>n;
    for(long long i = 1; i <= 1000000; i++){
        long long p = 0, d = 1, ci = i;
        vector<long long> v;
        while(ci > 0){
            v.push_back(ci % 10);
            ci /= 10;
        }
        for(int j = v.size() - 1; j > 0; j--){
            p += v[j] * d;
            d *= 10;
        }
        for(auto E: v){
            p += E * d;
            d *= 10;
        }
        if(p > n) continue;
        string na = "";
        long long op = p;
        while(op > 0){
            na += (char)(op % a + '0');
            op /= a;
        }
        bool Bien = 1;
        for(int j = 0; j < na.size() / 2; j++){
            Bien &= na[j] == na[na.size() - j - 1];
        }
        if(Bien) r += p;
        p = 0;
        Bien = 1;
        na = "";
        d = 1;
        for(int j = v.size() - 1; j > -1; j--){
            p += v[j] * d;
            d *= 10;
        }
        for(auto E: v){
            p += E * d;
            d *= 10;
        }
        if(p > n) continue;
        op = p;
        while(op > 0){
            na += (char)(op % a + '0');
            op /= a;
        }
        for(int j = 0; j < na.size() / 2; j++){
            Bien &= na[j] == na[na.size() - j - 1];
        }
        if(Bien) r += p;
    }
    cout<<r;
    return 0;
}