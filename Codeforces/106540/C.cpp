#include "bits/stdc++.h"
using namespace std;
long long m = 1e9 + 7;
long long Potencia(long long b, long long e){
    if(e == 0LL) return 1LL;
    if(e == 1LL) return b % m;
    long long a = Potencia(b, e / 2LL);
    a = (a % m * a % m) % m;
    a = (a % m * Potencia(b, e & 1LL)) % m;
    return a % m;
}
struct M_dulo{
    long long v;
    M_dulo(int a){
        v = ((long long)a % m + m) % m;
    }
    M_dulo(long long a){
        v = (a % m + m) % m;
    }
    M_dulo operator+(const M_dulo& a){
        return M_dulo(v % m + a.v % m);
    }
    M_dulo operator-(const M_dulo& a){
        return M_dulo(v % m - a.v % m);
    }
    M_dulo operator-(const int& a){
        return M_dulo(v % m - a % m);
    }
    M_dulo operator*(const M_dulo& a){
        return M_dulo(v % m * a.v % m);
    }
    M_dulo operator/(const M_dulo& a){
        return M_dulo(v % m * Potencia(a.v % m, m - 2LL) % m);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    /*vector<M_dulo> H(1, M_dulo(0));
    for(int i = 1; i <= 1000022; i++){
        H.push_back(H.back() + (M_dulo(1) / M_dulo(i)));
    }*/
    vector<M_dulo> a;
    for(int i = 0; i <= 1000022; i++){
        a.push_back(M_dulo((i - 1) / 2));
        if(i > 0) a.back() = a.back() + a[i - 1];
    }
    int t;
    cin>>t;
    M_dulo p = M_dulo(1);
    while(t--){
        int N;
        cin>>N;
        M_dulo n = M_dulo(N);
        p = p * (M_dulo(6) / (n * (n - 1) * (n - 2)) * a[N]).v;
        cout<<p.v<<"\n";
        //M_dulo x = M_dulo((N + 2) / 2);
        //cout<<(M_dulo(6) * ((n - x) * n + (n - M_dulo(1)) * n / M_dulo(2) - x - M_dulo(2)  - M_dulo(1)) / (n * (n - M_dulo(1) * (n - M_dulo(2))))).v<<"\n";
    }
    return 0;
}