#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define el "\n"
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n = int(s.size());
    set<string> Palabras, Buscar;
    Buscar.insert("AGASA");
    Buscar.insert("EGASE");
    Buscar.insert("IGASI");
    Buscar.insert("OGASO");
    Buscar.insert("UGASU");
    forn(i, n - 4){
        auto E = Buscar.find(s.substr(i, 5));
        if(E == Buscar.end()) continue;
        string r = "";
        forn(j, n){
            if(j < i or j > i + 4) r += s[j];
            if(j == i) r += (*E)[0];
        }
        Palabras.insert(r);
    }
    if(int(Palabras.size()) == 1) cout<<*Palabras.begin()<<el;
    else if(Palabras.empty()) cout<<"-\n";
    else cout<<"+\n";
    return 0;
}