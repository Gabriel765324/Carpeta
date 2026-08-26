#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    long long n = s.size();
    long long Cuatro = 0, Siete = 0;
    for(long long i = 0; i < n; i++){
        if(s[i] == '4') Cuatro++;
        if(s[i] == '7') Siete++;
    }
    if(Cuatro == 0 and Siete == 0) cout<<-1;
    else if(Cuatro >= Siete) cout<<4;
    else cout<<7;
    return 0;
}