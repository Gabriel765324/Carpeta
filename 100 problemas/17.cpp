#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<<((c < a or (a == c and d <= b)) ? "Yes" : "No");
    return 0;
}