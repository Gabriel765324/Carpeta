#include "bits/stdc++.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double a, b, c, d;
    cin>>a>>b>>c>>d;
    double A = a / b, B = c / d, E = 1 - (1 - A) * B - A;
    cout<<setprecision(22)<<A / (1 - E);
    return 0;
}