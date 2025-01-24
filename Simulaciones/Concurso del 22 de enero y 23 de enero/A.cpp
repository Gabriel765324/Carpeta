#include "bits/stdc++.h"
using namespace std;
vector< vector<long long> > Memorizaci_n;
string s;
long long n;
long long Resolver(long long i, long long Racha){
    if(i >= n) return 0;
    if(Racha < 0 or Racha > 2) return -2222222222222222; //Mejor prevenir que lamentar.
    if(Memorizaci_n[i][Racha] != -2) return Memorizaci_n[i][Racha];
    switch(s[i]){
        case 'W':
        if(Racha == 2){
            return Memorizaci_n[i][Racha] = max(3 + Resolver(i + 1, Racha), Resolver(i + 1, 0));
        } else {
            return Memorizaci_n[i][Racha] = max(2 + Resolver(i + 1, Racha + 1), Resolver(i + 1, 0));
        }
        break;
        case 'D':
        return Memorizaci_n[i][Racha] = max(1 + Resolver(i + 1, 0), Resolver(i + 1, Racha));
        break;
        case 'L':
        return Memorizaci_n[i][Racha] = max(Resolver(i + 1, Racha), Resolver(i + 1, 0));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    n = s.size();
    Memorizaci_n.assign(n, vector<long long>(3, -2));
    cout<<Resolver(0, 0);
    return 0;
}