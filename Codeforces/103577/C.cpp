#include "bits/stdc++.h"
#define vi vector<int>
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin>>s){
        int n = int(s.size());
        long long r = 0;
        forn(i, n - 1){
            vi a(n - i, 0);
            forsn(j, 1, n - i){
                int p = a[j - 1];
                while(s[i + j] != s[i + p] and p > 0) p = a[p - 1];
                if(s[i + p] == s[i + j]) p++;
                a[j] = p;
                r += p;
            }
        }
        cout<<r<<el;
    }
    return 0;
}