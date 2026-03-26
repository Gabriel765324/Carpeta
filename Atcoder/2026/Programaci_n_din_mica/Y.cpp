#include "bits/stdc++.h"
using namespace std;
struct M_dulo{
    long long v, m;
    M_dulo(long long a){
        m = 1000000007;
        v = a % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo((v % m + a.v % m) % m);
    }
    M_dulo operator-(const M_dulo& a){
        return M_dulo(((v % m - a.v % m) % m + m) % m);
    }
    M_dulo operator*(const M_dulo& a){
        return M_dulo((v % m * a.v % m) % m);
    }
    M_dulo operator^(const long long& a){
        if(a == 0) return M_dulo(1);
        if(a == 1) return M_dulo(v);
        M_dulo r = M_dulo(v) ^ (a / 2);
        r = r * r * (M_dulo(v) ^ (a % 2LL));
        return r;
    }
    M_dulo operator/(const M_dulo& a){
        M_dulo b = a;
        return M_dulo((v % m * (b ^ (m - 2LL)).v % m) % m);
    }
    bool operator!=(const M_dulo& a){
        return a.v != v;
    }
};
struct Chau{
    int x, y;
    pair<int, int> Par;
    long long v;
    Chau(int X, int Y, long long V){
        x = X;
        y = Y;
        v = V;
        Par.first = X;
        Par.second = Y;
    }
};
vector<M_dulo> Factorial;
M_dulo nCk(int n, int k){
    return Factorial[n] / (Factorial[n - k] * Factorial[k]);
}
bool Contiene(pair<int, int> a, pair<int, int> b){
    return a.first <= b.first and a.second <= b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Factorial.assign(222222, M_dulo(1));
    for(int i = 2; i < 222222; i++) Factorial[i] = Factorial[i - 1] * M_dulo(i);
    int n, m, k;
    cin>>n>>m>>k;
    M_dulo r = nCk(n + m - 2, m - 1);
    vector< pair<int, int> > Quitables(k);
    vector<Chau> Quitados;
    for(int i = 0; i < k; i++) cin>>Quitables[i].first>>Quitables[i].second;
    while(!Quitables.empty()){
        pair<int, int> Actual = Quitables[0];
        int p = 0;
        for(int i = 1; i < k; i++){
            if(Contiene(Quitables[i], Actual)){
                Actual = Quitables[i];
                p = i;
            }
        }
        //cerr<<Actual.first<<" "<<Actual.second<<"\n";
        Quitables.erase(Quitables.begin() + p);
        Chau Nuevo(Actual.first, Actual.second, nCk(Actual.first + Actual.second - 2, Actual.second - 1).v);
        for(auto E: Quitados){
            if(Contiene(E.Par, Nuevo.Par)){
                Nuevo.v = (M_dulo(Nuevo.v) - M_dulo(E.v) * M_dulo(nCk(Nuevo.x - E.x + Nuevo.y - E.y, Nuevo.x - E.x))).v;
            }
        }
        Quitados.push_back(Nuevo);
        r = r - M_dulo(Quitados.back().v) * M_dulo(nCk(n - Quitados.back().x + m - Quitados.back().y, n - Quitados.back().x));
        k--;
    }
    cout<<r.v;
    return 0;
}