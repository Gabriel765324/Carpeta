#include "bits/stdc++.h"
#define el "\n"
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define ll long long
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define ii pair<int, int>
#define all(v) (v).begin(), (v).end()
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long t;
    cin>>n>>t;
    vector<long long> a(n + 1);
    cin>>a[0];
    forsn(i, 1, n){
        cin>>a[i];
        a[i] += a[i - 1];
    }
    a.back() = 2222222222222222;
    int r = 0;
    long long Resta = 0;
    forn(i, n){
        int I = i, D = n, M = n;
        while(I < D + 1){
            int P = (I + D) / 2;
            if(a[P] - Resta > t){
                M = P;
                D = P - 1;
            } else {
                I = P + 1;
            }
        }
        r = max(M - i, r);
        Resta = a[i];
    }
    cout<<r;
    return 0;
}