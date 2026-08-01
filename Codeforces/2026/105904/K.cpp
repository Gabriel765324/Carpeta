#include "bits/stdc++.h"
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define pb push_back
#define pf push_front 
#define mp make_pair
#define F first
#define S second
#define el "\n"
using namespace std;
const ll m = 998244353;
struct Modular{
    ll v;
    Modular(ll a){
        v = a % m;
    }
    Modular(){
        v = 0ll;
    }
    Modular operator+(const Modular &a){
        return Modular(v % m + a.v % m);
    }
    Modular operator-(const Modular &a){
        return Modular((v % m - a.v % m) % m + m);
    }
    Modular operator*(const Modular &a){
        return Modular(v % m * a.v % m);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<Modular> PD(n + 1, Modular(0));
    PD[0] = Modular(1);
    forsn(i, 1, n + 1){
        if(i == k) continue;
        forsn(j, i, n + 1){
            PD[j] = PD[j] + PD[j - i];
        }
    }
    cout<<PD.back().v<<"\n";
    return 0;
}