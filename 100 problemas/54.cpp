#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    s = 'a' + s;
    int n = s.size();
    vector<int> Suma(n, 0);
    for(int i = 1; i < n; i++){
        Suma[i] = s[i] == 't';
        Suma[i] += Suma[i - 1];
    }
    long double Mayor = -0;
    for(int i = 1; i < n; i++){
        for(int j = i + 2; j < n; j++){
            if(s[i] == s[j] and s[i] == 't'){
                Mayor = max(Mayor, ((long double)Suma[j - 1] - (long double)Suma[i]) /((long double)j - (long double)i - (long double)1));
            }
        }
    }
    cout<<setprecision(22)<<Mayor;
    return 0;
}