#include "bits/stdc++.h"
using namespace std;
struct Punto{
    long double x, y;
};
long double d(Punto a, Punto b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Punto> a(n);
    for(int i = 0; i < n; i++) cin>>a[i].x>>a[i].y;
    long double r = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            r = max(r, d(a[i], a[j]));
        }
    }
    cout<<setprecision(22)<<r;
    return 0;
}