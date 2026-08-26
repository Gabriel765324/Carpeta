#include "bits/stdc++.h"
using namespace std;
string n;
vector< vector< vector< vector< vector<int> > > > > PD;
int Resolver(int Posici_n, int _1, int _2, int Libre, int Cero){
    if(Posici_n == n.size()) return 1;
    if(PD[Posici_n][_1][_2][Libre][Cero] != -2) return PD[Posici_n][_1][_2][Libre][Cero];
    if(Libre == 1 and Cero == 1) return PD[Posici_n][_1][_2][Libre][Cero] = Resolver(Posici_n + 1, _1, _2, Libre, Cero) * 2;
    if(Libre == 1 and Cero == 0){
        if(_1 == 0 or _2 == 0) return PD[Posici_n][_1][_2][Libre][Cero] = Resolver(Posici_n + 1, _1, _2, Libre, 1);
        else return PD[Posici_n][_1][_2][Libre][Cero] = Resolver(Posici_n + 1, _1, _2, Libre, 1) * 2;
    }
    int r = 0;
    if(Libre == 0 and Cero == 1){
        if(_1 <= n[Posici_n] - '0') r += Resolver(Posici_n + 1, _1, _2, _1 < n[Posici_n] - '0', Cero);
        if(_2 <= n[Posici_n] - '0') r += Resolver(Posici_n + 1, _1, _2, _2 < n[Posici_n] - '0', Cero);
        return PD[Posici_n][_1][_2][Libre][Cero] = r;
    }
    if(_1 <= n[Posici_n] - '0' and _1 != 0) r += Resolver(Posici_n + 1, _1, _2, _1 < n[Posici_n] - '0', 1);
    if(_2 <= n[Posici_n] - '0' and _2 != 0) r += Resolver(Posici_n + 1, _1, _2, _2 < n[Posici_n] - '0', 1);
    return PD[Posici_n][_1][_2][Libre][Cero] = r;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    stringstream a;
    a<<N;
    a>>n;
    PD.assign(n.size(), vector< vector< vector< vector<int> > > >(10, vector< vector< vector<int> > >(10, vector< vector<int> >(2, vector<int>(2, -2)))));
    int r = 0;
    cout<<n<<" ";
    for(int i = 0; i < n.size(); i++){
        for(int j = 0; j < 9; j++){
            for(int k = j + 1; k < 10; k++){
                r += Resolver(i, j, k, i != 0, 0);
            }
        }
    }
    cout<<r;
    return -0;
}