#include "bits/stdc++.h"
using namespace std;
struct Punto{
    long double x, y;
    Punto(long double X, long double Y){
        x = X;
        y = Y;
    }
    long double Distancia(const Punto& a){
        return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
    }
};
void Resolver(){
    long double x, y, r, u, v, s, d;
    long long X, Y, R, U, V, S, D;
    cin>>X>>Y>>R>>U>>V>>S>>D;
    if((X - U) * (X - U) + (Y - V) * (Y - V) > (R + S) * (R + S)){
        cout<<(max(2LL * R, 2LL * S) >= D ? "YES" : "NO")<<"\n";
        return;
    }
    x = X;
    y = Y;
    r = R;
    u = U;
    v = V;
    s = S;
    d = D;
    Punto a = Punto(x, y);
    Punto b = Punto(u, v);
    if(r >= s + a.Distancia(b)){
        cout<<(max(2LL * R, 2LL * S) >= D ? "YES" : "NO")<<"\n";
        return;
    }
    cout<<(r + s + a.Distancia(b) >= d ? "YES" : "NO")<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}