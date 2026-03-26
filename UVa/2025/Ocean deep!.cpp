#include "bits/stdc++.h"
using namespace std;
long long Sumar(long long a, long long b, long long m){
    return (a % m + b % m) % m;
}
long long Multiplicar(long long a, long long b, long long m){
    return (a % m * b % m) % m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "";
    string c;
    while(cin>>c){
        s += c;
        if(c.back() == '#'){
            long long n = 0, m = 131071, e = 1;
            for(long long i = s.size() - 2; i > -1; i--){
                if(s[i] == '1') n = Sumar(n, e, m);
                e = Multiplicar(e, 2, m);
            }
            if(n == 0) cout<<"YES\n";
            else cout<<"NO\n";
            s = "";
        }
    }
    return 0;
}