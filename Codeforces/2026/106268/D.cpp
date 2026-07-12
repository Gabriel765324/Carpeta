#include "bits/stdc++.h"
using namespace std;
bool Comparar(string& a, string& b){
    if(a.size() > b.size()) return 0;
    if(b.size() > a.size()) return 1;
    int n = int(a.size());
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]) return 0;
        if(a[i] < b[i]) return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, d = 1;
    string r = "";
    cin>>n;
    for(; d < n; d *= 10LL){
        long long cnd = n - d, cd = d;
        string snd, sd;
        stringstream Conversor0, Conversor1, Conversor2;
        Conversor0<<cnd;
        Conversor0>>snd;
        Conversor1<<cd;
        Conversor1>>sd;
        snd += sd;
        if(Comparar(r, snd)) r = snd;
    }
    cout<<r<<"\n";
    return 0;
}