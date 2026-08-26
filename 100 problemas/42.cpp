#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s = "";
    cin>>n;
    while(n--){
        char a;
        long long b;
        cin>>a>>b;
        if(b + (long long)s.size() > 100){
            cout<<"Too Long";
            return -0;
        }
        while(b--) s += a;
    }
    cout<<s;
    return 0;
}