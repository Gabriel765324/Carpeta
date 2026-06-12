#include "bits/stdc++.h"
#define el "\n"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ii pair<int, int>
#define vi vector<int>
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define ll long long
using namespace std;
void Resolver(){
    int l, r;
    cin>>l>>r;
    int y = r - (r % 2), x = y / 2;
    if(x >= l) cout<<x<<" "<<y<<el;
    else cout<<"-1 -1\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}