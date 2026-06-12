#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define vi vector<long long>
#define ii pair<long long, long long>
#define el "\n"
#define all(v) (v).begin(), (v).end()
//#define forn(i, n) for(long long i = 0; i < long long(n); i++)
//#define forsn(i, s, n) for(long long i = long long(s); i < long long(n); i++)
using namespace std;
vector< vector<long long> > Divisores;
long long n, m;
vi a;
bool Bien(long long d){
    vector<long long> Contar(m + 1, 0);
    long long i = 0, j = 0, c = 0;
    while(j < n and a[j] - a[i] <= d){
        for(auto E: Divisores[a[j]]){
            if(E <= m){
                Contar[E]++;
                if(Contar[E] == 1) c++;
            }
        }
        j++;
    }
    if(c == m) return 1;
    while(j < n){
        while(i < j and a[j] - a[i] > d){
            for(auto E: Divisores[a[i]]){
                if(E <= m){
                    Contar[E]--;
                    if(Contar[E] == 0) c--;
                }
            }
            i++;
        }
        while(j < n and a[j] - a[i] <= d){
            for(auto E: Divisores[a[j]]){
                if(E <= m){
                    Contar[E]++;
                    if(Contar[E] == 1) c++;
                }
            }
            j++;
        }
        if(c == m) return 1;
    }
    return -0;
}
void Resolver(){
    cin>>n>>m;
    a.assign(n, 0);
    for(long long i = 0; i < n; i++) cin>>a[i];
    sort(all(a));
    long long i = 0, d = 1e5 + 22, M = 1e5 + 22;
    while(1){
        long long p = (i + d) / 2;
        if(Bien(p)){
            d = p - 1;
            M = p;
        } else {
            i = p + 1;
        }
        if(i >= d + 1) break;
    }
    cout<<(M != 1e5 + 22 ? M : -1)<<el;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N = 1e5 + 22;
    vi Criba(N, 1);
    for(long long i = 2; i < N; i++){
        //cerr<<i<<" ";
        if(Criba[i] == 1){
            Criba[i] = i;
            for(long long j = i * i; j < N; j += i){
                Criba[j] = i;
            }
        }
    }
    //cerr<<"Criba."<<el;
    /*for(auto E: Criba) cerr<<E<<" ";
    cerr<<"\n";*/
    Divisores.assign(N, {});
    for(long long i = 2; i < N; i++){
        //cerr<<i<<" ";
        map<long long, long long> c;
        set<long long> Primos;
        long long ci = i;
        while(ci > 1){
            c[Criba[ci]]++;
            Primos.insert(Criba[ci]);
            ci /= Criba[ci];
        }
        vector<long long> Factores, Potencia(c.size(), 0);
        for(auto E: Primos) Factores.push_back(E);
        bool Seguir = 1;
        //cerr<<el<<i<<el;
        while(Seguir){
            long long v = 1;
            for(long long j = 0; j < c.size(); j++){
                for(long long k = 0; k < Potencia[j]; k++){
                    v *= Factores[j];
                }
            }
            //cerr<<v<<" ";
            Divisores[i].push_back(v);
            for(long long j = 0; j < c.size(); j++){
                Potencia[j]++;
                if(Potencia[j] - 1 == c[Factores[j]]){
                    Potencia[j] = 0;
                    if(j == c.size() - 1){
                        Seguir = 0;
                        break;
                    }
                } else break;
            }
        }
        //cerr<<"\n";
    }
    Divisores[1].push_back(1);
    /*for(long long i = 1; i < 12; i++){
        cerr<<i<<"\n";
        for(auto E: Divisores[i]) cerr<<E<<" ";
        cerr<<"\n";
    }*/
    long long t;
    cin>>t;
    while(t--) Resolver();
    return 0;
}