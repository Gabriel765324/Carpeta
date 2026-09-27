#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define el "\n"
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    set<string> Borrable;
    string Borrando = "APT";
    do{
        Borrable.insert(Borrando);
    } while(next_permutation(all(Borrando)));
    while(!s.empty()){
        bool Mal = 1;
        forn(i, s.size() - 2){
            if(Borrable.find(s.substr(i, 3)) != Borrable.end()){
                Mal = 0;
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                break;
            }
        }
        if(Mal){
            cout<<"N\n";
            return 0;
        }
    }
    cout<<"S\n";
    return 0;
}