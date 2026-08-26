#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <cmath>

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

const int MAXI = 19;
vector<ii> adj[MAXI][MAXI] = {};
int color[MAXI][MAXI] = {};
bool vis[MAXI][MAXI] = {};
int arr[MAXI*MAXI] = {};

int dfs(int i, int j){
    if(vis[i][j] || color[i][j] == -1) return 0;
    vis[i][j] = true;
    int res = 1;
    for(auto& v: adj[i][j]){
        if(vis[v.F][v.S] || color[i][j] != color[v.F][v.S]) continue;
        res += dfs(v.F, v.S);
    }
    return res;
}

int solve(int ptr, int k, int L, int R){
    if(k == -1){
        forn(i, MAXI) forn(j, MAXI - i) vis[i][j] = false;
        int res = 0;
        forn(i, MAXI){
            forn(j, MAXI - i){
                if(vis[i][j]) continue;
                res = max(res, dfs(i, j));
            }
        }
        return res;
    }
    
    int rptr = ptr;
    for(int i = k; i >= 0; i--){
        color[i][R - i] = arr[rptr];
        rptr--;
    }
    int res = solve(rptr, k-1, L, R-1);

    int lptr = ptr;
    for(int i = k; i >= 0; i--){
        color[i][L] = arr[lptr];
        lptr--;
    }
    res = max(res, solve(lptr, k-1, L+1, R));
    return res;
}

int main(){
    int n; cin >> n;
    forn(i, n) cin >> arr[i];

    forn(i, MAXI) forn(j, MAXI - i) color[i][j] = -1;

    int x = floor((sqrt(1 + 8*n) - 1)/2);

    forn(i, x + 1){
        forn(j, x + 1 - i){
            adj[i][j].pb({i, j+1});
            adj[i][j+1].pb({i, j});
            if(i > 0){
                adj[i][j].pb({i-1, j});
                adj[i-1][j].pb({i, j});
                adj[i][j].pb({i-1, j+1});
                adj[i-1][j+1].pb({i, j});
            }
        }
    }

    int remaining = n - (x*(x+1)/2); int ptr = n-1;
    for(int i = remaining-1; i >= 0; i--){
        color[i][x - i] = arr[ptr];
        ptr--;
    }

    cout << solve(ptr, x-1, 0, x-1) << el;
}