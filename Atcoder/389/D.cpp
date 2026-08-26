#include "bits/stdc++.h"
using namespace std;
long long f(double x, double r){
    r *= r;
    double y1 = sqrt(r - (x - 0.5) * (x - 0.5)) + 0.5, y2 = sqrt(r - (x + 0.5) * (x + 0.5)) + 0.5;
    //cout<<x<<" "<<y1<<" "<<x + 1<<" "<<y2<<" "<<r<<"\n";
    return min(y1, y2);
}
long long Contiene(double x, double r){
    r *= r;
    double y1 = sqrt(r - (x - 0.5) * (x - 0.5)) + 0.5, y2 = sqrt(r - (x + 0.5) * (x + 0.5)) + 0.5;
    //cout<<x<<" "<<y1<<" "<<x + 1<<" "<<y2<<" "<<r<<"\n";
    return (long long)(min(y1, y2) >= 1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double r;
    long long c = 0;
    cin>>r;
    for(double i = -r + 1; i + 1 <= r + 0.0000000000000001; i++){
        c += f(i, r);
    }
    c *= 2;
    for(double i = -r + 1; i + 1 <= r + 0.0000000000000001; i++){
        c -= Contiene(i, r);
    }
    cout<<c;
    return 0;
}