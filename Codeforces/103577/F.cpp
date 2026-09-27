#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp make_pair
#define ii pair<int, int>
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ll long long
#define ld long double
#define di deque<int>
#define vi vector<int>
#define pf push_front
#define pb push_back
#define el "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, c = 0;
    cin>>n>>q;
    deque< di > m(n, di(n, 0));
    di Buenos_c(n, 0), Buenos_f(n, 0);
    forn(i, n){
        string s;
        cin>>s;
        forn(j, n){
            m[i][j] = s[j] - '0';
            Buenos_f[i] += m[i][j];
            Buenos_c[j] += m[i][j];
            if(Buenos_f[i] == n) c++;
            if(Buenos_c[j] == n) c++;
        }
    }
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int i, j, b;
            cin>>i>>j>>b;
            i--;
            j--;
            if(m[i][j] == b){
                cout<<c<<el;
                continue;
            }
            if(b == 0){
                if(Buenos_f[i] == n) c--;
                if(Buenos_c[j] == n) c--;
                Buenos_f[i]--;
                Buenos_c[j]--;
            } else {
                Buenos_f[i]++;
                Buenos_c[j]++;
                if(Buenos_f[i] == n) c++;
                if(Buenos_c[j] == n) c++;
            }
            m[i][j] = b;
        } else {
            int b;
            cin>>b;
            if(Buenos_c.back() == n) c--;
            Buenos_c.pf(Buenos_c.back() - m[n - 1][n - 1] + b);
            Buenos_c.pop_back();
            if(Buenos_c[0] == n) c++;
            forn(i, n){
                if(Buenos_f[i] == n) c--;
                Buenos_f[i] -= m[i][n - 1];
            }
            forn(i, n){
                Buenos_f[i] += b;
                if(Buenos_f[i] == n) c++;
                m[i].pf(b);
                b = m[i].back();
                m[i].pop_back();
            }
        }
        cout<<c<<el;
    }
    return 0;
}