#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>

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
    int n; cin >> n;
    vector<int> arr(n, 0);
    priority_queue<ii, vector<ii>, greater<ii>> in_line;
    forn(i, n){
        cin >> arr[i];
        in_line.push({arr[i], i});
    }

    vector<ii> res;
    forn(i, n){
        while(!in_line.empty()){
            while(!in_line.empty() && in_line.top().S <= i){
                in_line.pop();
            }
            if(in_line.empty()) break;
            auto curr = in_line.top();
            if(arr[i] <= curr.F) break;
            int new_left = (arr[i] + arr[curr.S])/2;
            int new_right = (arr[i] + arr[curr.S] + 1)/2;
            in_line.pop();
            arr[i] = new_left;
            arr[curr.S] = new_right;
            in_line.push({new_right, curr.S});
            res.pb({i, curr.S});
        }
    }

    cout << res.size() << el;
    for(auto e: res){
        cout << e.F + 1 << " " << e.S + 1 << el;
    }
}