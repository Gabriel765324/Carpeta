#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, Menor = 222 * 222;
    cin>>n;
    vector<string> s(n), t(n);
    for(int i = 0; i < n; i++) cin>>s[i];
    for(int i = 0; i < n; i++) cin>>t[i];
    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c += s[i][j] != t[i][j];
            cerr<<s[i][j];
        }
        cerr<<"\n";
    }
    cerr<<"\n";
    Menor = min(Menor, c);
    c = 1;
    for(int j = 0, ii = 0; j < n; j++){
        for(int i = n - 1, jj = 0; i > -1; i--){
            c += s[i][j] != t[ii][jj];
            cerr<<s[i][j];
            jj++;
        }
        cerr<<"\n";
        ii++;
    }
    cerr<<"\n";
    Menor = min(Menor, c);
    c = 2;
    for(int i = n - 1, ii = 0; i > -1; i--){
        for(int j = n - 1, jj = 0; j > -1; j--){
            c += s[i][j] != t[ii][jj];
            cerr<<s[i][j];
            jj++;
        }
        cerr<<"\n";
        ii++;
    }
    cerr<<"\n";
    Menor = min(Menor, c);
    c = 3;
    for(int j = n - 1, ii = 0; j > -1; j--){
        for(int i = 0, jj = 0; i < n; i++){
            c += s[i][j] != t[ii][jj];
            cerr<<s[i][j];
            jj++;
        }
        cerr<<"\n";
        ii++;
    }
    cerr<<"\n";
    Menor = min(Menor, c);
    cout<<Menor;
    return 0;
}