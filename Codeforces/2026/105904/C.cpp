#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define pb push_back
#define pf push_front 
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int x, y;
        cin>>x>>y;
        if(x < -200 or x > 200){
            cout<<"N\n";
            continue;
        }
        if(-200 <= x and x <= -100){
            if(y >= 0 and y <= x + 200){
                cout<<"S\n";
            } else {
                cout<<"N\n";
            }
        } else if(-100 <= x and x <= 0){
            if(y <= 100 and y >= -x - 100){
                cout<<"S\n";
            } else {
                cout<<"N\n";
            }
        } else if(0 <= x and x <= 100){
            if(y >= -100 and y <= 100 - x){
                cout<<"S\n";
            } else {
                cout<<"N\n";
            }
        } else if(100 <= x and x <= 200){
            if(y <= 0 and y >= x - 200){
                cout<<"S\n";
            } else {
                cout<<"N\n";
            }
        }
    }
    return 0;
}