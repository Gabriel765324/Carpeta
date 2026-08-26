#include "bits/stdc++.h"
using namespace std;
void Resolver(){
    int n, q;
    cin>>n>>q;
    vector< vector<long long> > s(1000, vector<long long>(1000, 0));
    while(n--){
        long long a, b;
        cin>>a>>b;
        s[a - 1][b - 1] += a * b;
    }
    for(int i = 1; i < 1000; i++){
        s[i][0] += s[i - 1][0];
        s[0][i] += s[0][i - 1];
    }
    for(int i = 1; i < 1000; i++){
        for(int j = 1; j < 1000; j++){
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    while(q--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        c -= 2;
        d -= 2;
        if(a > c or b > d){
            cout<<"0\n";
            continue;
        }
        long long r = s[c][d];
        a--;
        b--;
        if(a >= 0) r -= s[a][d];
        if(b >= 0) r -= s[c][b];
        if(a >= 0 and b >= 0) r += s[a][b];
        cout<<r<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}