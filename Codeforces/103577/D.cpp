#include "bits/stdc++.h"
#define vi vector<int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp make_pair
#define ii pair<int, int>
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define el "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, r = "";
    cin>>s;
    map<ll, ll> Polinomio;
    forn(i, s.size()){
        r += s[i];
        if(r.back() == '+' or (r.back() == '-' and s[i - 1] != '^') or i == int(s.size()) - 1){
            if(i != int(s.size()) - 1) r.pop_back();
            ll Coeficiente = 0LL, Exponente = 0LL;
            bool C = 1, cn = 0, en = 0, e1 = 0, c1 = 0;
            for(auto E: r){
                if(E == '-'){
                    if(C) cn = 1;
                    else en = 1;
                }
                if(C and (E >= '0' and E <= '9')) Coeficiente = Coeficiente * 10LL + (ll)E - 48LL;
                if(!C and (E >= '0' and E <= '9')) Exponente = Exponente * 10LL + (ll)E - 48LL;
                if(C and E == 'x'){
                    C = 0;
                    e1 = 1;
                    c1 = 1;
                }
            }
            r = "";
            if(Exponente == 0LL and e1) Exponente = 1LL;
            if(Coeficiente == 0LL and c1) Coeficiente = 1LL;
            if(cn) Coeficiente /= -1LL;
            if(en) Exponente /= -1LL;
            //cerr<<Coeficiente<<" "<<Exponente<<el;
            Polinomio[Exponente - 1LL] += Coeficiente * Exponente;
            if(s[i] == '-') r += s[i];
        }
    }
    bool Primero = 1;
    for(auto E: Polinomio){
        if(E.second != 0LL){
            if(!Primero and E.second > 0LL) cout<<"+";
            if(Primero) Primero = 0;
            cout<<E.second;
            if(E.first != 0LL and E.first != 1LL) cout<<"x^"<<E.first;
            if(E.first == 1LL) cout<<"x";
        }
    }
    if(Primero) cout<<0;
    cout<<el;
    return 0;
}