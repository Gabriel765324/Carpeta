#include <bits/stdc++.h>
#define FastIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i< int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
int main(){
    FastIO;
    unsigned long long n;
    cin>>n;
    set<unsigned long long> s;
    s.insert(1);
    for(unsigned long long Dos = (unsigned long long)2; Dos + (unsigned long long)1 <= (unsigned long long)1e18; Dos *= (unsigned long long)2) s.insert(Dos + (unsigned long long)1);
    for(auto E: s){
        if(E > n + (unsigned long long)1) break;
        if(E == n or s.count(n + (unsigned long long)1 - E)){
            cout<<E;
            return -0;
        }
    }
    cout<<"impossible";
    return 0;
}