#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
// #define all(v) (v).begin(), (v).end()
#define vi vector<int>
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define el '\n'

#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

const int MAXI = 2e5 + 1;
const int OFFSET = MAXI;
const int SQRTMAXI = 633;
const int RANGE = 2*(MAXI + OFFSET) + 1;

bitset<RANGE> dp[SQRTMAXI];
bitset<RANGE> sign[SQRTMAXI];
int first[RANGE];

int abso(int x){
    return x > 0? x: -x;
}

void init(){
    forn(i, SQRTMAXI) 
        forn(j, RANGE)
             dp[i][j] = false;
    forn(j, MAXI + OFFSET + 1) first[j] = -1;
    dp[1][1 + OFFSET] = true; first[1+OFFSET] = 1; 
    forsn(i, 2, SQRTMAXI){
        forn(j, RANGE){
            if(dp[i-1][j] == false) continue;
            if(0 <= j + i && j + i < RANGE){
                if(0 <= j + i && j + i < RANGE && first[j + i] == -1) first[j + i] = i;
                dp[i][j + i] = true;
                sign[i][j + i] = true;
            }
            if(0 <= j - i && j - i < RANGE){
                if(0 <= j - i && j - i < RANGE && first[j - i] == -1) first[j - i] = i;
                dp[i][j - i] = true;
                sign[i][j - i] = false;
            } 
        }
    }
}

void solve(){
    int n; cin >> n; n += OFFSET;
    int j = first[n];
    vector<int> res;
    while(j > 0){
        int val = sign[j][n]? j: -j;
        res.pb(val);
        j = j - 1;
        n = n - val;
    }
    reverse(res.begin(), res.end()); 
    cout << res.size() << el;
    for(auto e: res){
        if(e != 1 and e > 0) cout<<"+";
        cout << e;
    }
    cout << el;
}

int main()
{
    FastIO;
    init();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}