#include "bits/stdc++.h"
using namespace std;
string XOR(string a, string b){
    string r;
    if(b.size() > a.size()) swap(a, b);
    long long i;
    for(i = 0; i < a.size() - b.size(); i++){
        r += a[i];
    }
    for(long long j = 0; j < b.size(); j++){
        if(a[i] == b[j]){
            if(r.size() > 0) r += '0';
        } else r += '1';
        i++;
    }
    if(r.size() == 0) r = "0";
    return r;
}
bool Comparar(string a, string b){
    if(a.size() > b.size()) return 1;
    if(b.size() > a.size()) return 0;
    for(long long i = 0; i < a.size(); i++){
        if(a[i] == '1' and b[i] == '0') return 1;
        if(a[i] == '0' and b[i] == '1') return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        string s, Mejor = "0";
        cin>>s;
        long long n = s.size();
        long long l1 = 1, l2, r1 = n, r2;
        /*for(long long i = 0; i < n; i++){
            for(long long j = 1; i + j - 1 < n; j++){

            }
        }*/
        long long D_gitos = -2;
        for(long long i = 0; i < n; i++){
            if(s[i] == '0'){
                D_gitos = n - i;
                break;
            }
        }
        //cout<<D_gitos<<"\n";
        if(D_gitos == -2) cout<<l1<<" "<<r1<<" "<<r1<<" "<<r1<<"\n";
        else {
            for(long long i = 0; i <= n - D_gitos; i++){
                if(s[i] == '0') continue;
                string Actual = s.substr(i, D_gitos);
                string So = XOR(Actual, s);
                //cout<<n - D_gitos<<" "<<i<<" "<<s<<" "<<Actual<<" "<<So<<"\n";
                if(Comparar(So, Mejor)){
                    Mejor = So;
                    l2 = i + 1;
                    r2 = i + D_gitos;
                }
            }
            cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";
        }
    }
    return 0;
}