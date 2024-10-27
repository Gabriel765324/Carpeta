#include "bits/stdc++.h"
using namespace std;
long long c;
vector<long long> r;
long long Buscar(long long a){
    //cout<<a<<" ";
    if(r[a] == a){
        //cout<<"\n";
        return a;
    } else return r[a] = Buscar(r[a]);
}
void Unir(long long A, long long B){
    if(A == B) return;
    long long a = Buscar(A), b = Buscar(B);
    if(a != b){
        c--;
        r[a] = b;
        //cout<<":(\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    c = n;
    r.assign(n, 0);
    map< char, set<long long> > Mapa;
    for(long long i = 0; i < n; i++){
        string s;
        cin>>s;
        r[i] = i;
        for(long long j = 0; j < s.size(); j++){
            Mapa[s[j]].insert(i);
        }
    }
    for(long long i = 'a'; i <= 'z'; i++){
        set<long long> zd = Mapa[i];
        long long p = *zd.begin();
        //cout<<(char)i<<" ";
        for(auto E: zd){
            Unir(E, p);
            //cout<<(char)i<<" "<<p<<" "<<E<<"\n";
            //cout<<E<<" ";
        }
        //cout<<"\n";
    }
    cout<<c;
    return 0;
}