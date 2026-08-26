#include "bits/stdc++.h"
using namespace std;
long long m = 1e9 + 7;
vector< vector< vector<long long> > > Memorizaci_n;
long long n, N, M;
string s, t;
long long Suma(long long a, long long b){
    return (a % m + b % m) % m;
}
bool Mismo_tipo(char a, char b){
    if(a >= '0' and a <= '9' and b <= '9' and b >= '0') return 1;
    if(a == b) return 1;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long T;
    cin>>T;
    while(T--){
        cin>>n>>s>>t;
        long long i;
        for(i = n; i > -1 and s[i] != '0'; i--){}
        string Nuevo = "";
        for(i = max(i, 0LL); i <= n; i++) if(s[i] != '1') Nuevo += s[i];
        s = Nuevo;
        for(i = n; i > -1 and t[i] != '0'; i--){}
        Nuevo = "";
        for(i = max(i, 0LL); i <= n; i++) if(t[i] != '1') Nuevo += t[i];
        t = Nuevo;
        N = s.size();
        M = t.size();
        //cout<<s<<" "<<t<<" "<<N<<" "<<M<<" ";
        Memorizaci_n.assign(N + 2, vector< vector<long long> >(M + 2,  vector<long long>(2, 0)));
        if(N == 0 or M == 0){
            cout<<"1\n";
            continue;
        }
        Memorizaci_n[0][0][0] = 1;
        for(long long i = 0; i < N; i++){
            for(long long j = 0; j < M; j++){
                for(long long k = 0; k < 2; k++){
                    if(i == 0 and j == 0){
                        Memorizaci_n[i][j + 1][1] = Suma(Memorizaci_n[i][j][k], Memorizaci_n[i][j + 1][1]);
                        Memorizaci_n[i + 1][j][0] = Suma(Memorizaci_n[i][j][k], Memorizaci_n[i + 1][j][0]);
                        continue;
                    }
                    Memorizaci_n[i][j + 1][1] = Suma(Memorizaci_n[i][j][k], Memorizaci_n[i][j + 1][1]);
                    if(k == 0) Memorizaci_n[i + 1][j][0] = Suma(Memorizaci_n[i][j][0], Memorizaci_n[i + 1][j][0]);
                    else {
                        if(j > 0 and !Mismo_tipo(s[i], t[j - 1])) Memorizaci_n[i + 1][j][0] = Suma(Memorizaci_n[i][j][1], Memorizaci_n[i + 1][j][0]);
                    }
                }
            }
        }
        /*for(auto E: Memorizaci_n){
            for(auto e: E) cout<<e[0]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        for(auto E: Memorizaci_n){
            for(auto e: E) cout<<e[1]<<" ";
            cout<<"\n";
        }
        cout<<"\n";*/
        cout<<Suma(Memorizaci_n[N - 1][M - 1][0], Memorizaci_n[N - 1][M - 1][1])<<"\n";
    }
    return 0;
}