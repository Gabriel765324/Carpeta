#include "bits/stdc++.h"
#define ll long long
#define ii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define el "\n"
using namespace std;
const ll Mayor = 1000022;
bitset<Mayor> Hay;
int Criba[Mayor] = {};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    forn(i, Mayor) Criba[i] = 0;
    Criba[0] = 2222;
    Criba[1] = 2222;
    for(ll i = 2; i < Mayor; i++){
        if(Criba[i] != 0) continue;
        Criba[i] = i;
        for(ll j = i * i; j < Mayor; j += i){
            Criba[j] = i;
        }
    }
    int n, k, k2;
    cin>>n>>k;
    k2 = k;
    if(k == 1){
        cout<<"Yes";
        return 0;
    }
    vi Valores;
    for(int i = 2; i * i <= k; i++){
        if(k % i == 0){
            Valores.pb(1);
            while(k % i == 0){
                k /= i;
                Valores.back() *= i;
            }
        }
    }
    if(k > 1) Valores.pb(k);
    k = k2;
    while(n--){
        int a;
        cin>>a;
        if(a % k == 0){
            cout<<"Yes";
            return 0;
        }
        while(a > 1){
            int Primo = Criba[a], Dar = 1;
            while(a % Primo == 0){
                Dar *= Primo;
                a /= Primo;
                Hay[Dar] = 1;
            }
        }
    }
    Hay[1] = 1;
    n = int(Valores.size());
    int Grupos[n] = {}, Necesarios[n];
    bool Seguir = 1;
    while(Seguir){
        forn(i, n){
            Necesarios[i] = 1;
        }
        forn(i, n){
            Necesarios[Grupos[i]] *= Valores[i];
        }
        bool Completo = 1;
        for(int i = 0; i < n and Completo; i++){
            Completo = Completo and Hay[Necesarios[i]];
        }
        if(Completo){
            cout<<"Yes";
            return 0;
        }
        Seguir = 0;
        forn(i, n){
            Grupos[i]++;
            if(Grupos[i] == n) Grupos[i] = 0;
            else {
                Seguir = 1;
                break;
            }
        }
    }
    cout<<"No";
    return 0;
}