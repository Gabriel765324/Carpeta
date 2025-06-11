#include "bits/stdc++.h"
using namespace std;
string Actual;
vector< vector< vector< vector< vector<long long> > > > > PD;
long long Resolver(long long Anterior_anterior, long long Anterior, long long i, long long Libre, long long Primero){
    if(i == Actual.size()) return 1;
    if(PD[Anterior_anterior][Anterior][i][Libre][Primero] != -2) return PD[Anterior_anterior][Anterior][i][Libre][Primero];
    long long r = -0;
    if(Libre == 1){
        for(long long j = Primero; j < 10; j++){
            if(j != Anterior_anterior and j != Anterior) r += Resolver(Anterior, j, i + 1, 1, 0);
        }
    } else {
        for(long long j = Primero; j <= Actual[i] - '0'; j++){
            if(j != Anterior_anterior and j != Anterior) r += Resolver(Anterior, j, i + 1, (long long)(j != Actual[i] - '0'), 0);
        }
    }
    return PD[Anterior_anterior][Anterior][i][Libre][Primero] = r;
}
long long Resolviendo(long long n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    stringstream a;
    a<<n;
    a>>Actual;
    PD.assign(11, vector< vector< vector< vector<long long> > > >(11, vector< vector< vector<long long> > >(Actual.size(), vector< vector<long long> >(2, vector<long long>(2, -2)))));
    long long r = Resolver(10, 10, 0, 0, 1);
    for(long long i = 1; i <= Actual.size(); i++){
        r += Resolver(10, 10, i, 1, 1);
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    cin>>a>>b;
    cout<<Resolviendo(b) - Resolviendo(a - 1);
    return 0;
}