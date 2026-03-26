#include <vector>
#include <iostream>
#include <climits>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forn(i, n) for(int i = 0; i< int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i< int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define el "\n"
#define pb push_back
#define mp make_pair
using namespace std;
const int MAXN = 1e6 + 1;
int arr[MAXN] = {};
unordered_map<int, int> max_pos = {};
int main(){
    FastIO;
    int n;
    cin>>n;
    string s;
    cin>>s;
    arr[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        arr[i] = arr[i + 1] ^ (1<<(s[i] - 'a'));
    }
    forn(i, s.size() + 1){
        max_pos[arr[i]] = i;
    }
    int res = 0;
    forn(i, s.size()){
        res = max(res, max_pos[arr[i]] - i);
        forn(j, 27){
            res = max(res, max_pos[arr[i] ^ (1<<j)] - i);
        }
    }
    cout<<res<<el;
}