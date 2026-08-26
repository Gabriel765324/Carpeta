#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define forn(i, n) for(unsigned int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(unsigned int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<unsigned int, unsigned int>
#define vi vector<unsigned int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define el '\n'
using namespace std;

const unsigned int MAXI = 1e6 + 1;
unsigned int arr[MAXI] = {};
unsigned int last[32] = {};

void solve(){
    unsigned int n, m; cin >> n >> m;
    unsigned int or_mask = 0;
    unsigned int and_mask = (1 << 30) - 1;
    
    bool f = true;
    forn(i, n){
        cin >> arr[i];
        or_mask |= arr[i];
        and_mask &= arr[i];
        if(arr[i] != arr[0]) f = false;
    }
    
    if(f == true){
        int q; cin >> q;
        forn(i, q){
            int x; cin >> x;
            cout << 0 << el;
        }
        return;
    }
    
    unsigned int sub_mask = 0;
    forn(i, n){
        sub_mask |= (arr[i] ^ or_mask);
    }
    
    // cout << "mask: " << mask << el;
    
    unsigned int c = 0;
    for(unsigned int i = 0; i < n; ){
        if(arr[i] == or_mask){
            i++;
        }
        else{
            i += m;
            c++;
        }
    }
    
    unsigned int q; cin >> q;
    forn(i, q){
        unsigned int x; cin >> x; 
        // cout << "q: " << x << " " << and_mask << " " << (~and_mask) <<el;
        x = x & (~and_mask);
        // cout << x << el;
        if(x == sub_mask){
            cout << c << el;
        }
        else if((x & sub_mask) == sub_mask){
            cout << (n + m - 1)/m << el;
        }
        else{
            cout << -1 << el;
        }
    }
}

int main(){
    FastIO;
    unsigned int t; cin >> t;
    while(t--) solve();
}