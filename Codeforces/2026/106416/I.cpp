#include "bits/stdc++.h"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define vi vector<int>
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define el '\n'
using namespace std;
int main(){
    FastIO;
    int n, Contador = 0;
    cin>>n;
    bool Par = 1;
    vi Baldes(n + 1, 0);
    forn(i, n){
        int a;
        cin>>a;
        Baldes[a]++;
        if(Baldes[a] == 1) Contador++;
    }
    forn(i, n + 1){
        if(Baldes[i] % 2 == 1) Par = !Par;
    }
    if(Contador == 1){
        cout<<"E\n";
        return 0;
    }
    if(Par) cout<<"F\n";
    else cout<<"S\n";
    return 0;
}