#include "bits/stdc++.h"
using namespace std;
int n, a, b, c, s = 0, p;
vector< vector< vector<short int> > > PD;
vector<int> x;
bool Resolver(int i, int ac, int bc){
    if(ac < 0 or bc < 0) return 0;
    if(i == n) return s - (a * p - ac) - (b * p - bc) <= c * p;
    if(PD[i][ac][bc] != -2) return PD[i][ac][bc];
    return PD[i][ac][bc] = Resolver(i + 1, ac - x[i], bc) or Resolver(i + 1, ac, bc - x[i]) or Resolver(i + 1, ac, bc);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>a>>b>>c;
    int Menor = 1, Mayor = 170, m = 170;
    x.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin>>x[i];
        s += x[i];
    }
    while(Menor < Mayor + 1){
        p = (Menor + Mayor) / 2;
        PD.assign(n, vector< vector<short int> >(a * p + 1, vector<short int>(b * p + 1, -2)));
        if(Resolver(0, a * p, b * p)){
            m = p;
            Mayor = p - 1;
        } else {
            Menor = p + 1;
        }
    }
    cout<<m<<"\n";
    return 0;
}