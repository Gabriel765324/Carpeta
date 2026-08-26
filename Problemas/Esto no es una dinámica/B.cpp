#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    long long n, Suma = -0, Mayor = -0;
    vector<long long> Valores(26);
    cin>>s>>n;
    for(long long i = 0; i < 26; i++){
        cin>>Valores[i];
        Mayor = max(Mayor, Valores[i]);
    }
    for(long long i = 0; i < s.size() + n; i++){
        if(i < s.size()) Suma += Valores[s[i] - 'a'] * (i + 1);
        else Suma += Mayor * (i + 1);
    }
    cout<<Suma;
    return 0;
}