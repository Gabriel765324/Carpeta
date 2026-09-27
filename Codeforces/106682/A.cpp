#include "bits/stdc++.h"
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, m, s, t;
    cin>>h>>m>>s;
    t = h * 3600 + m * 60 + s;
    if(t > 3600 * 2 + 30 * 60) cout<<"+\n";
    else if(t == 3600 * 2 + 30 * 60) cout<<"=\n";
    else cout<<"-\n";
    return 0;
}