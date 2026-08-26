#include "bits/stdc++.h"
#define forn(i, n) for(unsigned int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(unsigned int i = int(s); i < int(n); i++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<unsigned int, unsigned int>
#define vi vector<unsigned int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define el "\n"
using namespace std;
void Resolver(){
    int n, m, d = 1;
    cin>>n>>m;
    vector<int> a(n);
    forn(i, n){
        cin>>a[i];
    }
    while(1){
        bool Bien = 1;
        int Tengo = m, Punto_bajo = m;
        forn(i, n){
            Tengo -= a[i];
            if(Tengo < 0){
                Bien = 0;
                d = Punto_bajo + 1;
                break;
            }
            if(Tengo < d) Tengo = m;
            Punto_bajo = min(Punto_bajo, Tengo);
        }
        if(Bien){
            cout<<d<<"\n";
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}